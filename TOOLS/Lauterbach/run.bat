set T32=C:\T32

if not @%T32% == @ goto got_t32
@echo You need to set the env variable T32 to something like c:\t32 so I can find the debugger...
goto exit

:got_t32
set T32_BIN=%T32%\bin\windows64
if exist %T32_BIN%\t32mtc.exe goto prep
set T32_BIN=%T32%\bin\windows
if exist %T32_BIN%\t32mtc.exe goto prep
set T32_BIN=%T32%
if exist %T32_BIN%\t32mtc.exe goto prep
echo Can't find t32mtc.exe in '%T32%' or '%T32%\bin\windows or '%T32%\bin\windows64'

:prep

@echo Starting > test.log
copy "TC275.cmm" work-settings.cmm

%T32_BIN%\t32mtc.exe -c %T32%\config.t32 test.log %1
goto exit

:exit


