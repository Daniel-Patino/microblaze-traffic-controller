################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
lab4.elf.size \

ELFCHECK += \
lab4.elf.elfcheck \


# All Target
all: lab4.elf secondary-outputs

# Tool invocations
lab4.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MicroBlaze gcc linker'
	mb-gcc -Wl,-T -Wl,../lscript.ld -L../../standalone_bsp_0/microblaze_0/lib -mxl-pattern-compare -mcpu=v7.30.a -mno-xl-soft-mul -o"lab4.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lab4.elf.size: lab4.elf
	@echo 'Invoking: MicroBlaze Print Size'
	mb-size lab4.elf  |tee "lab4.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

lab4.elf.elfcheck: lab4.elf
	@echo 'Invoking: Xilinx ELF Check'
	elfcheck lab4.elf -hw ../../hw_platform_0/system.xml -pe microblaze_0  |tee "lab4.elf.elfcheck"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) lab4.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
