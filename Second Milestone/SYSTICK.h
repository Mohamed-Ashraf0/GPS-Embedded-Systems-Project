#ifndef SYSTICK_H_
#define SYSTICK_H_ 
#include <stdint.h>
void SYSTICK_Init(void);
void SYSTICK_WAIT(uint32_t delay);
void SysTick_Wait10ms(uint32_t delay);
#endif
