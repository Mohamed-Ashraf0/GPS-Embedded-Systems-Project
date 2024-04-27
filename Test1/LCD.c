/*
  name :Mohammed khaled mohamed 
  id: 2101103
*/
#include "TM4C123.h"
#include "Bit_Utilies.h"
#include<stdint.h>
#include "LCD.h"
#include"SysTick.h"
#include<string.h>

//RS = PD0
//RW = PD1
//EN = PD2

// D0 = PA7
// D1 = PA6
// D2 = PA5
// D3 = PB4
// D4 = PE5
// D5 = PE4
// D6 = PB1
// D7 = PB0

void LCD_Data (uint8_t data){
Print_Data(data);                            //pass the 8-BITS data to the data lines of LCD
CLR_BIT(GPIO_PORTD_DATA_R,1);                //Turn off the R/W for the write operation in LCD
SET_BIT(GPIO_PORTD_DATA_R,0);                //Turn on the RS for writing to data register of LCD 	
SET_BIT(GPIO_PORTD_DATA_R,2);                //Turn on the EN of LCD for enabling the clock of lcd
SysTick_Wait1ms(350);                      //wait for sometime 
CLR_BIT(GPIO_PORTD_DATA_R,2);                //Turn off the EN of LCD
}
void LCD_CMD (uint8_t data){
Print_Data(data);                            //pass the 8-BITS data to the data lines of LCD
CLR_BIT(GPIO_PORTD_DATA_R,1);                //Turn off the R/W for the write operation in LCD
SET_BIT(GPIO_PORTD_DATA_R,0);                //Turn OFF the RS for writing to command register of LCD 	
SET_BIT(GPIO_PORTD_DATA_R,2);                //Turn on the EN of LCD for enabling the clock of lcd
SysTick_Wait1ms(350);                      //wait for sometime 
CLR_BIT(GPIO_PORTD_DATA_R,2);                //Turn off the EN of LCD
}

void Print_Data(uint8_t data){
if (GET_BIT(data,0) == 1){SET_BIT(GPIO_PORTA_DATA_R,PA7);}
else {CLR_BIT(GPIO_PORTA_DATA_R,PA7);}

if (GET_BIT(data,1) == 1){SET_BIT(GPIO_PORTA_DATA_R,PA6);}
else {CLR_BIT(GPIO_PORTA_DATA_R,PA6);}

if (GET_BIT(data,2) == 1){SET_BIT(GPIO_PORTA_DATA_R,PA5);}
else {CLR_BIT(GPIO_PORTA_DATA_R,PA5);}

if (GET_BIT(data,3) == 1){SET_BIT(GPIO_PORTB_DATA_R,PB4);}
else {CLR_BIT(GPIO_PORTA_DATA_R,PB4);}

if (GET_BIT(data,4) == 1){SET_BIT(GPIO_PORTE_DATA_R,PE5);}
else {CLR_BIT(GPIO_PORTA_DATA_R,PE5);}

if (GET_BIT(data,5) == 1){SET_BIT(GPIO_PORTE_DATA_R,PE4);}
else {CLR_BIT(GPIO_PORTA_DATA_R,PE4);}

if (GET_BIT(data,6) == 1){SET_BIT(GPIO_PORTB_DATA_R,PB1);}
else {CLR_BIT(GPIO_PORTA_DATA_R,PB1);}

if (GET_BIT(data,7) == 1){SET_BIT(GPIO_PORTB_DATA_R,PB0);}
else {CLR_BIT(GPIO_PORTA_DATA_R,PB0);}
}
void LCD_String_First_line (char* str , uint8_t len){
					char i ;			
	for ( i = 0; i<len ; ++i){
										LCD_CMD(0x80);
									  LCD_Data(str[i]);
									}
}
void LCD_String_Second_line (char* str , uint8_t len){
	char i ;								
	for ( i = 0; i<len ; ++i){
										LCD_CMD(0xC0);
									  LCD_Data(str[i]);
									}
}


void LCD_Init (void){
LCD_CMD(0x38);        //8-BIT mode utilising 16 coloumns 2 rows
LCD_CMD(0x06);        //auto incrementing the cursor when it 	prints data in current line
LCD_CMD(0x0C);        //cursor off and display on 
LCD_CMD(0x01);        // clear 	screen 
}
