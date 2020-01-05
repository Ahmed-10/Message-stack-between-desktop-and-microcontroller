/*
 * LCD_config.h
 *
 * Created: 19/12/20 2:52:47 PM
 *  Author: ahmed
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define DATA_PORT	PORTB
#define CTRL_PORT	PORTC

#define RS_PIN		5
#define RW_PIN		6
#define EN_PIN		7

#define DATA_PORT_DIR	DDRB
#define CTRL_PINS_DIR	DDRC

#define BCK_LIGHT_INIT	SET_BIT(DDRC, 4)	
#define BCK_LIGHT_ON	SET_BIT(PORTC, 4)
#define BCK_LIGHT_OFF	CLR_BIT(PORTC, 4)



#endif /* LCD_CONFIG_H_ */