/*
  Name : Abdelrahman Taha Mohamed 
  Code : 2100464
  Section : 3 CSE
*/
#ifndef DIO_h_
#define DIO_h_
#include "TM4C123.h"
enum port {A=1,B=2,C=4,D=8,E=16,F=32};
typedef enum port type;
void enableClock(type port);
//takes values (A --> F) to enable clock for their ports
void enableLEDs();
//configure built-in LEDs to work
void ledOFF();
//turns off LEDs
void greenON();
void blueON();
void redON();
void SW();
//configures built-in switches to work

#endif
