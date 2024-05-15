#include "UART_config.h"
#include "Bit_Utilies.h"
#include <stdint.h>
#include <string.h>

#include "TM4C123.h"
char x;
char y;
void uint8_UART_config (UART_config_t * uartConfigNum) {
    CLR_BIT((uartConfigNum -> CTL) , 0);

    /* setting up baud rate to 9600 */
    (uartConfigNum -> IBRD) = 0x68;
    (uartConfigNum -> FBRD) = 0x0B;

    uartConfigNum -> LCRH = 0x00000070; /* 8bit, no parity bits,one stop, fifo */
    SET(uartConfigNum ->CTL, 0x00000301); /* setting up enable ,tx and rx */
}


uint8_t struct_UART_recieveByte(UART_config_t * uartConfigNum) {
    while(uartConfigNum ->FR & UART_FR_RXFE){}
			x=(uint8_t)(uartConfigNum->DR & 0xFF);
    return x;
}

void void_UART_sendByte(uint8_t data, UART_config_t * uartConfigNum) {
    while(uartConfigNum ->FR & UART_FR_TXFF){}
			y=data;
    (uartConfigNum -> DR) = data;
}

int8_t UART_receiveString(char *Str, UART_config_t * uartConfigNum)
{
    uint8_t i = 0;
    Str[i] =  struct_UART_recieveByte(uartConfigNum);
    if(Str[i]!='$'){return 0;}
    while(Str[i] !=  '*')
    {
        i++;
        Str[i] =  struct_UART_recieveByte(uartConfigNum);
    }
    Str[i] = '\0';
    return 1;
}
/* break character is used to identify each string sepratly ex: '\n' */
void UART_sendString(char* str, uint8_t breakChar, UART_config_t * uartConfigNum)
{
    uint8_t counter = 0;
    for(counter = 0; counter < strlen(str); counter ++) {
        void_UART_sendByte(str[counter], uartConfigNum);
    }
    void_UART_sendByte(breakChar, uartConfigNum);
}
