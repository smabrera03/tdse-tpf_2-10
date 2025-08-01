#ifndef EEPROM_H
#define EEPROM_H

#include "stm32f1xx_hal.h"  // Ajustá esto si usás otra familia STM32

// Definiciones de I2C y dirección de EEPROM
extern I2C_HandleTypeDef hi2c1;
#define EEPROM_I2C &hi2c1
#define EEPROM_ADDR 0xA0

// Tamaño de página y cantidad total de páginas
#define PAGE_SIZE 64
#define PAGE_NUM  512

// Declaraciones de funciones
void EEPROM_Write(uint16_t page, uint16_t offset, uint8_t *data, uint16_t size);
void EEPROM_Read(uint16_t page, uint16_t offset, uint8_t *data, uint16_t size);
void EEPROM_PageErase(uint16_t page);

// Declaración opcional si bytestowrite está definida externamente
uint16_t bytestowrite(uint16_t size, uint16_t offset);  // Si está definida en otro archivo .c

#endif // EEPROM_H
