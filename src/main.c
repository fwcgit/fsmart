#include <stdio.h>
#include "fsocket.h"
#include <unistd.h>
#include "msg.h"
#include "usart.h"

int main(int argc,char *argv[])	
{
	//121.40.165.18:8800
	connect_server("127.0.0.1",16889);
	open_usart("/dev/ttyUSB0");
	getchar();

	close_usart();
	close_connect();
	
	return 0;
}
