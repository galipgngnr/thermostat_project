################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
fonksiyon/%.obj: ../fonksiyon/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --use_hw_mpy=none --include_path="C:/ti/ccs1240/ccs/ccs_base/msp430/include" --include_path="C:/Users/glpgn/Desktop/msp_workspace/LCD/interrupts" --include_path="C:/Users/glpgn/Desktop/msp_workspace/LCD/ADC_CONFIG" --include_path="C:/Users/glpgn/Desktop/msp_workspace/LCD/GPIO_CONFIG" --include_path="C:/Users/glpgn/Desktop/msp_workspace/LCD/LCD_CONFIG/inc" --include_path="C:/Users/glpgn/Desktop/msp_workspace/LCD/LCD_CONFIG/src" --include_path="C:/Users/glpgn/Desktop/msp_workspace/LCD" --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power=all --advice:hw_config=all --define=__MSP430FR4132__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="fonksiyon/$(basename $(<F)).d_raw" --obj_directory="fonksiyon" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


