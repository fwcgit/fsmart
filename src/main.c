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
#if 1
	//pid_t pid;

	//pid = fork();

	/**if(pid == 0)
	{
	
	connect_server("127.0.0.1",28898,"212321");
	}
	else
	{
	
	connect_server("127.0.0.1",28898,"123321");
	}
	****/

	connect_server("127.0.0.1",28898,"123321");
	//open_usart("/dev/ttyUSB0");
	getchar();

	close_usart();
	close_connect();
#endif

	return 0;
}
