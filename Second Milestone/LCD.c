#include "TM4C123.h"
#include "Bit_Utilies.h"
#include "LCD.h"

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

void LCD_Data (char data){
Print_Data(data);                            //pass the 8-BITS data to the data lines of LCD
CLR_BIT(GPIO_PORTD_DATA_R,1);                //Turn off the R/W for the write operation in LCD
SET_BIT(GPIO_PORTD_DATA_R,0);                //Turn on the RS for writing to data register of LCD 	
SET_BIT(GPIO_PORTD_DATA_R,2);                //Turn on the EN of LCD for enabling the clock of lcd
myDelay (10000);                      				//wait for sometime 
CLR_BIT(GPIO_PORTD_DATA_R,2);                //Turn off the EN of LCD
}
void LCD_CMD (char data){
Print_Data(data);                            //pass the 8-BITS data to the data lines of LCD
CLR_BIT(GPIO_PORTD_DATA_R,1);                //Turn off the R/W for the write operation in LCD
CLR_BIT(GPIO_PORTD_DATA_R,0);                //Turn OFF the RS for writing to command register of LCD 	
SET_BIT(GPIO_PORTD_DATA_R,2);                //Turn on the EN of LCD for enabling the clock of lcd
myDelay(10000);                              //wait for sometime 
CLR_BIT(GPIO_PORTD_DATA_R,2);                //Turn off the EN of LCD
}

void Print_Data(char data){
if ((data & 0x01) == 0x01){SET_BIT(GPIO_PORTA_DATA_R,7);}
else {CLR_BIT(GPIO_PORTA_DATA_R,7);}

if ((data & 0x02) == 0x02){SET_BIT(GPIO_PORTA_DATA_R,6);}
else {CLR_BIT(GPIO_PORTA_DATA_R,6);}

if ((data&0x04) == 0x04){SET_BIT(GPIO_PORTA_DATA_R,5);}
else {CLR_BIT(GPIO_PORTA_DATA_R,5);}

if ((data&0x08) == 0x08){SET_BIT(GPIO_PORTB_DATA_R,4);}
else {CLR_BIT(GPIO_PORTB_DATA_R,4);}

if ((data&0x10) == 0x10){SET_BIT(GPIO_PORTE_DATA_R,5);}
else {CLR_BIT(GPIO_PORTE_DATA_R,5);}

if ( (data& 0x20) == 0x20){SET_BIT(GPIO_PORTE_DATA_R,4);}
else {CLR_BIT(GPIO_PORTE_DATA_R,4);}

if ( (data & 0x40) == 0x40){SET_BIT(GPIO_PORTB_DATA_R,1);}
else {CLR_BIT(GPIO_PORTB_DATA_R,1);}

if ((data&0x80) == 0x80){SET_BIT(GPIO_PORTB_DATA_R,0);}
else {CLR_BIT(GPIO_PORTB_DATA_R,0);}
}
void LCD_String_First_line (char* str ,char len){
    char i ;
    for( i =0 ;i<len;++i){LCD_Data(str[i]);}
					
}
void LCD_String_Second_line (char* str , char len){
	char i ;								
	for ( i = 0; i<len ; ++i){LCD_Data(str[i]);}
}


void LCD_Init (void){
LCD_CMD(0x38);        //8-BIT mode utilising 16 columns 2 rows
LCD_CMD(0x06);        //auto incrementing the cursor when it 	prints data in current line
LCD_CMD(0x0C);        //cursor off and display on 
LCD_CMD(0x01);        // clear 	screen 
}
void myDelay(long d){
	long i;
for(i=0;i<d;++i);
}
