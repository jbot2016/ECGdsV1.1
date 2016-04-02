################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/ADS1220.obj: ../src/ADS1220.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/ADS1220.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/ECGSystemFunctions.obj: ../src/ECGSystemFunctions.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/ECGSystemFunctions.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/ECGSystemInit.obj: ../src/ECGSystemInit.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/ECGSystemInit.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/ECGSystem_main.obj: ../src/ECGSystem_main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/ECGSystem_main.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/ECG_Filter_Co-efficients.obj: ../src/ECG_Filter_Co-efficients.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/ECG_Filter_Co-efficients.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/I2C.obj: ../src/I2C.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/I2C.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/adcSpi.obj: ../src/adcSpi.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/adcSpi.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/cpu_clock_init.obj: ../src/cpu_clock_init.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/cpu_clock_init.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/csl_sar.obj: ../src/csl_sar.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/csl_sar.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/dda_dma.obj: ../src/dda_dma.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/dda_dma.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/dda_spi.obj: ../src/dda_spi.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/dda_spi.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/dda_uart.obj: ../src/dda_uart.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/dda_uart.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/dda_uartCfg.obj: ../src/dda_uartCfg.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/dda_uartCfg.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/ddc_dma.obj: ../src/ddc_dma.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/ddc_dma.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/ddc_spi.obj: ../src/ddc_spi.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/ddc_spi.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/ddc_uart.obj: ../src/ddc_uart.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/ddc_uart.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/llc_spi.obj: ../src/llc_spi.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/llc_spi.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/llc_uart.obj: ../src/llc_uart.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/llc_uart.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/oledDisplay.obj: ../src/oledDisplay.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/oledDisplay.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/pal_osList.obj: ../src/pal_osList.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/pal_osList.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/pal_osMem.obj: ../src/pal_osMem.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/pal_osMem.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/pal_osProtect.obj: ../src/pal_osProtect.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/pal_osProtect.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/pal_osSem.obj: ../src/pal_osSem.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/pal_osSem.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/pal_osTime.obj: ../src/pal_osTime.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/pal_osTime.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/timer.obj: ../src/timer.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/timer.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/uartTest.obj: ../src/uartTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/uartTest.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/util_circ.obj: ../src/util_circ.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="src/util_circ.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


