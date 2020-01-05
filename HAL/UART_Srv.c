/*
 * UART_Srv.c
 *
 * Created: 20/01/04 2:20:08 AM
 *  Author: ahmed
 */ 

#include "UART.h"
#include "stack.h"
#include "LCD.h"

extern Stack s;
/***************private***************/
static void swap(uint8_t* x, uint8_t* y){
	uint8_t temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

static void reverse_str(uint8_t* str, uint8_t str_size){
	uint8_t i  = 0;
	uint8_t j = str_size - 2;
	
	while(i < (str_size - 1)/2){
		swap(str + i, str + j);
		i++;
		j--;
	}
}
/***************services***************/
void StrTransmit(uint8_t* str){
	while(*str != 0){
		UART_NoInterrupt_transmit(*str);
		str++;
	}
}

void Uint16Transmit(uint16_t data){
	if(data == 0){
		UART_NoInterrupt_transmit('0');
	}
	else{
		uint8_t i = 0;
		uint8_t str[6];
		while(data != 0){
			str[i] = data % 10 +48;
			data /= 10;
			i++;
		}
		str[i] = '\0';
		reverse_str(str, i+1);
		StrTransmit(str);
	}
}

void Uint8Transmit(uint8_t data){
	if(data == 0){
		UART_NoInterrupt_transmit('0');
	}
	else{
		uint8_t i = 0;
		uint8_t str[4];
		while(data != 0){
			str[i] = data % 10 +48;
			data /= 10;
			i++;
		}
		str[i] = '\0';
		reverse_str(str, i+1);
		StrTransmit(str);
	}
}

void StrReceive(uint8_t *str)       //receive until  '#'
{
	uint8_t i = 0;
	str[i] = UART_NoInterrupt_receive();
	while(str[i] != '#')
	{
		i++;
		str[i] = UART_NoInterrupt_receive();
	}
	str[i] = '\0';
}

/***************Asynchronous Services***************/
static	 uint8_t *Asynch_transmit_Str;
/*static	 uint8_t *Asynch_receive_str;*/

static void ReceiveFunction(void){
	//write your code
	uint8_t temp;
	temp = UART_Interrupt_receive();
	if(StackFull(&s)){
		lcd_clr();
		lcd_write_string((uint8_t*)"stack is full");
	}
	else{
		Push(temp, &s);
		lcd_clr();
		lcd_write_string((uint8_t*)"press the btn");
	}
}

void StrReceive_Asynch(void){
	/*Asynch_receive_str = str;*/
	UART_Interrupt_En(RX_C);
	UART_callBack_receive(ReceiveFunction);
}

static void TransmitFunction(void){
	//write your code

}

void StrTransmit_Asynch(uint8_t* str){
	Asynch_transmit_Str = str;
	UART_callBack_transmit(TransmitFunction);
	UART_Interrupt_En(UDR_E);	
}

