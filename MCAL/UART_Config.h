/*
 * UART0_Config.h
 *
 * Created: 19/11/02 1:04:07 PM
 *  Author: ahmed
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*Baud rate equation: if you want to change the baud rate at run time you have to 
calculate UBRR value yourself and use it with the initialization function*/
#define FOSC	8000000
#define BAUD	9600
#define MYUBRR	FOSC/16/BAUD-1

#endif /* UART_CONFIG_H_ */