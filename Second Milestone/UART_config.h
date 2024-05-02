#ifndef UART_CONFIG_H
#define UART_CONFIG_H
#include <stdint.h>

typedef struct {
    volatile uint32_t  DR; /* UART DATA recieve */
    volatile uint32_t ERROR_RX_TX;
    volatile const  uint32_t  RESERVED[4];
    volatile uint32_t  FR; /* UART Flag */
    volatile const  uint32_t  RESERVED1;
    volatile uint32_t  ILPR;
    volatile uint32_t  IBRD;                              /* UART Integer Baud-Rate Divisor */
    volatile uint32_t  FBRD;                              /* UART Fractional Baud-Rate Divisor */
    volatile uint32_t  LCRH;                              /* UART Line Control */
    volatile uint32_t  CTL;                               /* UART control */
}UART_config_t;

#define UART0_CONFIG                      0x4000C000UL
#define UART1_CONFIG                      0x4000D000UL
#define UART2_CONFIG                      0x4000E000UL
#define UART3_CONFIG                      0x4000F000UL
#define UART4_CONFIG                      0x40010000UL
#define UART5_CONFIG                      0x40011000UL
#define UART6_CONFIG                      0x40012000UL
#define UART7_CONFIG                      0x40013000UL

#define UART0                   ((UART_config_t              *) UART0_CONFIG)
#define UART1                   ((UART_config_t              *) UART1_CONFIG)
#define UART2                   ((UART_config_t              *) UART2_CONFIG)
#define UART3                   ((UART_config_t              *) UART3_CONFIG)
#define UART4                   ((UART_config_t              *) UART4_CONFIG)
#define UART5                   ((UART_config_t              *) UART5_CONFIG)
#define UART6                   ((UART_config_t              *) UART6_CONFIG)
#define UART7                   ((UART_config_t              *) UART7_CONFIG)

void uint8_UART_config (UART_config_t * uartNumber);
uint8_t struct_UART_recieveByte(UART_config_t * uartConfigNum);
int8_t UART_receiveString(char *Str, UART_config_t * uartConfigNum);



#endif //UART_CONFIG_H
