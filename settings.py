# Version information:
# BUILD_TYPE = PROD  : production release
# BUILD_TYPE = DEBUG : temporary debug build
# BUILD_TYPE = DEVEL : development release
BUILD_TYPE          = 'DEBUG'
PROJ_NAME           = 'ENTRY_PLATFROM'
SW_VERSION_MSB      = 0
SW_VERSION_LSB      = 0

#nothing222222
# Compiler Type Choice 
			# COMPILER_CHOICE = TASKING     : Tasking V4 Compiler
			# COMPILER_CHOICE = GNU         : GNU Hightec Compiler
			# COMPILER_CHOICE = WINDRIVER   : WINDRIVER Compiler
COMPILER_CHOICE = 'TASKING'
#COMPILER_CHOICE = 'GNU'

# General configuration:--------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
	OUTPUT_DIR          = 'output'
	LOG_DIR             = 'log'
	COMPILER_TOOL       = 'Tasking'#Must match the file name located in the site_tools directory
	COMPILER_ROOT       = 'C:/TASKING/TriCorev6.2r1/ctc/bin'#fill you compiler location


elif COMPILER_CHOICE == 'GNU':
	OUTPUT_DIR          = 'output'
	LOG_DIR             = 'log' 	
	COMPILER_TOOL       = 'Hightec'#Must match the file name located in the site_tools directory
	COMPILER_ROOT       = 'C:/HIGHTEC/TOOLCHAINS/TRICORE/V4.6.6.1/bin'#fill you compiler location
elif COMPILER_CHOICE == 'WINDRIVER':
	OUTPUT_DIR          = 'output'
	LOG_DIR             = 'log'
	COMPILER_TOOL       = 'WindRiver'#Must match the file name located in the site_tools directory
	COMPILER_ROOT       = 'C:/WindRiver/diab/5.9.4.7/WIN32/bin'#fill you compiler location


# CPU target--------------------------------------------------------------------------------------------------------
#CPU_TARGET          = 'PPCE200Z425N3VEG:simple'
CPU_TARGET            = 'tc27xx'
CPU_USED            = 'tc27x'

# Compiler configuration:-------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
	
	COMPILER_DEFINES        = ['-D_TASKING_C_TRICORE_=1'] 
	COMPILER_FLAGS		= '	-Ctc27x \
							--core=tc1.6.x \
							-t \
							-Wa-gAHLs \
							--emit-locals=-equ,-symbols \
							-Wa-Ogs \
							-Wa--error-limit=42 \
							--iso=99 \
							--eabi-compliant \
							--integer-enumeration \
							--language=-comments,-gcc,+volatile,-strings \
							--switch=auto \
							--default-near-size=0 \
							--default-a0-size=0 \
							--default-a1-size=0 \
							-O2ROPYGKLF-predict \
							--tradeoff=4 \
							-g \
							--source '

elif COMPILER_CHOICE == 'GNU':
	COMPILER_DEFINES        = ['-D_GNU_C_TRICORE_=1'] 
	COMPILER_FLAGS			= '-g \
								-O3 \
								-fshort-double \
								-gdwarf-2 \
								-Wall \
								-W \
								-Wno-unused-variable \
								-Wno-empty-body \
								-Wbad-function-cast \
								-Wstrict-prototypes \
								-Wmissing-noreturn \
								-Wnested-externs \
								-fno-builtin \
								-Wno-unused-parameter \
								-Wno-pointer-to-int-cast \
								-Wfloat-equal \
								-nostartfiles \
								-fno-common \
								-ffreestanding \
								-fno-short-enums \
								-fpeel-loops \
								-falign-functions=4 \
								-funsigned-bitfields \
								-fno-asm \
								-fno-ivopts \
								-fno-peephole2 \
								-mtc161 \
								-ffunction-sections \
								-fdata-sections '

