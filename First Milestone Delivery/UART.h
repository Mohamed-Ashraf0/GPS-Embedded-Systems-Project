#ifndef UART_H
#define UART_H
#include <stdint.h>
#define BAUD_9600_RATE_INT (int)((16*1000000)/(9600*16))
#define BAUD_9600_RATE_DIV (int)((BAUD_9600_RATE_INT - (int)(BAUD_9600_RATE_INT))*64 + 0.5)
//#define CHAR_noPARITY_STP1 0x00000070

void UART2_Init();
char UART2_recieveByte(void);
int UART2_receiveString(char *Str );

#endif
