#include <stdint.h>
#include "TM4C123.h"
#include "NVIC.h"
/*
    Peripheral Enable
*/

void NVIC_voidEnable(uint32_t copyBitnumber) {
    
    if(copyBitnumber <= 31){
        NVIC_EN0_R = (1 << copyBitnumber);
    }
    else if(copyBitnumber <= 63){
        copyBitnumber -=32;
        NVIC_EN1_R = (1<<copyBitnumber);
    }
    else{
        /* Rest of bits Manpulation later */
    }
    
}

void NVIC_voidDisable(uint32_t copyBitnumber) {
    
    if(copyBitnumber <= 31){
        NVIC_DIS0_R = (1 << copyBitnumber);
    }
    else if(copyBitnumber <= 63){
        copyBitnumber -=32;
        NVIC_DIS1_R = (1 << copyBitnumber);
    }
    else{
        /* Rest of bits Manpulation later */
    } 
}

void NVIC_voidPriorityLevel(uint32_t copybitNumber, uint8_t copyPriorityValue) {
	
	if(copyPriorityValue <= 7 ){
		if(copyPriorityValue == 0){
			NVIC_prioritiyPtr[copybitNumber/4] &= (~( 1 << (5 + (copybitNumber % 4)*8)));
		}
		else{
			NVIC_prioritiyPtr[copybitNumber/4] |= copyPriorityValue << (5 + (copybitNumber % 4)*8);
		}
	}
	else{
		//Error handler
	}
}
