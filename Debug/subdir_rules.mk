################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
csl_spi.obj: ../csl_spi.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/common_inc" --include_path="C:/Users/Joey Botero/Documents/workspace/ECGdsV1.1/inc" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/include" --include_path="C:/Program Files (x86)/Texas Instruments/ccsv4/emulation/boards/ezdsp5535_v1/c55xx_csl/inc" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=large --preproc_with_compile --preproc_dependency="csl_spi.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


