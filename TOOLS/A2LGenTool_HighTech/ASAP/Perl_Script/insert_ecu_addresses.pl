################################################################################
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#                                                                              #
#     author: Dm                                                               #
#     date: 14.06.2011                                                         #
#     Version 1.0.7                                                            #
#                                                                              #
#     V1.0 Created Dm 04/2005                                                  #
#                                                                              #
#     V1.0.1 Some minor enhancements                                           #
#     V1.0.2 Added support for Tasking C16x / Renesas 32R /                    #
#            Greenhills NECV850 / Renesas SH70xx / Tasking Tricore             #
#     V1.0.3 Corrected Size Detection error for Renesas 32R /                  #
#            Tasking Tricore / M32R                                            #
#     V1.0.4                                                                   #
#     V1.0.5 Added Tasking VX 2x for C16x                                      #
#     V1.0.6 Added Freescale Codewarrior Map for MPC5xxx                       #
#     V1.0.7 Added Greenhills map for MPC5xxx                                  #
#                                                                              #
#                                                                              #
################################################################################

################################################################################
#                                                                              #
# this perl script inserts the address/size Information of                     #
# ECU code elements into new .a2l template files                               #
#                                                                              #
# Supported Patterns for Linker MAP files:                                     #
# Please note that this is only tested for the listed Version:                 #
# Maptype:    Compiler/linker Toolchain                                        #
# DIAB4       Diab Data 4.3G / Diab 4.4B for MPC5xx                            #
# DIAB5       Diab Data 5.2.1.0 for MPC55xx                                    #
# TASK_C16x   Tasking 7.x Map for C16x  (Only Address Supported)               #
# REN_M32R    Renesas CC32RV42 toolchain for M32R                              #
# GREEN_V850  Greenhills V850 Toolchain / ELXR 4.0                             #
# REN_SH70xx  Renesas SH70xx toolchain for SH70xx  (Only Address Supported)    #
# TASK_TRIC   Tasking Tricore V2.1 toolchain (Only Address Supported)          #
# VX_C16x     Tasking VX V2.x Map for C16x  (Only Address Supported)           #
# FRSC_CW_MPC5xxx  Freescale Codewarrior Map for MPC5xxx                       #
# GHS_MPC5xxx  Freescale Codewarrior Map for MPC5xxx                           #
# HIGHTEC_TC27X Hightec Compiler for IFX TC27x                                 # 
#                                                                              #
#                                                                              #
# List of Arguments:                                                           #
# 1st : Mapfilename (Either in Working-Directory/oder with Path)               #
# 2nd : Source path for IF_DATA Templatefiles                                  #
#       (Sources will not be overwritten)                                      #
# 3rd : MAP type (Info for different map file types                            #
#       which are possible / Tested ...see above)                              #
#                                                                              #
# 4th : First IF_Data Template file                                            #
# [5th...] : Further IF_Data Template files                                    #
#                                                                              #
#                                                                              #
# The generated Output files will have the same filenames as the               #
# inputfiles except for the Source Path and are written                        #
# in the working Directory                                                     #
#                                                                              #
################################################################################
use strict;

my $thisScript = "insert_ECU_Addresses.pl";
print "\n\nStarting script $thisScript!\n";
# redirect STDERR to STDOUT so that the "die" messages appear in the .log file
open(STDERR, ">&STDOUT"); 

######################################################
# Enable= 1/ Disable=0 enhanced Debug Output  
my $DODEBUG_OUT = 0;
######################################################
# get Basic Arguments from Commandline 
# Note that further commandline Arguments will be 
# covered in loop later
######################################################

my $map_file = $ARGV[0];
my $Source_path=$ARGV[1];
my $MAP_Type=$ARGV[2];
my $Start_Argument_ASAP_files = 3;
my $Input_filename = ""; 
my $Output_filename = ""; 
my $maxnumfiles = $#ARGV; # get highest Index of array

######################################################
# List of available MAP-FileType / Relation 2 Regular Expressions
######################################################

