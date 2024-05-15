//
// Created by Seif Ehab on 08/05/2024.
//

#include "eeprom_ctrl.h"

void _EEPROM_writeFromGPS(uint32_t data) {
    static uint8_t wordAdder = 0;
    static uint8_t blkAdder = 0;
    if(wordAdder == 16) {
        blkAdder++;
        wordAdder = 0;
    }
    if(blkAdder == 32) {
        wordAdder = 0;
        blkAdder = 0;
    }
    void_EEPROM_write(data,wordAdder,blkAdder);
    wordAdder++;
}

uint32_t _EEPROM_read2PC() {
    uint32_t data = 0;
    static uint8_t wordAdder = 0;
    static uint8_t blkAdder = 0;
    if(wordAdder == 16) {
        blkAdder++;
        wordAdder = 0;
    }
    if(blkAdder == 32) {
        wordAdder = 0;
        blkAdder = 0;
    }
    data = u32_EEPROM_read(wordAdder,blkAdder);
    wordAdder++;
    return data;
}