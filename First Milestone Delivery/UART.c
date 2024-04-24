
#include <stdint.h>
#include "TM4C123.h"
#include "UART.h"
#include "Bit_Utilies.h"

void UART2_Init()
{
    SET(SYSCTL_RCGCUART_R,SYSCTL_RCGC1_UART2); //Enables UART2 clk
    SET(SYSCTL_RCGCGPIO_R,SYSCTL_RCGC2_GPIOD); //Enables PORT D
    CLR_BIT(UART2_CTL_R,0); // Diable uart2 before intialization
    /* setting baudrate to 9600 */
    UART2_IBRD_R = BAUD_9600_RATE_INT;
    UART2_FBRD_R = BAUD_9600_RATE_DIV ;
    SET(UART2_LCRH_R,(UART_LCRH_WLEN_8 | UART_LCRH_FEN));
    //UART2_LCRH_R= CHAR_noPARITY_STP1;
    SET(UART2_CTL_R, 0x0301);


    /*********   digital enable  **************/
    SET_BIT(GPIO_PORTD_DEN_R,0x6);
    SET_BIT(GPIO_PORTD_DEN_R,0x7);

    /**********  enable alternate function  ***********/
    SET_BIT(GPIO_PORTD_AFSEL_R,0x6);
    SET_BIT(GPIO_PORTD_AFSEL_R,0x7);

    /************* disable analog ***********/
    CLR_BIT(GPIO_PORTD_AMSEL_R,0x6);
    CLR_BIT(GPIO_PORTD_AMSEL_R,0x7);
    /************ PCTL *************/
    /*To enable UART2 PD6 and PD7 should be
    * set to alternate function 1 as it represent
    * UART2 from datasheet of the microcontroller */
    SET(GPIO_PORTD_PCTL_R, 0x11000000);
}

char UART2_recieveByte(void)
{
    while(CHECK_REG(UART2_FR_R,UART_FR_RXFE));
    return ((uint8_t)(UART2_DR_R &= UART_DR_DATA_M));
}

int UART2_receiveString(char *Str )
{
    uint8_t i = 0;
    Str[i] =  UART2_recieveByte();
    if(Str[i]!='$'){return 0;}
    while(Str[i] !=  '*')
    {
        i++;
        Str[i] =  UART2_recieveByte();
    }
    Str[i] = '\0';
    return 1;
}