my %Supported_MAP_Types = (
    "HIGHTEC_TC27X"  => "Hightec map for infineon TC27X",
	"ARM_TMS570"	=>	"Map format for TMS570",
	"Power_MPC574"	=>	"Map format for MPC574"	#diab compiler
    );
    
my %MAP_Pattern_Type =(
    "HIGHTEC_TC27X"   => "Format10_HIGHTEC_TC27x",
	"ARM_TMS570"	=> "Format_ARM_TMS570",
	"Power_MPC574"	=> "Format_Power_MPC574"
    );

my %REG_EXP_Patterns =(
	"Format10_HIGHTEC_TC27x" 	=> "^0x([0-9a-fA-F]{8})[\\s]+?0x[0-9a-fA-F]{8}\\s+?([0-9]{1,5})[\\s]+?[g][\\s]+([a-zA-Z0-9]{1,}\\w+)",
	"Format_ARM_TMS570" 		=> "^([0-9a-fA-F]{8})[\\s]+([sa-zA-Z0-9]{1,}\\w+)",
	"Format_Power_MPC574" 		=> "[\\s]+([a-zA-Z0-9]{1,}\\w+)\\s+([0-9a-fA-F]{8})\\s+[0-9a-fA-F]{1,}" #name of var with only alphanumberic and "_"
);	


# Format of MPC 
# test_calib 08f90000	00000028
# Format10_HIGHTEC_TC27x
# 0x80064ce0 0x80064cf7      24 g ASW0_InfoTable
# Rte_Self_SWCI10       g 0x800470d0 0x800470d3      4 ASW0_Flash

   
my $REG_EXP_Use = "";

######################################################
# Data Element which collects the ECU_Elements to search for .......
# Fill that from files to modify
######################################################
my %ElementMatrix = ();

my %Address_List=();
my %Size_List=();


######################################################
# Regular expression definition for Macro replacement
######################################################
my $RegExp_Address        = "<(Address_of):(\\.?[a-zA-Z]\\w*)>";
my $RegExp_Address_Offset = "<(Address_of):(\\.?[a-zA-Z]\\w*);(Offset):(0x)?([0-9a-fA-F]+)>";
my $RegExp_Size           = "<(Size_of):(\\.?[a-zA-Z]\\w*)>";
my $RegExp_Size_Calc      = "<(Size_of):(\\.?[a-zA-Z]\\w*);(Calc):(Distab13|Distab12|Byp_Ret13|Byp_Ret12)>";


&Check_Arguments;

&Read_Template_Files_for_Macro_Detection;

&Read_MAP_File;

&Write_Template_Files_with_Macro_Replacement;





print "\nEnding script $thisScript!\n";
######################################################
# Thats it !
######################################################



######################################################
# Step 0: Check and Debug Arguments for Script
######################################################
sub Check_Arguments
{
  ######################################################
  # Step 0: Debug Output Arguments 
  ######################################################
  if ($DODEBUG_OUT == 1)
  {
    my $numargs;
    print "Start Arguments: \n";
    for ( $numargs = 0; $numargs <= $maxnumfiles ; $numargs++ )
    {
       print "$ARGV[$numargs]\n"; 
    }
    print "Maxnum_files = $maxnumfiles \n";
    print "End Arguments: \n";
  }
  ######################################################
  # Step 0: Check if Search Pattern for MAPfile is available 
  #  and select corresponding pattern
  ######################################################
  print "\n\nStep 0 check the requested MAP file pattern !\n";
  if ( exists($MAP_Pattern_Type{$MAP_Type}))
  {
    if ($DODEBUG_OUT == 1)
    {
       print "Requested MAP format: $Supported_MAP_Types{$MAP_Type} !\n";
       print "Using MAP format: $MAP_Pattern_Type{$MAP_Type} !\n";
    }
    if ( exists ($REG_EXP_Patterns{$MAP_Pattern_Type{$MAP_Type}}))
    {
       $REG_EXP_Use = $REG_EXP_Patterns{$MAP_Pattern_Type{$MAP_Type}};
    }
    else
    {
       die "Requested MAP format: Regular Expression for $MAP_Type not known !\n";
    }
  }
  else
  {
    print "Error Requested MAP format: $MAP_Type not known !\n";
    print "Only the following types are currently supported: \n";

    foreach my $keystr (keys %Supported_MAP_Types)
    {
      print "$Supported_MAP_Types{$keystr} \n";
    }
    die ;
  }
}


