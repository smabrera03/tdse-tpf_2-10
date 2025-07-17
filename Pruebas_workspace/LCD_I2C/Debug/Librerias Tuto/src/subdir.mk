################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Librerias\ Tuto/src/I2C_LCD.c \
../Librerias\ Tuto/src/I2C_LCD_cfg.c \
../Librerias\ Tuto/src/Util.c 

OBJS += \
./Librerias\ Tuto/src/I2C_LCD.o \
./Librerias\ Tuto/src/I2C_LCD_cfg.o \
./Librerias\ Tuto/src/Util.o 

C_DEPS += \
./Librerias\ Tuto/src/I2C_LCD.d \
./Librerias\ Tuto/src/I2C_LCD_cfg.d \
./Librerias\ Tuto/src/Util.d 


# Each subdirectory must supply rules for building sources it contributes
Librerias\ Tuto/src/I2C_LCD.o: ../Librerias\ Tuto/src/I2C_LCD.c Librerias\ Tuto/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Librerias Tuto/src/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Librerias\ Tuto/src/I2C_LCD_cfg.o: ../Librerias\ Tuto/src/I2C_LCD_cfg.c Librerias\ Tuto/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Librerias Tuto/src/I2C_LCD_cfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Librerias\ Tuto/src/Util.o: ../Librerias\ Tuto/src/Util.c Librerias\ Tuto/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Librerias Tuto/src/Util.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Librerias-20-Tuto-2f-src

clean-Librerias-20-Tuto-2f-src:
	-$(RM) ./Librerias\ Tuto/src/I2C_LCD.cyclo ./Librerias\ Tuto/src/I2C_LCD.d ./Librerias\ Tuto/src/I2C_LCD.o ./Librerias\ Tuto/src/I2C_LCD.su ./Librerias\ Tuto/src/I2C_LCD_cfg.cyclo ./Librerias\ Tuto/src/I2C_LCD_cfg.d ./Librerias\ Tuto/src/I2C_LCD_cfg.o ./Librerias\ Tuto/src/I2C_LCD_cfg.su ./Librerias\ Tuto/src/Util.cyclo ./Librerias\ Tuto/src/Util.d ./Librerias\ Tuto/src/Util.o ./Librerias\ Tuto/src/Util.su

.PHONY: clean-Librerias-20-Tuto-2f-src

