#include "GPS.h"
#include "TM4C123.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "SYSTICK.h"
#include <string.h>
#include "Bit_Utilies.h"
#include "DIO.h"
#include <float.h>
#include "GPIO_FOR_LCD.h"
#include "LCD.h"
#include "eeprom.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "eeprom_ctrl.h"

extern char Valid ;
extern char Lat[15];
extern char NorS;
extern char longi[15];
extern char EorW;
extern double currentLong ,currentLat ,speed ;
double PreviousLong , PrivousLat;
double startLong , startLat;
char eepromread_s[15];
double Distance = 0 , totalDistance =0;
 char finish[]="    reached    ";
char Total_distance_message[]=" Total distance  ";
char  message[6] ;
uint32_t pui32Data;
void doubleToString(double num, char *str) {
    sprintf(str, "%lf", num);
}
void SystemInit(){}
int main(){
	int flag1=0;

	uint32_t pui32Read;
	int eeprom_counter_W=0;
	int eeprom_counter_R=0;
	enableClock(F);
	enableLEDs();
  MCAL_UART_Init(U2);
	MCAL_UART_Init(U7);
  GPIO_LCD_init();
   SW();

    LCD_Init();
	  SYSTICK_Init();
    void_EEPROM_Init();
	while(totalDistance<100){
	GPS_read ();

            sprintf(message,"    %0.2f    ",totalDistance);
            LCD_CMD(0x80);
            LCD_String_First_line(Total_distance_message, sizeof(Total_distance_message) - 1);
            LCD_CMD(0xC0);
            LCD_String_Second_line(message, 13);

    if(flag1){
  Distance=computeDistance( currentLat,currentLong,PrivousLat, PreviousLong);
			if(Distance){
				 pui32Data=(uint32_t)(currentLat*100000);
			 _EEPROM_writeFromGPS(pui32Data);
				eeprom_counter_W++;
				 pui32Data=(uint32_t)(currentLong*100000);
			 	_EEPROM_writeFromGPS(pui32Data);
				eeprom_counter_W++;
			}
  totalDistance+=Distance;
  }
   PreviousLong=currentLong;
  PrivousLat=currentLat;
	 flag1=1;
   }
	   greenON();
	 LCD_Init();
	 LCD_CMD(0x80);
	 LCD_String_Second_line(finish,sizeof(finish)-1);
      while((struct_UART_recieveByte(UART7)) != (uint8_t)'U');
	 for(eeprom_counter_R=0;eeprom_counter_R<eeprom_counter_W;eeprom_counter_R++){
	  pui32Read=_EEPROM_read2PC();
	 doubleToString(((double)pui32Read/10000000), eepromread_s);
	 	UART_sendString(eepromread_s,'L',UART7);

	 }
    void_UART_sendByte('E',UART7);
	 while(1);
	}
