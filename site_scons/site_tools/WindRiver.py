import scons_common

from SCons.Script import *

# SCons mandatory function for custom tools, sets up environment
def generate(env):

######## ENVIRONMENT ########

	env['CPPDEFPREFIX'] 	= '-D'
	env['INCPREFIX']		= '-I'
	env['INCSUFFIX']		= ''
	env['OBJSUFFIX'] 		= '.o'
	env['DEPFILESUFFIX'] 	= '.d'
	env['MAPFILESUFFIX'] 	= '.map'
	env['LIBSUFFIX'] 		= '.a'
	env['PROGSUFFIX']		= '.elf'
	env['LIBLINKPREFIX']	= '-l:'
	env['LIBDIRPREFIX']		= '-L'
	env['HEXFILESUFFIX'] 	= '.hex'
	env['s19FILESUFFIX'] 	= '.s19'
	env['ASMSUFFIXES'] 		= ['.ppc', '.s', '.sx']
	env['CPPSUFFIXES'] 		= ['.c','.C','.h','.H']
	env['SPAWN'] 			= scons_common.w32api_cmdfilearg_spawn
	env['PRINT_CMD_LINE_FUNC'] = scons_common.print_cmd_line

######## END ENVIRONMENT ########

######## COMPILER ########

	# Implements: COR003, COR006, PLF001
	env['CC'] 				= env['COMPILER_ROOT'] + os.sep + 'dcc.exe'
	env['TARGETCPUOPT'] 	= env['CPU_TARGET']
	env['CPPDEFINES']   	= env['COMPILER_DEFINES']
	env['CPPDEFINESCOM']	= '${_defines(CPPDEFPREFIX, CPPDEFINES, CPPDEFSUFFIX, __env__)}'
	env['CCFLAGS'] 			= env['COMPILER_FLAGS']

	# Compiler command line
	env['CCCOM'] 			= '$CC -c -t$TARGETCPUOPT $CCFLAGS -I$CEN_HEADER_DIR $CPPDEFINESCOM -o $TARGET $SOURCE'

######## END COMPILER ########

	# Implements: COR004, COR008, PLF002
	env['AS']				= 'dcc'
	env['ASFLAGS']  		= env['ASSEMBLER_FLAGS']
	
	# Assembler command line
	env['ASCOM']			= '$AS -cpu=$TARGETCPUOPT -o $TARGET -c $SOURCES $ASCFLAGS $ASFLAGS $_ASCOMCOM $_ASCPPCOMCOM'
	env['ASPPFLAGS'] 		= env['ASSEMBLER_FLAGS']
	env['ASCPPDEFINES']		= env['ASSEMBLER_DEFINES']
	env['_ASCPPDEFFLAGS'] 	= '${_defines(CPPDEFPREFIX, ASCPPDEFINES, CPPDEFSUFFIX, __env__)}'
	env['_ASCPPCOMCOM']    	=  '$ASCPPFLAGS $_ASCPPDEFFLAGS $_ASCPPINCFLAGS $_CPPINCFLAGS'
	
	# Assembler command line
	env['ASPPCOM']			= '$AS -t$TARGETCPUOPT -o $TARGET -c $SOURCES $ASPPFLAGS $ASCFLAGS $_ASCPPCOMCOM'
######## LINKER ########

	# Implements: COR005, COR007, PLF003
	env['LINK'] 			= env['COMPILER_ROOT'] + os.sep + 'dld.exe'
	env['LINKFLAGS']		= env['LINKER_FLAGS']
	env['LINKCMDFILE'] 		= ''
	env['LIBS']				= env['ADD_LIBRARIES']
	env['LIBPATH']			= env['LIBRARY_PATHS']
	env['LINKERGENMAPFILE'] = ""
	env['_LIBDIRFLAGS'] 	= '${_concat(LIBDIRPREFIX, LIBPATH, LIBDIRSUFFIX, __env__, RDirs, TARGET, SOURCE)}'
	env['_LIBFLAGS']		= '${_concat(LIBLINKPREFIX, LIBS, LIBLINKSUFFIX, __env__)}'
	# Linker command line
	env['LINKCOM']  		= '$LINK $LINKFLAGS $LINKERGENMAPFILE $LINKCMDFILE -o $TARGET $_LIBDIRFLAGS $OBJECT_FILE $_LIBFLAGS'
#	env['LINKCOM']  		= '$LINK  $LINKFLAGS  $LINKERGENMAPFILE $LINKCMDFILE -o  $TARGET'
	# Linker command line

######## END LINKER ########

######## OBJECT BUILDER ########

	# Implements: COR003, COR004
	cs = SCons.Scanner.ClassicCPP("CScanner", "$CPPSUFFIXES", "CPPPATH", '^[ \t]*#[ \t]*(?:include|import)[ \t]*(<|")([^>"]+)(>|")')

	obj_builder = SCons.Builder.Builder(action = '$CCCOM',
										src_suffix = env.subst('$CPPSUFFIXES') + env.subst('$ASMSUFFIXES'),
										suffix = env.subst('$OBJSUFFIX'),
										source_scanner = cs)

	env['BUILDERS']['Object']	= obj_builder

######## END OBJECT BUILDER ########
######## HEX BUILDER ########

	# Implements: COR011
	env['HEXCMD'] 			= env['COMPILER_ROOT'] + os.sep + 'ddump.exe'

	hex_builder = SCons.Builder.Builder(action = '$HEXCMD -X -o $TARGET $SOURCE',
										single_source = 1,
										suffix = env.subst('$HEXFILESUFFIX'))

	env['BUILDERS']['Hex']	= hex_builder

######## END HEX BUILDER ########

######## HEX BUILDER ########

	# Implements: COR011
	env['S19CMD'] 			= env['COMPILER_ROOT'] + os.sep + 'ddump.exe'



	s19_builder = SCons.Builder.Builder(action = '$S19CMD -Rv -o $TARGET $SOURCE',
										single_source = 1,
										suffix = env.subst('$s19FILESUFFIX'))

	env['BUILDERS']['S19']	= s19_builder

######## END HEX BUILDER ########


# SCons mandatory function for custom tools
def exists(env):
    return True
