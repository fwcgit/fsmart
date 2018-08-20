#ifndef _FSOCKET_H
#define _FSOCKET_H
#include <stdio.h>

extern int golbalSocketFd;
extern char isConnect;

int connect_server(char *serverAddr,int port);

int close_connect();

void handler_socket_status(int ret);

int send_data(char *data,size_t len);
#endif


