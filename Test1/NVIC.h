#ifndef NVIC_H
#define NVIC_H
#include <stdint.h>

#define NVIC_prioritiyPtr ((volatile unsigned int *)0xE000E400)

void NVIC_voidDisable(uint32_t copyBitnumber);
void NVIC_voidEnable(uint32_t copyBitnumber);

void NVIC_voidPriorityLevel(uint32_t copybitNumber, uint8_t copyPriorityValue);

#endif /compilation guard to avoid double decleration/
