################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)
CG_TOOL_ROOT := C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./csl_spi.obj" \
"./src/util_circ.obj" \
"./src/uartTest.obj" \
"./src/timer.obj" \
"./src/pal_osTime.obj" \
"./src/pal_osSem.obj" \
"./src/pal_osProtect.obj" \
"./src/pal_osMem.obj" \
"./src/pal_osList.obj" \
"./src/oledDisplay.obj" \
"./src/llc_uart.obj" \
"./src/llc_spi.obj" \
"./src/ddc_uart.obj" \
"./src/ddc_spi.obj" \
"./src/ddc_dma.obj" \
"./src/dda_uartCfg.obj" \
"./src/dda_uart.obj" \
"./src/dda_spi.obj" \
"./src/dda_dma.obj" \
"./src/csl_sar.obj" \
"./src/cpu_clock_init.obj" \
"./src/adcSpi.obj" \
"./src/I2C.obj" \
"./src/ECG_Filter_Co-efficients.obj" \
"./src/ECGSystem_main.obj" \
"./src/ECGSystemInit.obj" \
"./src/ECGSystemFunctions.obj" \
"./src/ADS1220.obj" \
-l"libc.a" \
-l"cslVC5505.lib" \
-l"rts55x.lib" \
-l"ezdsp5535bsl.lib" \
"../lnkx.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include src/subdir_vars.mk
-include subdir_rules.mk
-include src/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ECGdsV1.1.out

# Tool invocations
ECGdsV1.1.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large -z -m"ECGdsV1.1.map" --warn_sections -i"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/lib" -i"C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/ccs_v4.0_examples/cslVC5505/Debug" -i"C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/lib" -i"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --reread_libs --rom_model -o "ECGdsV1.1.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C5500_EXECUTABLE_OUTPUTS__QTD) "ECGdsV1.1.out"
	-$(RM) ".\src\ADS1220.obj" ".\src\ECGSystemFunctions.obj" ".\src\ECGSystemInit.obj" ".\src\ECGSystem_main.obj" ".\src\ECG_Filter_Co-efficients.obj" ".\src\I2C.obj" ".\src\adcSpi.obj" ".\src\cpu_clock_init.obj" ".\src\csl_sar.obj" ".\src\dda_dma.obj" ".\src\dda_spi.obj" ".\src\dda_uart.obj" ".\src\dda_uartCfg.obj" ".\src\ddc_dma.obj" ".\src\ddc_spi.obj" ".\src\ddc_uart.obj" ".\src\llc_spi.obj" ".\src\llc_uart.obj" ".\src\oledDisplay.obj" ".\src\pal_osList.obj" ".\src\pal_osMem.obj" ".\src\pal_osProtect.obj" ".\src\pal_osSem.obj" ".\src\pal_osTime.obj" ".\src\timer.obj" ".\src\uartTest.obj" ".\src\util_circ.obj" ".\csl_spi.obj" 
	-$(RM) ".\src\ADS1220.pp" ".\src\ECGSystemFunctions.pp" ".\src\ECGSystemInit.pp" ".\src\ECGSystem_main.pp" ".\src\ECG_Filter_Co-efficients.pp" ".\src\I2C.pp" ".\src\adcSpi.pp" ".\src\cpu_clock_init.pp" ".\src\csl_sar.pp" ".\src\dda_dma.pp" ".\src\dda_spi.pp" ".\src\dda_uart.pp" ".\src\dda_uartCfg.pp" ".\src\ddc_dma.pp" ".\src\ddc_spi.pp" ".\src\ddc_uart.pp" ".\src\llc_spi.pp" ".\src\llc_uart.pp" ".\src\oledDisplay.pp" ".\src\pal_osList.pp" ".\src\pal_osMem.pp" ".\src\pal_osProtect.pp" ".\src\pal_osSem.pp" ".\src\pal_osTime.pp" ".\src\timer.pp" ".\src\uartTest.pp" ".\src\util_circ.pp" ".\csl_spi.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
