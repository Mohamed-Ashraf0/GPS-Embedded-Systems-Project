//
// Created by Seif Ehab on 07/05/2024.
//
#include "eeprom.h"

void void_EEPROM_Init() {
    int8_t flag = 0;
    SYSCTL_RCGCEEPROM_R = SYSCTL_RCGCEEPROM_R0;
    voidDelay_n(6); // 6 cycles + overhead for safety

    _EEPROM_isReady();
    /* if any of eesupp bits are set these means a fatal error has occured and the data written after
       might be lost and can't be recovered */
    if((EEPROM_EESUPP_R & (EEPROM_EESUPP_ERETRY | EEPROM_EESUPP_PRETRY)) == 1) {
        flag = -1;
    }else{}

    SYSCTL_SREEPROM_R |= SYSCTL_SREEPROM_R0; // resetting eeprom to make sure its empty
    //while(SYSCTL_PREEPROM_R == 0){} // making sure resetting takes its full time
    voidDelay_n(6);

    SYSCTL_SREEPROM_R = 0; // disabling software resetting
    voidDelay_n(6);

    _EEPROM_isReady();

    if((EEPROM_EESUPP_R & (EEPROM_EESUPP_ERETRY | EEPROM_EESUPP_PRETRY)) == 1) {
        flag = -1 ;
    }else{}

    if(flag == -1) {
        EEPROM_EESUPP_R |= EEPROM_EESUPP_START;
        _EEPROM_isReady();
    }
}

void void_EEPROM_write(uint32_t data, uint8_t addr, uint8_t blk) {
     EEPROM_EEBLOCK_R = blk;//Block number
	 EEPROM_EEOFFSET_R =  addr; //offset within the block
	 EEPROM_EERDWR_R = data; //data written
    _EEPROM_isReady();
}

uint32_t u32_EEPROM_read(uint8_t addr,uint8_t blk) {
    uint32_t data;
	EEPROM_EEBLOCK_R = blk;//Block number
	EEPROM_EEOFFSET_R =  addr;
    data = EEPROM_EERDWR_R;
    _EEPROM_isReady();
    return data;
}


void voidDelay_n(uint8_t delay) {
    // for an 80MHz device delay in for loop is 80000 counter no need for accurate implementation
    uint8_t counter = 0;
    for (counter = 0; counter < delay; counter++){}
}

void _EEPROM_isReady() {
    while((EEPROM_EEDONE_R & EEPROM_EEDONE_WORKING) != 0){} // making sure eeprom is fully working and ready
}