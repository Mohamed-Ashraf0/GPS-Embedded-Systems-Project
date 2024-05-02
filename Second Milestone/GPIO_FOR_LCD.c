/*
name : mohammed khalid mohamed
id : 2101103
*/
#include"Bit_Utilies.h"
#include "TM4C123.h"

void GPIO_LCD_init(void){
   		//initialize port A
		SET_BIT(SYSCTL_RCGCGPIO_R,0);
		while(GET_BIT(SYSCTL_PRGPIO_R,0)==0){}
		SET(GPIO_PORTA_DEN_R,0xE0);
		SET(GPIO_PORTA_DIR_R,0xE0);		
		
		//initialize port B
   		SET_BIT(SYSCTL_RCGCGPIO_R,1);
	 	while(GET_BIT(SYSCTL_PRGPIO_R,1)==0){}
    		SET(GPIO_PORTB_DEN_R,0x13);	
		SET(GPIO_PORTB_DIR_R,0x13);
		
		//initialize port D
		SET_BIT(SYSCTL_RCGCGPIO_R,3); 
	  	while(GET_BIT(SYSCTL_PRGPIO_R,3)==0){}
		SET(GPIO_PORTD_DEN_R,0x07);	
		SET(GPIO_PORTD_DIR_R,0x07);
		
		//initialize port E
    		SET_BIT(SYSCTL_RCGCGPIO_R,4);
	  	while(GET_BIT(SYSCTL_PRGPIO_R,4)==0){}
    		SET(GPIO_PORTE_DEN_R,0x30);
		SET(GPIO_PORTE_DIR_R,0x30); 
		
		
    
}
