/*
 * UART.h
 *
 * Created: 19/11/02 12:53:26 PM
 *  Author: ahmed
 */ 


#ifndef UART_H_
#define UART_H_

#include "avr/io.h"
#include "avr/interrupt.h"
#include "bit_handle.h"
#include "UART_Config.h"

typedef enum{
	RX_C,
	TX_C,
	UDR_E	
	}t_interrupt_type;

/***************initialization***************/
void UART_Init(uint16_t ubrr);
void UART_disable_tx(void);
void UART_disable_rx(void);
/***************send and receive***************/
void    UART_NoInterrupt_transmit(uint8_t data);
uint8_t	UART_NoInterrupt_receive(void);

/***************interrupt functions***************/
void	UART_Interrupt_En(t_interrupt_type interr);
void	UART_Interrupt_dis(t_interrupt_type interr);
void	UART_Interrupt_transmit(uint8_t data);
uint8_t	UART_Interrupt_receive(void);
/*Receive Setter*/
void UART_callBack_receive(void (*ptrFunc)(void));
/*Transmit Setter*/
void UART_callBack_transmit(void (*ptrFunc)(void));

#endif /* UART_H_ */