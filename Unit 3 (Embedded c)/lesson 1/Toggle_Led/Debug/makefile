################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
embedded\ first\ lesson.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
embedded\ first\ lesson.list \

OBJCOPY_HEX += \
embedded\ first\ lesson.hex \

OBJCOPY_BIN += \
embedded\ first\ lesson.bin \


# All Target
all: embedded\ first\ lesson.elf secondary-outputs

# Tool invocations
embedded\ first\ lesson.elf: $(OBJS) $(USER_OBJS) C:\Users\ayman\STM32CubeIDE\workspace_1.4.0\embedded\ first\ lesson\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "embedded first lesson.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\ayman\STM32CubeIDE\workspace_1.4.0\embedded first lesson\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="embedded first lesson.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

embedded\ first\ lesson.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "embedded first lesson.list"
	@echo 'Finished building: $@'
	@echo ' '

embedded\ first\ lesson.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "embedded first lesson.hex"
	@echo 'Finished building: $@'
	@echo ' '

embedded\ first\ lesson.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "embedded first lesson.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
