#include <stdio.h>
#include "fsocket.h"
#include <unistd.h>
#include "msg.h"
#include "usart.h"
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void *connectThread(void *args)
{
	char str[12];
	sprintf(str,"123ab321",*((int *)args));
	connect_server("10.18.20.40",28898,str);
	getchar();
	return NULL;
}

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
#if 0	
	int i;
	pthread_t pids[50];
	for(i = 0 ; i < 5 ; i++)
	{
		pthread_create(&pids[i],NULL,connectThread,&i);
		sleep(10);

	}
#endif	
	connect_server("10.18.75.100",28898,"jabc001");
//	open_usart("/dev/ttyUSB0");
	getchar();

	close_usart();
	close_connect();
#endif

	return 0;
}
