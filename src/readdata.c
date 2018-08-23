#include <stdlib.h>
#include <stdio.h>
#include "readdata.h"
#include "fsocket.h"
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>
#include "msg.h"

unsigned char isRun;

void parserData(char *data,ssize_t len)
{
	package msg;

	if(strcmp(data,"reqCode") == 0)
	{
	
		memset(&msg,0,sizeof(msg));
		msg.head.type 	= MSG_TYPE_ID;
		msg.fd = 0;
		msg.head.len = sizeof(msg_head)+strlen(cid);
		strcpy(msg.body,cid);
		send_msg(msg);
	}
}

void* run_read(void  *args)
{
	struct timeval tv;
	fd_set fds;
	int ret ;
	char buff[1024];
	ssize_t recvLen;

	FD_ZERO(&fds);
	FD_SET(golbalSocketFd,&fds);
	
	tv.tv_sec = 1;
	tv.tv_usec= 0;

	while(isRun)
	{
		if(isConnect)
		{
			FD_ZERO(&fds);
			FD_SET(golbalSocketFd,&fds);
			tv.tv_sec = 1;
			tv.tv_usec = 0;

			ret = select(golbalSocketFd+1,&fds,NULL,NULL,&tv);

			if(ret < 0)
			{
				sleep(10);
				printf("read fail errno:%d\n",errno);
				handler_socket_status(errno);
			}
			else if(ret == 0)
			{
				//printf("read time out \n");
			}
			else
			{
			
				memset(buff,0,sizeof(buff));
				recvLen = recv(golbalSocketFd,buff,sizeof(buff),0);

				if(recvLen == 0)
				{
					handler_socket_status(0);
				}
				else if(recvLen < 0)
				{
					handler_socket_status(errno);
				}
				else
				{	
					parserData(buff,recvLen);
					printf("recv data len:%d ---  %s \n",recvLen,buff);
				}
			}
		}
		else
		{
			sleep(1);
		}

	}

	return (void *)NULL;
}

int start_read_data(void)
{
	pthread_t pid;

	isRun = 1;

	if(pthread_create(&pid,NULL,run_read,(void *)NULL)==0)
	{
		printf("start read success\n");
	}
	else
	{
		printf("start read fail \n");
		return -1;
	}

	return 0;

}

void close_read_data(void)
{
	isRun = 0;
}
