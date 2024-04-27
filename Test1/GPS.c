#include "GPS.h"
#include "uart.h"
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

double degToRad(double degree) {
    return degree * (3.14159265358979323846 / 180.0);
}

double GPS_getDistance(double currentLat,double currentLong,double previousLat,double previousLong){
    double lat1 = degToRad(currentLat);
    double long1 = degToRad(currentLong);
    double lat2 = degToRad(previousLat);
    double long2 = degToRad(previousLong);
    double latdiff = lat2 - lat1;
    double longdiff = long2 - long1;

    double a= pow(sin(latdiff/2),2)+cos(lat1)*cos(lat2)*pow(sin(longdiff/2),2); // Haversine formula: a = sin²(?f/2) + cos f1 · cos f2 · sin²(??/2)
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371000*c;   //in meters
}

void GPS_read (){
	char recivedvalue[70];
	char flag=0;
	currentLat=0;
	currentLong=0; 
	  while(1){
        flag=1;
   flag=UART2_receiveString( recivedvalue );
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

