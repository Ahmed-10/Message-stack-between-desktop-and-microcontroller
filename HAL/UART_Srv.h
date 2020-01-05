/*
 * UART_Srv.h
 *
 * Created: 20/01/04 2:20:56 AM
 *  Author: ahmed
 */ 


#ifndef UART_SRV_H_
#define UART_SRV_H_

/***************services***************/
void StrTransmit(uint8_t* str);
void Uint16Transmit(uint16_t data);
void Uint8Transmit(uint8_t data);
void StrReceive(uint8_t *str);//receive until  '#'

/***************Asynchronous Services***************/
void StrReceive_Asynch(void);
void StrTransmit_Asynch(uint8_t* str);



#endif /* UART_SRV_H_ */