#ifndef DIO.h
#define DIO.h
#include "tm4c123gh6pm.h"

enum port {A=1,B=2,C=4,D=8,E=16,F=32};
typedef enum port type;

void enableClock(type port);
void enableLEDs();
void ledOFF();
void greenON();
void blueON();
void redON();
void SW();

#endif
