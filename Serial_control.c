/*
 * Serial_control.c
 *
 * Created: 20/01/02 6:03:21 AM
 *  Author: ahmed
 */ 


#include "avr/io.h"
#include "LCD.h"
#include "UART.h"
#include "UART_Srv.h"
#include "stack.h"

void btn_init(void);
uint8_t get_btn(void);

Stack s;

int main(void)
{
	uint8_t ch;
	CreateStack(&s);
	lcd_init();
	UART_Init(MYUBRR);
	StrReceive_Asynch();
    while(1)
    {
		if(get_btn()){
			if(StackEmpty(&s) == 1){
				lcd_clr();
				lcd_write_string((uint8_t*)"stack is empty");
			}
			else{
				Pop(&ch, &s);
				lcd_clr();
				lcd_write_char(ch);
			}
		}
		else{
		}
    }
}


void btn_init(void){
	DDRA  &= 0xFE;
	PORTA |= 0x01;
}

uint8_t get_btn(void){
	uint8_t value = 0;
	static uint8_t flag = 0;
	if(!(PINA & 1)){
		if(flag == 0){
			_delay_ms(10);
			if((!(PINA & 1)) == 1){
				value = 1;
				flag = 1;
			}
		}
	}
	else{
		flag = 0;
	}
	return value;
}