/*
 * LCD.c
 *
 * Created: 19/10/26 7:41:27 PM
 *  Author: ahmed
 */ 

#include "lcd.h"


/*private functions*/
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


void lcd_init(void){
	/*set the interfacing pins as outputs*/
	DATA_PORT_DIR = 0xff;
	SET_BIT(CTRL_PINS_DIR, RS_PIN);
	SET_BIT(CTRL_PINS_DIR, RW_PIN);
	SET_BIT(CTRL_PINS_DIR, EN_PIN);
	/*clr lcd*/
	lcd_write_instr(0x01);
	/*entry mood*/
	lcd_write_instr(0x06);
	/*display on*/
	lcd_write_instr(0x0c);
	/*setup 8 bit data line*/
	lcd_write_instr(0x38);
	/*setting back light pin as output*/
	BCK_LIGHT_INIT;
	BCK_LIGHT_ON;
}

void lcd_write_instr(uint8_t instr){
	_delay_ms(2);//to any previous commands
	CLR_BIT(CTRL_PORT, RS_PIN);//deal with instruction register
	CLR_BIT(CTRL_PORT, RW_PIN);//write operation
	DATA_PORT = instr;//operation code
	SET_BIT(CTRL_PORT, EN_PIN);//logic 1 on the enable bit
	CLR_BIT(CTRL_PORT, EN_PIN);//latch the data to the instruction register on the falling edge	
}

void lcd_write_char(uint8_t c){
	_delay_ms(2);//to any previous commands
	SET_BIT(CTRL_PORT, RS_PIN);//deal with data register
	CLR_BIT(CTRL_PORT, RW_PIN);//write operation
	DATA_PORT = c;//operation code
	SET_BIT(CTRL_PORT, EN_PIN);//logic 1 on the enable bit
	CLR_BIT(CTRL_PORT, EN_PIN);//latch the data to the instruction register on the falling edge
}

void lcd_clr(void){
	_delay_ms(2);
	lcd_write_instr(0x01);
}

void lcd_write_string(uint8_t* arr){
	while(*arr != 0){
		lcd_write_char(*arr);
		arr++;
	}
}

void lcd_goto(uint8_t column,uint8_t row){
	if (row == 0){
		lcd_write_instr(0x80 + column);
	}
	else if (row == 1){
		lcd_write_instr(0xc0 + column);
	}
}

void lcd_write_uint16(uint16_t data){
	if(data == 0){
		lcd_write_char('0');
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
		lcd_write_string(str);
	}
}

void lcd_write_uint8(uint8_t data){
	if(data == 0){
		lcd_write_char('0');
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
		lcd_write_string(str);
	}
}