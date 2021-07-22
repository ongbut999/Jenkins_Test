REM Please adapt Perl pathes according to your installation
REM Here a Strawberry perl installation is used
SET PERL_DIR=C:\Strawberry\perl\bin
SET PERL5LIB=C:\Strawberry\perl

set HOME=%~dp0
set SW_HOME=%~dp0\..\..\..
set XCP=%SW_HOME%\BSW\src\BSW\Gen\Xcp
set A2L=%SW_HOME%\TOOLS\A2LGenTool_HighTech

REM xcopy %SW_HOME%\Integration\Entry_A2L.a2l %A2L% /y
xcopy %SW_HOME%\output\dbg\D_ENTRY_PLATFROM.map %A2L% /y
cd %A2L%\ASAP

REM First copy map file to local directory, Delete old A2L Output file
del D_ENTRY_PLATFROM_temp.a2l
REM Delete old Map file from build, rename to adapt to your project
del D_ENTRY_PLATFROM_temp.map
REM Delete old a2l file from generation
del Entry_A2L_temp.a2l
REM Delete old files from last run with modified addresses
del *.adr


REM Please adapt pathes according to your build, Copy map file from build to local directory
copy "..\D_ENTRY_PLATFROM.map" D_ENTRY_PLATFROM_temp.map /B
REM // Copy a2l Config file from generation to local directory
copy "..\Entry_A2L_Template.a2l" Entry_A2L_temp.a2l /B

%PERL_DIR%\perl.exe perl_script\insert_ecu_addresses.pl "D_ENTRY_PLATFROM_temp.map" "Adr_Files" "HIGHTEC_TC27X" "Characteristics.Adr" "Measurements.Adr" > Output_mc.log
%PERL_DIR%\perl.exe perl_script\merge_include.pl -f="Entry_A2L_temp.a2l" -o="Asap_Main_mc_out_temp.a2l" >> Output_mc.log
%PERL_DIR%\perl.exe perl_script\insert_segment_sizes.pl "D_ENTRY_PLATFROM_temp.map" "Asap_Main_mc_out_temp.a2l" "Entry_A2L_out_temp.a2l" >> Output_mc.log

copy "Entry_A2L_out_temp.a2l" "..\A2LGen\Entry_A2L_Complete.a2l"

REM // Delete temp files from this run with modified addresses
del *.adr
REM del "Asap_Main_mc_out_temp.a2l"
xcopy %SW_HOME%\output\hex\D_ENTRY_PLATFROM.hex %SW_HOME%\TOOLS\INCATest\D_ENTRY_PLATFROM.hex /y /f
xcopy %A2L%\A2LGen\Entry_A2L_Complete.a2l %SW_HOME%\TOOLS\INCATest\Entry_A2L_Complete.a2l /y /f
cd %HOME%
pause