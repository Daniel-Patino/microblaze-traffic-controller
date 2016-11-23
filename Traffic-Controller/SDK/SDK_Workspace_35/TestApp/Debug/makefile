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
TestApp.elf.size \

ELFCHECK += \
TestApp.elf.elfcheck \


# All Target
all: TestApp.elf secondary-outputs

# Tool invocations
TestApp.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MicroBlaze gcc linker'
	mb-gcc -Wl,-T -Wl,../src/lscript.ld -L../../standalone_bsp_0/microblaze_0/lib -mxl-pattern-compare -mcpu=v7.30.a -mno-xl-soft-mul -o"TestApp.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TestApp.elf.size: TestApp.elf
	@echo 'Invoking: MicroBlaze Print Size'
	mb-size TestApp.elf  |tee "TestApp.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

TestApp.elf.elfcheck: TestApp.elf
	@echo 'Invoking: Xilinx ELF Check'
	elfcheck TestApp.elf -hw ../../hw_platform_0/system.xml -pe microblaze_0  |tee "TestApp.elf.elfcheck"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES)$(ELFSIZE)$(ELFCHECK)$(S_UPPER_DEPS) TestApp.elf
	-@echo ' '

secondary-outputs: $(ELFSIZE) $(ELFCHECK)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
