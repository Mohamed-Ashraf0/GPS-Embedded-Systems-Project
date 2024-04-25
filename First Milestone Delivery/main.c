#include "GPS.h"
#include "TM4C123.h"
#include "UART.h"
#include "SYSTICK.h"
#include "Bit_Utilies.h"
#include "DIO.h"
#include <float.h>
#include "GPIO_FOR_LCD.h"
#include  "LCD.h"

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
void SystemInit(){}
unsigned char Total_distance_message[]="  Total distance im meter  ";
unsigned char long_message[] ;
unsigned char lati_message[] ;
unsigned char long_value[];
unsigned char lati_value[];
unsigned char message[20] ;

int main(){
 GPIO_initPortA_LCD();
 GPIO_initPortB_LCD();
 GPIO_initPortD_LCD();
 GPIO_initPortE_LCD();
 GPIO_initPortF_LCD();
 SysTick_Wait1ms(500);	
 LCD_Init ();

	int flag1=0;
	GPIOF_Init();		
	UART2_init();
	LCD_String_First_line(Total_distance_message , sizeof (Total_distance_message)-1);
        LCD_String_Second_line(" Zero ",6);
	while(totalDistance<100){
		GPS_read ();
		PreviousLong=currentLat;
	        PrivousLat=currentLat;
		sprintf(long_value, "%d", PreviousLong);
		sprintf(lati_value, "%d", PrivousLat);
		long_message[] = "Latitude in meter"+long_value;
                lati_message[] = "Longitude in meter" +lati_value;
		if(flag1){
		  Distance=GPS_getDistance( currentLat,currentLong,PrivousLat, PreviousLong);
		  totalDistance+=Distance;
		  sprintf(message, "%d", totalDistance); /*converting the total distance from double to string */
		  if (GET_BIT(GPIO_PORTF_DATA_R,0)){
                           
		  LCD_String_Second_line( message , sizeof (message)-1);
		  }
		  else if(GET_BIT(GPIO_PORTF_DATA_R,0)==0){
			  LCD_Init();
			  LCD_String_First_line( long_message ,sizeof(long_message)-1);
			  LCD_String_Second_line(lati_message,sizeof(lati_message)-1);
		  }
  }
	 flag1=1;
   }
	strcpy(check,finish);
	   greenon();	
	 while(1);
	}
