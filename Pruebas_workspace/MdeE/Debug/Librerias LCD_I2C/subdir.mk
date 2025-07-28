################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Librerias\ LCD_I2C/I2C_LCD.c \
../Librerias\ LCD_I2C/I2C_LCD_cfg.c \
../Librerias\ LCD_I2C/Util.c 

OBJS += \
./Librerias\ LCD_I2C/I2C_LCD.o \
./Librerias\ LCD_I2C/I2C_LCD_cfg.o \
./Librerias\ LCD_I2C/Util.o 

C_DEPS += \
./Librerias\ LCD_I2C/I2C_LCD.d \
./Librerias\ LCD_I2C/I2C_LCD_cfg.d \
./Librerias\ LCD_I2C/Util.d 


# Each subdirectory must supply rules for building sources it contributes
Librerias\ LCD_I2C/I2C_LCD.o: ../Librerias\ LCD_I2C/I2C_LCD.c Librerias\ LCD_I2C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../app/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Librerias LCD_I2C/I2C_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Librerias\ LCD_I2C/I2C_LCD_cfg.o: ../Librerias\ LCD_I2C/I2C_LCD_cfg.c Librerias\ LCD_I2C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../app/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Librerias LCD_I2C/I2C_LCD_cfg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Librerias\ LCD_I2C/Util.o: ../Librerias\ LCD_I2C/Util.c Librerias\ LCD_I2C/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../app/inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Librerias LCD_I2C/Util.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Librerias-20-LCD_I2C

clean-Librerias-20-LCD_I2C:
	-$(RM) ./Librerias\ LCD_I2C/I2C_LCD.cyclo ./Librerias\ LCD_I2C/I2C_LCD.d ./Librerias\ LCD_I2C/I2C_LCD.o ./Librerias\ LCD_I2C/I2C_LCD.su ./Librerias\ LCD_I2C/I2C_LCD_cfg.cyclo ./Librerias\ LCD_I2C/I2C_LCD_cfg.d ./Librerias\ LCD_I2C/I2C_LCD_cfg.o ./Librerias\ LCD_I2C/I2C_LCD_cfg.su ./Librerias\ LCD_I2C/Util.cyclo ./Librerias\ LCD_I2C/Util.d ./Librerias\ LCD_I2C/Util.o ./Librerias\ LCD_I2C/Util.su

.PHONY: clean-Librerias-20-LCD_I2C

