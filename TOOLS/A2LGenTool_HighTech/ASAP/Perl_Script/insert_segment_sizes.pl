use strict;

my $DEBUG_ENABLE = 1;
open(STDERR, ">&STDOUT"); 
my $thisScript="insert_segment_sizes.pl";
######################################################
# get Basic Arguments from Commandline 
######################################################
my $map_file=$ARGV[0];
my $a2l_file=$ARGV[1];
my $a2l_file_out=$ARGV[2];
my $map_file_regex= "Binh";
######################################################
# define format of map file  
my $map_type = 1;

if ($map_type == 1)  #Tricore TC275
{
	$map_file_regex="^([a-zA-Z0-9]{1,}\\w+)[\\s]+(0x[0-9a-fA-F]{8})[\\s]+?(0x[0-9a-fA-F]{8})\\s+?(0x[0-9a-fA-F]{8})\\s+?0x[0-9a-fA-F]{8}";
}
elsif ($map_type == 2) #ARM - TSM570
{ 
	$map_file_regex="^\\s+([0-9a-fA-F]{8})[\\s]+?([0-9a-fA-F]{8})\\s+?([0-9a-fA-F]{8})\\s+?([0-9a-fA-F]{8})\\s+?(r\-x)\\s+?(\.text)";
}
elsif ($map_type == 3) #Power PC - MPC574
{
	$map_file_regex= "^(0x[0-9a-fA-F]{1,})\\s+(0x[0-9a-fA-F]{1,})\\s+([0-9a-fA-F]{1,}).+\\s([a-zA-Z0-9]{1,}\\w+)";
	#\\s+(0x[0-9a-fA-F]{1,})\\s+[0-9a-fA-F]{1,}\W\s+[0-9]{1,}\W\\s+[0x]?[0-9a-fA-F].+([a-zA-Z0-9]{1,}\w+)";
#0x1000000   0x580000    373936( 6%)     0x270  flash_memory
#0x8f90000    0x10000        40( 0%)         0  mirrorfls
}
else
{
	print "Type of map file is not supported";
}
my $addr_regex           = "<Address_of_segment:\\s*(\\w*)>";
my $size_regex           = "<Size_of_segment:\\s*(\\w*)>";

my @replacement_list = [];
my %segment_addr = {};
my %segment_size = {};

######################################################
# Start the replacement sequence
######################################################
print "\n\nStarting script $thisScript!\n";
&Read_a2l_Get_Replacement_List;
&Read_Map_Get_Segment_Size;
&Replace_Size_In_a2l;
######################################################
# End of the replacement sequence
######################################################




######################################################
# Search the a2l to get the list of segments which
# need to be updated with its size
######################################################
sub Read_a2l_Get_Replacement_List
{
  my $addr_found = 0;
  my $size_found = 0;
  open(MAP, $a2l_file )||die "$thisScript: Couldn't open $a2l_file: $!";
  while(<MAP>)
  {
	if( s/$addr_regex// )
	{
		if($DEBUG_ENABLE)
		{
			print "Address of segment $1 found in $a2l_file\n";
		}
		push @replacement_list, $1;
		$addr_found++;
	}
	if( s/$size_regex// )
	{
		if($DEBUG_ENABLE)
		{
			print "Size of segment $1 found in $a2l_file\n";
		}
		#address of segment always comes first, followed by size
		if(grep(/$1/, @replacement_list))
		{
			$size_found++;
		}
		else
		{
			die "$thisScript: Size of segment appears before address $a2l_file $!"
		}
	}
  }
  if($DEBUG_ENABLE)
  {
	print "Number of address found: $addr_found\nNumber of size found: $size_found\n";
  }
  if($addr_found != $size_found)
  {
	die "$thisScript: number of segment address and segment size not match in $a2l_file $!";
  }
  close (MAP)||die "$thisScript: Couldn't close $a2l_file $!";
}

######################################################
# Search the map file to get size of the segments
######################################################
sub Read_Map_Get_Segment_Size
{
  open(MAP, $map_file )||die "$thisScript: Couldn't open $map_file: $!";
  while(<MAP>)
  {
	if( s/$map_file_regex//)
	{
		my $segment = $1;
		my $addr = $2;
		my $size = $3;
		if (grep( /$segment/, @replacement_list ))
		{
			if($DEBUG_ENABLE)
			{
				print "Segment $segment found in map file. Address is: $addr. Size is: $size\n";
			}
			$segment_addr{$segment} = $addr;
			$segment_size{$segment} = $size;
		}
	}
  }
  close (MAP)||die "$thisScript: Couldn't close $map_file $!";
}

######################################################
# Replace the a2l with the sizes got from map file
######################################################

sub Replace_Size_In_a2l
{
  open(IN, $a2l_file )||die "$thisScript: Couldn't open $a2l_file: $!";
  open(OUT, ">$a2l_file_out" )||die "$thisScript: Couldn't open $a2l_file_out for replacement: $!";
  while(<IN>)
  {
	my $line = $_;
	if( s/$addr_regex// )
	{
		if(exists($segment_addr{$1}))
		{
			$line =~ s/$addr_regex/$segment_addr{$1}/;
			if($DEBUG_ENABLE)
			{
				print "$line\n";
			}
		}
		else
		{
			die "$thisScript: Couldn't find the address of segment $1 in map file. Please check $!";
		}
	}
	if( s/$size_regex// )
	{
		if(exists($segment_size{$1}))
		{
			$line =~ s/$size_regex/$segment_size{$1}/;
			if($DEBUG_ENABLE)
			{
				print "$line\n";
			}
		}
		else
		{
			die "$thisScript: Couldn't find the size of segment $1 in map file. Please check $!";
		}
	}
	print OUT $line;
  }
  close (IN)||die "$thisScript: Couldn't close $a2l_file $!"; 
  close (OUT)||die "$thisScript: Couldn't close $a2l_file_out $!";
}