//
// Created by fwc on 2018/6/20.
//

#ifndef DRIVERBOARD_USART_H
#define DRIVERBOARD_USART_H
#include <stdio.h>
typedef unsigned char u8;

extern u8 doorStatus;
extern u8 lockStatus;
extern float tempComm;

int     open_usart(const char *ttys);
void   	usart_send_data(u8 *data,size_t len);
void    usart_parser_data(u8 *data,size_t len);

void    listener_usart_data(void (*call)(char* data,size_t len));
void    close_usart();
#endif //DRIVERBOARD_USART_H:
