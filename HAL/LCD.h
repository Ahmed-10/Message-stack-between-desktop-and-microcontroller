/*
 * LCD.h
 *
 * Created: 19/10/26 7:41:15 PM
 *  Author: ahmed
 */ 


#ifndef LCD_H_
#define LCD_H_


#define F_CPU	8000000UL
#include "Util/delay.h"
#include "avr/io.h"
#include "bit_handle.h"
#include "LCD_config.h"


void lcd_init(void);
void lcd_write_instr(uint8_t instr);
void lcd_write_char(uint8_t c);
void lcd_clr(void);
void lcd_write_string(uint8_t* arr);
void lcd_goto(uint8_t column,uint8_t row);
void lcd_write_uint16(uint16_t data);
void lcd_write_uint8(uint8_t data);




#endif /* LCD_H_ */