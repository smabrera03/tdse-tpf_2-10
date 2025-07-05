################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app/src/KEYPAD.c \
../app/src/KEYPAD_cfg.c \
../app/src/logger.c 

OBJS += \
./app/src/KEYPAD.o \
./app/src/KEYPAD_cfg.o \
./app/src/logger.o 

C_DEPS += \
./app/src/KEYPAD.d \
./app/src/KEYPAD_cfg.d \
./app/src/logger.d 


# Each subdirectory must supply rules for building sources it contributes
app/src/%.o app/src/%.su app/src/%.cyclo: ../app/src/%.c app/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../app/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-app-2f-src

clean-app-2f-src:
	-$(RM) ./app/src/KEYPAD.cyclo ./app/src/KEYPAD.d ./app/src/KEYPAD.o ./app/src/KEYPAD.su ./app/src/KEYPAD_cfg.cyclo ./app/src/KEYPAD_cfg.d ./app/src/KEYPAD_cfg.o ./app/src/KEYPAD_cfg.su ./app/src/logger.cyclo ./app/src/logger.d ./app/src/logger.o ./app/src/logger.su

.PHONY: clean-app-2f-src

