#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/*
 * UART 3,4 will not be implemented since they are on port c were
 * the jtag is present which is very sensitive to errors won't be able to test
 * without damaging the board
*/
#include <stdint.h>

#define U0 0
#define U1 1
#define U2 2

#define U5 5
#define U6 6
#define U7 7

#define U0RX 0
#define U0TX 1

#define U1RX 0
#define U1TX 1

#define U2RX 6
#define U2TX 7

#define U5RX 4
#define U5TX 5

#define U6RX 4
#define U6TX 5

#define U7RX 0
#define U7TX 1
void MCAL_UART_Init (uint8_t uartNum);


#endif //UART_INTERFACE_H
