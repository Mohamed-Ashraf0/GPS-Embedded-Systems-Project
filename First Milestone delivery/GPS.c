#include "GPS.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "TM4C123.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "DIO.h"
#include "arrtofloat.h"

char ch = 'A'; 
char Valid ;
char Lat[15];
char NorS;
char longi[15];
char EorW;
char GPS_logName[10];
double currentLat=0 ,currentLong=0 ,speed=0;
double deltaLat;
double deltaLong;
double a;
double c ;
double distance;

double to_degree(double angle) 
{
   short degree = angle / 100;
   float minuite = angle - degree * 100.0;
   return degree + minuite / 60.0;
}
double to_radian(double angle)
{
   return angle * (3.14159265358979323846 / 180.0);
}
double computeDistance(double currentlat, currentlong, previouslat, previouslong)
{
   currentlat = to_radian(to_degree(currentlat));
   currentlong = to_radian(to_degree(currentlong));
   previouslat = to_radian(to_degree(previouslat));
   previouslong = to_radian(to_degree(previouslong));
   deltaLat = (previouslat) - (currentlat);
    deltaLong = previouslong - currentlong;
    a = pow(sin(deltaLat / 2), 2) + cos(currentlat) * cos(previouslat) * pow(sin(deltaLong / 2), 2);
   c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = (6371000 * c);
   return distance;
}

void GPS_read (){
	char recivedvalue[70];
	char flag=0;
	currentLat=0;
	currentLong=0; 
	  while(1){
        flag=1;
	flag =	UART_receiveString(recivedvalue,UART2);
  if (flag){
		char *token;
       token = strtok(recivedvalue, ",");
    if ((strcmp(token,"$GPRMC"))){continue;}
	    token = strtok(NULL, ","); //skip date
    token = strtok(NULL, ",");
    if ((strcmp(token,&ch))){continue;}
    token = strtok(NULL, ",");
     if (token != NULL){
        strcpy(Lat,token);
     }
     token = strtok(NULL, ",");
   if (token != NULL){
        NorS = *token;
     }
     token = strtok(NULL, ",");

     if (token != NULL){
        strcpy(longi,token);
     }
      token = strtok(NULL, ",");
     if (token != NULL){
        EorW = *token;
     }
     token = strtok(NULL, ",");
     speed = strtofloat(token);
     if(speed==0.0){continue;}
     currentLat = strtofloat(Lat);
    currentLong = strtofloat(longi);
    if(currentLat>0 && currentLong>0){break;}
     }
  }
}
