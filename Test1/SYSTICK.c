#include "TM4C123.h"
#include "SysTick.h"

void SYSTICK_Init(void){
	NVIC_ST_CTRL_R=0;
	NVIC_ST_RELOAD_R=0X00FFFFFF;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=0X05;	
}
void SYSTICK_WAIT(uint32_t delay){
	NVIC_ST_RELOAD_R=delay-1;
	NVIC_ST_CURRENT_R=0;
	while((NVIC_ST_CTRL_R&0x00010000)==0){
	}
}
void SysTick_Wait10ms(uint32_t delay){
unsigned long i;
for(i=0; i<delay; i++){
SYSTICK_WAIT(800000); // wait 10ms
}
}

