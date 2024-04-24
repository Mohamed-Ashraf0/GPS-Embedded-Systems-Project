/*
  Name : Abdelrahman Taha Mohamed 
  Code : 2100464
*/
#ifndef DIO.h
#define DIO.h
#include "tm4c123gh6pm.h"
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
