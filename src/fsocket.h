#ifndef _FSOCKET_H
#define _FSOCKET_H
#include <stdio.h>
#include "msg.h"

extern int golbalSocketFd;
extern char isConnect;
extern char cid[12];

int connect_server(char *serverAddr,int port,char *id);

int close_connect();

void handler_socket_status(int ret);

int send_data(char *data,size_t len);

int send_msg(package msg);
#endif


