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
#include <stdio.h>

extern char Valid ;
extern char Lat[15];
extern char NorS;
extern char longi[15];
extern char EorW;
extern double currentLong ,currentLat ,speed ;
double PreviousLong , PrivousLat;
double Distance = 0 , totalDistance =0; 
 char check[]="unreached";
 char finish[]="reached";
char Total_distance_message[]=" Total distance  ";
char  message[6] ;
void SystemInit(){}
int main(){
	int flag1=0;
	enableClock(F);	
	enableLEDs();
	MCAL_UART_Init(U2);
    GPIO_LCD_init();
    SW();
    LCD_Init();
	while(totalDistance<100){
	GPS_read ();
        //SW2 ON and SW1 OFF ----> print longitude
        if((GET_BIT(GPIO_PORTF_DATA_R,0)==0 )&& (GET_BIT(GPIO_PORTF_DATA_R,3)==1)) {
            sprintf(message, "    %0.2f    ", PreviousLong);
            LCD_CMD(0x80);
            LCD_String_First_line("    Longitude   ",16);
            LCD_CMD(0xC0);
            LCD_String_Second_line(message, 15);
        }
            //SW2 OFF and SW1 ON ----> print latitude
        else if((GET_BIT(GPIO_PORTF_DATA_R,0)==1 )&& (GET_BIT(GPIO_PORTF_DATA_R,3)==0)){
            sprintf(message,"    %0.2f    ",PrivousLat);
            LCD_CMD(0x80);
            LCD_String_First_line("    Latitude    ", 16);
            LCD_CMD(0xC0);
            LCD_String_Second_line(message,15);
        }
        else {
            sprintf(message,"    %0.2f    ",totalDistance);
            LCD_CMD(0x80);
            LCD_String_First_line(Total_distance_message, sizeof(Total_distance_message) - 1);
            LCD_CMD(0xC0);
            LCD_String_Second_line(message, 15);
        }
    if(flag1){
  Distance=computeDistance( currentLat,currentLong,PrivousLat, PreviousLong);
  totalDistance+=Distance;
  }
   PreviousLong=currentLong;
  PrivousLat=currentLat;

	 flag1=1;
   }
	strcpy(check,finish);
	   greenON();	
	 while(1);
	}
