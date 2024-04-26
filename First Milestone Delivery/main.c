#include "GPS.h"
#include "TM4C123.h"
#include "UART.h"
#include "SYSTICK.h"
#include "Bit_Utilies.h"
#include "DIO.h"
#include "GPIO_FOR_LCD.h"
#include "LCD.h"
#include <string.h>
#include <stdio.h>
#include "float.h"

extern char Valid;
extern char Lat[15];
extern char NorS;
extern char longi[15];
extern char EorW;
extern double currentLong, currentLat, speed;
double PreviousLong, PreviousLat;
double Distance = 0, totalDistance = 0;
char check[] = "unreached";
char finish[] = "reached";
void SystemInit() {}

 char Total_distance_message[] = "  Total distance in meter  ";
 char message[20];

int main() {
    GPIO_initPortA_LCD();
    GPIO_initPortB_LCD();
    GPIO_initPortD_LCD();
    GPIO_initPortE_LCD();
    GPIO_initPortF_LCD();
    SysTick_Wait1ms(500);
    LCD_Init();

    int flag1 = 0;
    GPIOF_Init();
    UART2_init();
    LCD_String_First_line(Total_distance_message, sizeof(Total_distance_message) - 1);
    LCD_String_Second_line(" Zero ", 6);

    while (totalDistance < 100) {
        GPS_read();
        PreviousLong = currentLong;
        PreviousLat = currentLat;

         char long_message[25];
         char lati_message[25];

        sprintf(long_message, "Latitude: %.6f", PreviousLat);
        sprintf(lati_message, "Longitude: %.6f", PreviousLong);

        if (flag1) {
            Distance = GPS_getDistance(currentLat, currentLong, PreviousLat, PreviousLong);
            totalDistance += Distance;

            sprintf(message, "%.2f", totalDistance); // Convert total distance to string with 2 decimal places

            if (GET_BIT(GPIO_PORTF_DATA_R, 0)) {
                LCD_String_Second_line(message, strlen(message));
            } else {
                LCD_Init();
                LCD_String_First_line(long_message, sizeof(long_message)-1);
                LCD_String_Second_line(lati_message, sizeof(lati_message)-1);
            }
        }
        flag1 = 1;
    }

    strcpy(check, finish);
    greenON();

    while (1);
}
