//
// Created by Seif Ehab on 07/05/2024.
//

#ifndef EEPROM_H
#define EEPROM_H

#include "TM4C123.h"
#include <stdint.h>

void voidDelay_n(uint8_t delay);
void void_EEPROM_Init();
void _EEPROM_isReady();
void void_EEPROM_write(uint32_t data, uint8_t addr, uint8_t blk);
uint32_t u32_EEPROM_read(uint8_t addr,uint8_t blk);


#endif //EEPROM_H