######################################################
# Step 1: Check and Debug Arguments for Script
######################################################

sub Read_Template_Files_for_Macro_Detection
{
   # First Step read all input files to get information about needed Elements 
   if ($DODEBUG_OUT == 1)
   {
     print "\n\nStarting Step 1 reading the Input files !\n";
     print "And creating the variable list !\n";
   }

   ######################################################
   # Parse all input files from argument list 
   ######################################################
   for (my $numfiles = $Start_Argument_ASAP_files; $numfiles <= $maxnumfiles ; $numfiles++ )
   {
      $Input_filename = $Source_path.'\\'.$ARGV[$numfiles];
      print "\n\nReading Input file : $Input_filename !\n";
      open(A2L, $Input_filename)||die "$thisScript: Couldn't open $Input_filename: $!"; # open if_data file which will be inserted
      while (<A2L>)  # Read Line of Input File 
      {
        #  Now check if one of the following patterns is included in the line 
        #  <Address_of:Varname>
        #  <Address_of:Varname;
        #  <Size_of:Varname>
        #  <Size_of:Varname;
        while ( s/<Address_of:(\.?[a-zA-Z]\w*)[>;]//    
               || s/<Size_of:(\.?[a-zA-Z]\w*)[>;]//  ) 
        {
           if ($DODEBUG_OUT == 1)
           {
             print "$1\n";
           }
           if ( exists($ElementMatrix{$1}))
           {
             if ($DODEBUG_OUT == 1)
             {
                               print "Dropped: $1 \n";    
             }
           }
           else
           {
             if ($DODEBUG_OUT == 1)
             {
               print "Added to List: $1 \n";
             } 
             $ElementMatrix{$1}="";
           }
        }
      }
      close (A2L)||die "$thisScript: Couldn't close $Input_filename $!";
   }

   if ($DODEBUG_OUT == 1)
   {
     print "\n\nStep 1 Found Elements in Template Files (Request for replace): !\n";
     foreach my $str (keys %ElementMatrix)
     {
       print "$str \n";
     }
     print "\n";
     print "Ending Step 1 reading the Input files !\n";
   }
}

sub Read_MAP_File
{
   open(MAP, $map_file )||die "$thisScript: Couldn't open $map_file: $!"; # open map file which will be inserted

   my %SearchList = %ElementMatrix;
   my $Old_Line= "";
   my $line = "";
   ######################################################
   # Step 2: Parse MAP file to get all Adresses  
   ######################################################
   while (<MAP>)  # Read Line of Input File 
   {
     $Old_Line = $line;
     $line = $_; 
     if ($DODEBUG_OUT == 1)
     {
        #print "\nREADMAP-Line: $line\n";
     }

     #  Now check if one of the map patterns is included in the line 
     while ( s/$REG_EXP_Use// )
     {
        my $varname;
        my $var_Address;
        my $var_Size;
        if ($DODEBUG_OUT == 1)
        {
             print "Pattern found in Line: $line";
             print "Replaced             : $_";
        }
		if ("Format_ARM_TMS570"  eq $MAP_Pattern_Type{$MAP_Type} )
		{
			 ######################################################
			 # Set the variables from the corresponding Search pattern results
			 ######################################################
			 $varname = $2;
			 $var_Address = $1;
			 if ($DODEBUG_OUT == 1)
			 {
				print "Match (HIGHTEC_TC27X) found: Name:$varname  Address:$var_Address  Size:$var_Size  \n\n";
			 }
			 ######################################################
			 # Check if Element is in List to find
			 ######################################################
			 if (exists ($SearchList{$varname}))
			 {
				if ($DODEBUG_OUT == 1)
				{
					print "List: $varname; $var_Address; in Line: $line \n";
				}
				######################################################
				# Delete Element in List to find
				# (Search only for the first matching line)
				# Since for Memory Areas only this one is the one with the correct complete size
				######################################################
				delete $SearchList{$varname};
				$Address_List{$varname}=$var_Address;
				$Size_List{$varname}=$var_Size;
			 }
		}
		elsif ("Format10_HIGHTEC_TC27x"  eq $MAP_Pattern_Type{$MAP_Type} )
		{
			 ######################################################
			 # Set the variables from the corresponding Search pattern results
			 ######################################################
			 $varname = $3;
			 $var_Address = $1;
			 $var_Size = $2;
			 if ($DODEBUG_OUT == 1)
			 {
				print "Match (HIGHTEC_TC27X) found: Name:$varname  Address:$var_Address  Size:$var_Size  \n\n";
			 }
			 ######################################################
			 # Check if Element is in List to find
			 ######################################################
			 if (exists ($SearchList{$varname}))
			 {
				if ($DODEBUG_OUT == 1)
				{
					print "List: $varname; $var_Address; in Line: $line \n";
				}
				######################################################
				# Delete Element in List to find
				# (Search only for the first matching line)
				# Since for Memory Areas only this one is the one with the correct complete size
				######################################################
				delete $SearchList{$varname};
				$Address_List{$varname}=$var_Address;
				$Size_List{$varname}=$var_Size;
			 }
		}
		elsif ("Format_Power_MPC574"  eq $MAP_Pattern_Type{$MAP_Type} )
		{
			 ######################################################
			 # Set the variables from the corresponding Search pattern results
			 ######################################################
			 $varname = $1;
			 $var_Address = $2;
			 $var_Size = $3;
			 if ($DODEBUG_OUT == 1)
			 {
				print "Match (HIGHTEC_TC27X) found: Name:$varname  Address:$var_Address  Size:$var_Size  \n\n";
			 }
			 ######################################################
			 # Check if Element is in List to find
			 ######################################################
			 if (exists ($SearchList{$varname}))
			 {
				if ($DODEBUG_OUT == 1)
				{
					print "List: $varname; $var_Address; in Line: $line \n";
				}
				######################################################
				# Delete Element in List to find
				# (Search only for the first matching line)
				# Since for Memory Areas only this one is the one with the correct complete size
				######################################################
				delete $SearchList{$varname};
				$Address_List{$varname}=$var_Address;
				$Size_List{$varname}=$var_Size;
			 }
		}
		else
		{
			die "Error: This should not happen !!! \nFormat Type not equal in MAP file evaluate -> Missing Code !\n"
		}
     }
   }

   if ($DODEBUG_OUT == 1)
   {
     my @remaining_Keys = keys %SearchList;
     if (0 == scalar (@remaining_Keys) )
     { 
       print "All Elements in Key List have been found in MAP file !\n";
     }
     else
     {
       if ($DODEBUG_OUT == 1)
       {
         print "\n\nStep 2 Elements from List NOT found in map file : !\n";
         foreach my $str (keys %SearchList)
         { 
           print "NOT FOUND: $str \n";
         }
         print "\n";
       }
       else
       {
         print "\n\nStep 2 NOT all Elements from List found in map file : !\n";
       }
     }

     my @read_MAPvars = keys %Address_List;
     if (0 == scalar (@read_MAPvars) )
     {
        die "No variables could be read from the MAP file!\n";
     }

     print "\n\nStep 2 Result: The List of Variables read from mapfile: !\n";
     foreach my $str (keys %Address_List) # %ElementMatrix)
     {
       print "Var:$str Address:$Address_List{$str} Size:$Size_List{$str}\n";
     }
     print "\n";

     print "Ending Step 2 reading the map file !\n";
   }

   close(MAP)||die "$thisScript: Couldn't close $map_file: $!"; # open map file which will be inserted
}


sub Write_Template_Files_with_Macro_Replacement
{
  my $All_Vars = 0;
  my $line = "";

   ######################################################
   # Step 3: Replace in Template Files
   ######################################################

   for (my $numfiles = $Start_Argument_ASAP_files; $numfiles <= $maxnumfiles ; $numfiles++ )
   {
      $All_Vars = 1;
      my $This_Var = 0;
      $Input_filename = $Source_path.'\\'.$ARGV[$numfiles];
      $Output_filename = $ARGV[$numfiles];
      if ($DODEBUG_OUT == 1)
      {
        print "\n\nProcessing Input file: $Input_filename to Output file: $Output_filename !\n";
      }  
      open(IN, $Input_filename)||die "$thisScript: Couldn't open $Input_filename: $!"; # open if_data file which will be inserted
      open(OUT, ">$Output_filename")||die "$thisScript: Couldn't open $Output_filename to write: $!"; # open if_data file which will be inserted
      # print OUT "/* Manipulated file by Insert_ECU_Addresses */\n";
      while (<IN>)  # Read Line of Input File 
      {
        #  Now check if one of the following patterns is included in the line 
        #  <Address_of:Varname>
        #  <Address_of:Varname;
        #  <Size_of:Varname>
        #  <Size_of:Varname;
        #print "ReadLINE: $_\n";
        $line = $_;
        while (   s/$RegExp_Address// 
               || s/$RegExp_Address_Offset// 
               || s/$RegExp_Size//  
               || s/$RegExp_Size_Calc// ) 
        {
           $This_Var = 0;
           ######################################################
           # found 
           # $1 = Address_of / Size_of 
           # $2 = name of variable 
           # $3 = Offset / Calc 
           # $4 = (0x|0X|undef) or Calculation method
           # $5 = Number of Offset or undef 
           ######################################################
           if ($DODEBUG_OUT == 1)
           {
             print "Found: $1: $2: $3: $4: $5 \n";
           }
           ######################################################
           # check if Adress is available for $2 (name) in Adress list 
           # otherwise it was not in map file ....
           ######################################################
           if (!exists $Address_List{$2})
           {
               print "Error: Address_of $2 does not exist in List from MAP !\n";
               $All_Vars = 0;
               next;
           }
           
           ######################################################
           # Replace <Address_of:Varname>
           # check if () $1 = Address_of and  $3 ="" -> No Offset needed and Key $2 exists in Hash $Address_List{$2}
           ######################################################
           if ( ($1 eq "Address_of") && ($3 eq "") ) 
           {
             ######################################################
             # check if Key $2 exists in Hash $Address_List{$2}
             if (exists $Address_List{$2})
             {
               if ($DODEBUG_OUT == 1)
               {
                   print "Handle: Address_of $2= 0x$Address_List{$2}\n";
               }
               $line =~ s/$RegExp_Address/0x$Address_List{$2}/;
               $This_Var = 1;
             }
             else
             {
               print "Error: Address_of $2 does not exist in List from MAP !\n";
               $All_Vars = 0;
             }
           }
           ######################################################
           # Replace <Address_of:Varname;Offset:(0x)?number>
           # check if () $1 = Address_of and  $3 = "Offset" and $5 not undefined
           ######################################################
           if ( ($1 eq "Address_of") && ($3 eq "Offset") && ($5 ne undef) ) 
           {
             ######################################################
             # check if Key $2 exists in Hash $Address_List{$2}
             if (exists $Address_List{$2})
             {
               my $Zahl = 0;
               my $HexAddress = "";
               if ($DODEBUG_OUT == 1)
               {
                   print "Handle: Address_of $2= 0x$Address_List{$2} plus offset $4$5 \n";
               }
               $Zahl = hex("0x$Address_List{$2}");
               if ($4 ne undef ) # Add hex Number .....
               {
                 $Zahl = $Zahl + hex("0x$5");
               }
               else # Add decimal number 
               {
                 $Zahl = $Zahl + $5;
               }
               $HexAddress = "0x".sprintf ("%08x",$Zahl);
               $line =~ s/$RegExp_Address_Offset/$HexAddress/;
               $This_Var = 1;
             }
             else
             {
               print "Error: Address_of $2 does not exist in List from MAP !\n";
               $All_Vars = 0;
             }
           }
           ######################################################
           # Replace <Size_of:Varname>
           # check if () $1 = Size_of and  $3 ="" -> No Calculation needed and Key $2 exists in Hash $Size_List{$2}
           ######################################################
           if ( ($1 eq "Size_of") && ($3 eq "") ) 
           {
             ######################################################
             # check if Key $2 exists in Hash $Size_List{$2}
             if (exists $Size_List{$2})
             {
               if ($DODEBUG_OUT == 1)
               {
                 print "Handle: Size_of $2= 0x$Size_List{$2}\n";
               }
               $line =~ s/$RegExp_Size/0x$Size_List{$2}/;
               $This_Var = 1;
             }
             else
             {
               print "Error: Size_of $2 does not exist in List from MAP !\n";
               $All_Vars = 0;
             }
           }
           ######################################################
           # Replace <Size_of:Varname;Calc:Methodname>
           # check if () $1 = Size_of and  $3 ="" -> No Offset needed and Key $2 exists in Hash $Address_List{$2}
           ######################################################
           if ( ($1 eq "Size_of") && ($3 eq "Calc") && ($4 ne "") ) 
           {
             ######################################################
             # check if Key $2 exists in Hash $Address_List{$2}
             if (exists $Size_List{$2})
             {
               my $Zahl = 0;
               my $HexSize = "";

               if ($DODEBUG_OUT == 1)
               {
                 print "Handle: Size_of $2 : Calcmethod ($3) \n";
               }

               # All sizes are hex in map 
               $Zahl = hex("0x$Size_List{$2}");
               ######################################################
               # check allowed values for Calcmethod 
               # Distab13|Distab12|Byp_Ret13|Byp_Ret12
               if ($4 eq "Distab13") 
               {
                 $Zahl = int(($Zahl-8)/4);  
                 $HexSize = "0x".sprintf ("%x",$Zahl);
                 $line =~ s/$RegExp_Size_Calc/$HexSize/;
                 $This_Var = 1;
               }
               if ($4 eq "Distab12" || $4 eq "Byp_Ret12") 
               {
                 $Zahl = int(($Zahl-2)/2);  
                 $HexSize = "0x".sprintf ("%x",$Zahl);
                 $line =~ s/$RegExp_Size_Calc/$HexSize/;
                 $This_Var = 1;
               }
               if ($4 eq "Byp_Ret13") 
               {
                 $Zahl = int(($Zahl-8)/2);  
                 $HexSize = "0x".sprintf ("%x",$Zahl);
                 $line =~ s/$RegExp_Size_Calc/$HexSize/;
                 $This_Var = 1;
               }
               if (0 == $This_Var ) 
               {
                   print "Error: Calculation method $4 not found \n";
               }

             }
             else
             {
               print "Error: Size_of $2 does not exist in List from MAP !\n";
               $All_Vars = 0;
               $This_Var = 1;
             }
           }
           if ( 0 == $This_Var ) 
           {
               print "Error :No Convertion method found !\n";
               $All_Vars = 0;
           }
        }
        print OUT $line; #print OUT "\n";
      }
   
      close (IN)||die "$thisScript: Couldn't close $Input_filename $!";
      close (OUT)||die "$thisScript: Couldn't close $Output_filename $!";
      if (0 == $All_Vars )
      {
         print "Error: Not all Replacement Variables from File: $Input_filename found in MAP file \n";
      }
      else
      {
        print "All Variables from file $Input_filename replaced with values from MAP file \n";
      }
   }
}