elif COMPILER_CHOICE == 'WINDRIVER':
	COMPILER_DEFINES        = ['_WINDRIVER_C_TRICORE_=1'] 
	COMPILER_FLAGS			= '-save-temps=obj \
                            -std=iso9899:1990 \
                            -ansi \
                            -fno-asm \
                            -ffreestanding \
                            -Wundef \
                            -Wp,-std=iso9899:1990 \
                            -fno-short-enums \
                            -fpeel-loops \
                            -falign-functions=4 \
                            -frecord-gcc-switches \
                            -fsection-anchors \
                            -funsigned-bitfields \
                            -ffunction-sections \
                            -fno-ivopts \
                            -fno-peephole2 \
                            -nostartfiles \
                            -O3 \
                            -g3 \
                            -W \
                            -Wall \
                            -Wuninitialized \
                            -mtc161'
                            



# Assembler configuration:-------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
	ASSEMBLER_DEFINES      = COMPILER_DEFINES
	ASSEMBLER_FLAGS     = '    -Ctc27x \
	                            --lsl-core=vtc \
	                            -t \
	                            -Wa-H"sfr/regtc27x.def" \
	                            -Wa-gAHLs \
	                            --emit-locals=-equs,-symbols \
	                            -Wa-Ogs \
	                            -Wa--error-limit=42'

elif COMPILER_CHOICE == 'GNU':
	ASSEMBLER_DEFINES       = COMPILER_DEFINES
	ASSEMBLER_FLAGS			= COMPILER_FLAGS

elif COMPILER_CHOICE == 'WINDRIVER':
	ASSEMBLER_DEFINES       = ''
	ASSEMBLER_FLAGS			= ''


# Libraries to include:----------------------------------------------------------------------------------------------


if COMPILER_CHOICE == 'TASKING':
	ADD_LIBRARIES        = ['.\Targets\TC275\RTOS_T\Gen\RTAOS.a']  
elif COMPILER_CHOICE == 'GNU':
	ADD_LIBRARIES        = ['.\Targets\TC275\RTOS_G\Gen\RTAOS.a']  
elif COMPILER_CHOICE == 'WINDRIVER':
	ADD_LIBRARIES        = ['.\Targets\TC275\RTOS_W\Gen\RTAOS.a']  

LIBRARY_PATHS        = []

OBJECT_FILE         = 	[]


# Linker configuration:----------------------------------------------------------------------------------------------

#No optimization		 	-OCLTXY --optimize=0 -O0
#Default optimization 		-OcLtxy --optimize=1 -O1
#All optimizations 	 		-Ocltxy --optimize=2 -O2

if COMPILER_CHOICE == 'TASKING':
	LINKER_FLAGS    =   '-D__PROC_TC27X__ \
						--core=mpe:vtc \
						-OCLTXY \
						-Cmpe:vtc \
						-M         \
						-mcrfiklSmNOduQ \
						--error-limit=42'
	LINKER_FILE       = '.\Targets\TC275\Linker\ENTRY_PLATFORM_AUTOSAR_LSL_TASKING.lsl'

elif COMPILER_CHOICE == 'GNU':
	LINKER_FLAGS      = '-O0 \
						-nodefaultlibs \
						-nostdlib \
						-nostartfiles \
						-Wl,--allow-multiple-definition \
						-Wl,--cref \
						-Wl,--oformat=elf32-tricore \
						-Wl,--mcpu=tc161 \
						-Wl,--relax \
						-Wl,--mem-holes \
						-Wl,--warn-once \
						-Wl,--extmap="a"'
	LINKER_FILE       = '.\Targets\TC275\Linker\ENTRY_PLATFORM_AUTOSAR_LD_HIGHTECH.ld'
elif COMPILER_CHOICE == 'WINDRIVER':
	LINKER_FLAGS      = ''
	LINKER_FILE       = ''
	


#centralized header directory::----------------------------------------------------------------------------------------------
if COMPILER_CHOICE == 'TASKING':
	CEN_HEADER_DIR = '.\output\inc'

elif COMPILER_CHOICE == 'GNU':
	CEN_HEADER_DIR = '.\output\inc'

elif COMPILER_CHOICE == 'WINDRIVER':
	CEN_HEADER_DIR = '.\output\inc'

