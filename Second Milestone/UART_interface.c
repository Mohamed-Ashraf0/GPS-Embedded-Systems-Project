#include "UART_interface.h"
#include "UART_config.h"
#include "TM4C123.h"
#include "Bit_Utilies.h"

void MCAL_UART_Init (uint8_t uartNum){
    if((uartNum == 3) || (uartNum == 4)) {
        return;
    }
    switch (uartNum) {
        case 0:
            SET_BIT(SYSCTL_RCGCUART_R,U0);
            SET_BIT(SYSCTL_RCGCGPIO_R,0);

            uint8_UART_config(UART0);
            SET_BIT(GPIO_PORTA_DEN_R, U0RX);
            SET_BIT(GPIO_PORTA_DEN_R, U0TX);

            SET_BIT(GPIO_PORTA_AFSEL_R,U0RX);
            SET_BIT(GPIO_PORTA_AFSEL_R,U0TX);

            CLR_BIT(GPIO_PORTA_AMSEL_R,U0RX);
            CLR_BIT(GPIO_PORTA_AMSEL_R,U0TX);

            GPIO_PORTA_PCTL_R = GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX;
            break;

        case 1:
            SET_BIT(SYSCTL_RCGCUART_R,U1);
            SET_BIT(SYSCTL_RCGCGPIO_R,1);

            uint8_UART_config(UART1);
            SET_BIT(GPIO_PORTB_DEN_R, U1RX);
            SET_BIT(GPIO_PORTB_DEN_R, U1TX);

            SET_BIT(GPIO_PORTB_AFSEL_R,U1RX);
            SET_BIT(GPIO_PORTB_AFSEL_R,U1TX);

            CLR_BIT(GPIO_PORTB_AMSEL_R,U1RX);
            CLR_BIT(GPIO_PORTB_AMSEL_R,U1TX);

            GPIO_PORTB_PCTL_R = GPIO_PCTL_PB1_U1TX|GPIO_PCTL_PB0_U1RX;
            break;
        case 2:
            SET_BIT(SYSCTL_RCGCUART_R,U2);
            SET_BIT(SYSCTL_RCGCGPIO_R,3);

            uint8_UART_config(UART2);
            SET_BIT(GPIO_PORTD_DEN_R, U2RX);
            SET_BIT(GPIO_PORTD_DEN_R, U2TX);

            SET_BIT(GPIO_PORTD_AFSEL_R,U2RX);
            SET_BIT(GPIO_PORTD_AFSEL_R,U2TX);

            CLR_BIT(GPIO_PORTD_AMSEL_R,U2RX);
            CLR_BIT(GPIO_PORTD_AMSEL_R,U2TX);

            GPIO_PORTD_PCTL_R  |= GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX ;
            break;
        case 5:
            SET_BIT(SYSCTL_RCGCUART_R,U5);
            SET_BIT(SYSCTL_RCGCGPIO_R,4);

            uint8_UART_config(UART5);
            SET_BIT(GPIO_PORTE_DEN_R, U5RX);
            SET_BIT(GPIO_PORTE_DEN_R, U5TX);

            SET_BIT(GPIO_PORTE_AFSEL_R,U5RX);
            SET_BIT(GPIO_PORTE_AFSEL_R,U5TX);

            CLR_BIT(GPIO_PORTE_AMSEL_R,U5RX);
            CLR_BIT(GPIO_PORTE_AMSEL_R,U5TX);

            GPIO_PORTE_PCTL_R  |= GPIO_PCTL_PE4_U5RX | GPIO_PCTL_PE5_U5TX ;
            break;
        case 6:
            SET_BIT(SYSCTL_RCGCUART_R,U6);
            SET_BIT(SYSCTL_RCGCGPIO_R,3);

            uint8_UART_config(UART6);
            SET_BIT(GPIO_PORTD_DEN_R, U6RX);
            SET_BIT(GPIO_PORTD_DEN_R, U6TX);

            SET_BIT(GPIO_PORTD_AFSEL_R,U6RX);
            SET_BIT(GPIO_PORTD_AFSEL_R,U6TX);

            CLR_BIT(GPIO_PORTD_AMSEL_R,U6RX);
            CLR_BIT(GPIO_PORTD_AMSEL_R,U6TX);

            GPIO_PORTD_PCTL_R  |= GPIO_PCTL_PD4_U6RX | GPIO_PCTL_PD5_U6TX ;
            break;
        case 7:
            SET_BIT(SYSCTL_RCGCUART_R,U7);
            SET_BIT(SYSCTL_RCGCGPIO_R,4);

            uint8_UART_config(UART7);
            SET_BIT(GPIO_PORTE_DEN_R, U7RX);
            SET_BIT(GPIO_PORTE_DEN_R, U7TX);

            SET_BIT(GPIO_PORTE_AFSEL_R,U7RX);
            SET_BIT(GPIO_PORTE_AFSEL_R,U7TX);

            CLR_BIT(GPIO_PORTE_AMSEL_R,U7RX);
            CLR_BIT(GPIO_PORTE_AMSEL_R,U7TX);

            GPIO_PORTE_PCTL_R  |= GPIO_PCTL_PE0_U7RX | GPIO_PCTL_PE1_U7TX ;
            break;
        default:
            break;
    }
}
