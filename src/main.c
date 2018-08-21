#include <stdio.h>
#include "fsocket.h"
#include <unistd.h>
#include "msg.h"
#include "usart.h"
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[])	
{
	//121.40.165.18:8800
#if 0
	connect_server("127.0.0.1",28898);
	open_usart("/dev/ttyUSB0");
	getchar();

	close_usart();
	close_connect();
#endif

	char *c = "hell_wwwwww";
	package pk;
	pk.body = (char *)malloc(strlen(c)+1);
	strcpy(pk.body,c);
	
	printf("package size :%d body:%s \n",sizeof(pk),pk.body);

	free(pk.body);
	return 0;
}
