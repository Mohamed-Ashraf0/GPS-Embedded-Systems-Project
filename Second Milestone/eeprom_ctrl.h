//
// Created by Seif Ehab on 08/05/2024.
//

#ifndef EEPROM_CTRL_H
#define EEPROM_CTRL_H

#include "eeprom.h"
#include "TM4C123.h"
#include <stdint.h>

void _EEPROM_writeFromGPS(uint32_t data);
uint32_t _EEPROM_read2PC();

#endif //EEPROM_CTRL_H
