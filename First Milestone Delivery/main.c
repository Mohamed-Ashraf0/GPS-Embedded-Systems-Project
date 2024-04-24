#include "GPS.h"
#include "TM4C123.h"
#include "UART.h"
#include "SYSTICK.h"
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
	UART2_init(); 
	while(totalDistance<100){
	GPS_read ();
	PreviousLong=currentLat;
  PrivousLat=currentLat;
   if(flag1){
  Distance=GPS_getDistance( currentLat,currentLong,PrivousLat, PreviousLong);
  totalDistance+=Distance;
  }
	 flag1=1;
   }
	strcpy(check,finish);
	   greenon();	
	 while(1);
	}
