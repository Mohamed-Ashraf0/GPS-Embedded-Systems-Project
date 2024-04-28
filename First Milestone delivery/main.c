#include "GPS.h"
#include "TM4C123.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "SYSTICK.h"
#include <string.h>
#include "Bit_Utilies.h"
#include "DIO.h"
#include <float.h>

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
int main(){
	int flag1=0;
	GPIOF_Init();	
	//UART2_init();
	MCAL_UART_Init(U2); 
	while(totalDistance<100){
	GPS_read ();
	
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
