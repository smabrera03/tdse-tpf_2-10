################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Librerias\ Tuto/I2C_LCD.c \
../Librerias\ Tuto/I2C_LCD_cfg.c \
../Librerias\ Tuto/Util.c 

OBJS += \
./Librerias\ Tuto/I2C_LCD.o \
./Librerias\ Tuto/I2C_LCD_cfg.o \
./Librerias\ Tuto/Util.o 

C_DEPS += \
./Librerias\ Tuto/I2C_LCD.d \
./Librerias\ Tuto/I2C_LCD_cfg.d \
./Librerias\ Tuto/Util.d 


# Each subdirectory must supply rules for building sources it contributes
Librerias\ Tuto/I2C_LCD.o: ../Librerias\ Tuto/I2C_LCD.c Librerias\ Tuto/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Librerias Tuto/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Librerias\ Tuto/I2C_LCD_cfg.o: ../Librerias\ Tuto/I2C_LCD_cfg.c Librerias\ Tuto/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Librerias Tuto/I2C_LCD_cfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Librerias\ Tuto/Util.o: ../Librerias\ Tuto/Util.c Librerias\ Tuto/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Librerias Tuto/Util.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Librerias-20-Tuto

clean-Librerias-20-Tuto:
	-$(RM) ./Librerias\ Tuto/I2C_LCD.cyclo ./Librerias\ Tuto/I2C_LCD.d ./Librerias\ Tuto/I2C_LCD.o ./Librerias\ Tuto/I2C_LCD.su ./Librerias\ Tuto/I2C_LCD_cfg.cyclo ./Librerias\ Tuto/I2C_LCD_cfg.d ./Librerias\ Tuto/I2C_LCD_cfg.o ./Librerias\ Tuto/I2C_LCD_cfg.su ./Librerias\ Tuto/Util.cyclo ./Librerias\ Tuto/Util.d ./Librerias\ Tuto/Util.o ./Librerias\ Tuto/Util.su

.PHONY: clean-Librerias-20-Tuto

