/*
 * UART0.c
 *
 * Created: 19/11/02 12:53:43 PM
 *  Author: ahmed
 */ 
#include "UART.h"

/***************initialization***************/
void UART_Init(uint16_t ubrr){
		/*set the baud rate*/
		UCSRC &= ~(1 << URSEL);
		UBRRH = (uint8_t) (ubrr >> 8);
		UBRRL = (uint8_t) (ubrr);
		UCSRC |= (1 << URSEL);
		/*enable receiver and transimter*/
		UCSRB = (1 << RXEN) | (1 << TXEN);
		/*set frame format: 8 bit - no parity - one stop bits*/
		/*UCSRC |= (1<<USBS)|(3<<UCSZ0);*/
		UCSRC |= (3<<UCSZ0);
}

void UART_disable_tx(void){
	UCSRB &= ~(1 << TXEN);
}

void UART_disable_rx(void){
	UCSRB &= ~(1 << RXEN);
}

/***************send and receive***************/
void UART_NoInterrupt_transmit(uint8_t data){
	while (!(UCSRA & (1<<UDRE)));
	UDR = data;
}

uint8_t	UART_NoInterrupt_receive(void){
	while (!(UCSRA & (1<<RXC)));
	return UDR;	
}

/***************interrupt functions***************/
static void (*ptrReceiveFunction)(void);
static void (*ptrTransmitFunction)(void); 

void UART_Interrupt_En(t_interrupt_type interr){
	switch (interr){
	case RX_C:
	UCSRB |= (1 << RXCIE);
		break;
	case TX_C:
	UCSRB |= (1 << TXCIE);
		break;
	case UDR_E:
	UCSRB |= (1 << UDRIE);
		break;
	}
	SREG |= (1 << 7);
}

void UART_Interrupt_dis(t_interrupt_type interr){

	switch (interr){
	case RX_C:
	UCSRB &= ~(1 << RXCIE);
		break;
	case TX_C:
	UCSRB &= ~(1 << TXCIE);
		break;
	case UDR_E:
	UCSRB &= ~(1 << UDRIE);
		break;
	}	
}

void UART_Interrupt_transmit(uint8_t data){
	UDR = data;
}

uint8_t	UART_Interrupt_receive(void){
	return UDR;
}
/*Receive Setter*/
void UART_callBack_receive(void (*ptrFunc)(void)){
	ptrReceiveFunction = ptrFunc;
}
/*Transmit Setter*/
void UART_callBack_transmit(void (*ptrFunc)(void)){
	ptrTransmitFunction = ptrFunc;
}

/***************ISR***************/
ISR(USART_RXC_vect){
	(*ptrReceiveFunction)();
}

ISR(USART_UDRE_vect){
	(*ptrTransmitFunction)();
}