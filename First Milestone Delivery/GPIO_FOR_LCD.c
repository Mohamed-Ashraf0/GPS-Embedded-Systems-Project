/*
name : mohammed khalid mohamed
id : 2101103
*/
#include <stdint.h>
#include"Bit_Utilies.h"
#include "TM4C123.h"

void GPIO_initPortA_LCD(){
    SET_BIT(SYSCTL_RCGCGPIO_R,0);
    while(GET_BIT(SYSCTL_PRGPIO_R,0)==0);
    GPIO_PORTA_LOCK_R=GPIO_LOCK_KEY;
    SET(GPIO_PORTA_CR_R,0xFF);
    GPIO_PORTA_AMSEL_R=0x0;
    SET(GPIO_PORTA_DIR_R,0xE0);
    SET(GPIO_PORTA_DEN_R,0xE0);
}
void GPIO_initPortB_LCD(){
    SET_BIT(SYSCTL_RCGCGPIO_R,1);
    while(GET_BIT(SYSCTL_PRGPIO_R,1)==0);
    GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
    SET(GPIO_PORTB_CR_R,0xFF);
    CLR(GPIO_PORTB_AMSEL_R,0xF);
    SET(GPIO_PORTB_DIR_R,0x13); 
    SET(GPIO_PORTB_DEN_R,0x13);}

void GPIO_initPortD_LCD(){

SET_BIT(SYSCTL_RCGCGPIO_R,3); // BIT 3
while(GET_BIT(SYSCTL_PRGPIO_R,3)== 0);
GPIO_PORTD_LOCK_R= GPIO_LOCK_KEY;
SET(GPIO_PORTD_CR_R,0xFF);
CLR(GPIO_PORTD_AMSEL_R,0x0); // Disable Analog
SET(GPIO_PORTD_DIR_R,0x07); // PD OutPut
SET(GPIO_PORTD_DEN_R,0x07); // Enable digital

}
void GPIO_initPortE_LCD(){
    SET_BIT(SYSCTL_RCGCGPIO_R,4);
    while(GET_BIT(SYSCTL_PRGPIO_R,4)==0);
    GPIO_PORTE_LOCK_R=GPIO_LOCK_KEY;
    SET(GPIO_PORTE_CR_R,0xFF);
    CLR(GPIO_PORTE_AMSEL_R,0x0);
    SET(GPIO_PORTE_DIR_R,0x30); 
    SET(GPIO_PORTE_DEN_R,0x30);
}
void GPIO_initPortF_LCD(){

SET_BIT(SYSCTL_RCGCGPIO_R,5); // BIT 5
while(GET_BIT(SYSCTL_PRGPIO_R,5)== 0);
GPIO_PORTF_LOCK_R= GPIO_LOCK_KEY;
SET(GPIO_PORTF_CR_R ,0x1F);    
SET(GPIO_PORTF_PUR_R,0x11);
CLR(GPIO_PORTF_AMSEL_R,0xF); // Disable Analog
SET(GPIO_PORTF_DIR_R,0x0E); // PF OutPut PF1 ~ PF3 & PF Input PF0 - PF4
SET(GPIO_PORTF_DEN_R,0x1F);

}
