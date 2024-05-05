#include "TM4C123.h"
#include "DIO.h"

void enableClock(type port){//A to F

		SYSCTL_RCGCGPIO_R |= port;
    while((SYSCTL_PRGPIO_R & port) == 0);//

}

void enableLEDs(){

    GPIO_PORTF_PCTL_R   &= ~0xFFF0;//GPIO mode
    GPIO_PORTF_CR_R     |=  0x0E;//commit register
    GPIO_PORTF_AMSEL_R  &= ~0x0E;//disable analog
    GPIO_PORTF_DEN_R    |=  0x0E;//digital enable
    GPIO_PORTF_DIR_R    |=  0x0E;//direction = out


}
void ledOFF(){
    GPIO_PORTF_DATA_R &= ~0xE;
}
void greenON(){
    ledOFF();
    GPIO_PORTF_DATA_R |= 0x8;
}
void blueON(){
    ledOFF();
    GPIO_PORTF_DATA_R |= 0x4;
}
void redON(){
    ledOFF();
    GPIO_PORTF_DATA_R |= 0x2;
}
void SW(){

    GPIO_PORTF_PCTL_R   &= ~0xF000F;//GPIO mode
    GPIO_PORTF_CR_R     |=  0x11;//commit register
    GPIO_PORTF_AMSEL_R  &= ~0x11;//disable analog
    GPIO_PORTF_DEN_R    |=  0x11;//digital enable
    GPIO_PORTF_DIR_R    &= ~0x11;//direction = in
    GPIO_PORTF_PUR_R    |=  0x11;//enable Pull-Up resistors;

}
