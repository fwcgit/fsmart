#include "fsocket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include "readdata.h"
#include <errno.h>
#include <stdlib.h>
#include "msg.h"
#include <pthread.h>

int golbalSocketFd=0;
char cid[12];
char isConnect = 0;
char *server_addr;
int  server_port;
char tryIsRun = 0;

void handler_socket_status(int ret)
{
	switch (ret)
	{
		case ECONNRESET:
		case EBADF:
		case EPIPE:
		case ENOTSOCK:
		case 0:
		isConnect = 0;
		break;
												            
		default:
		break;
	}
}

void try_connect_server(void)
{
	int fd;

	printf("connect close try connect \n");
	
	fd = create_socket();
	if(fd > 0)
	{
		
		if(connect_socket(fd,server_addr,server_port) == 0)
		{
			isConnect = 1;
			golbalSocketFd = fd;
			printf("connect success fd:%d\n",fd);
		}
		else
		{
			isConnect = 0;
			printf("connect fail fd:%d\n",fd);
			close(fd);	
		}	
	}
	else
	{
		printf("create socket fail \n");
	}
}

void* run_try_connect(void *args)
{
	while(tryIsRun)
	{
		if(isConnect == 0)
		{
			if(golbalSocketFd > 0)
			{
				close(golbalSocketFd);
			}

			try_connect_server();
		}
		sleep(10);
	}
}


void* run_heartbeat(void *args)
{

	char *data = "A";
	package msg;

	while(tryIsRun)
	{
	
		sleep(10);
		if(isConnect)
		{

			memset(&msg,0,sizeof(msg));
			msg.head.type 	= MSG_TYPE_HEART;
			msg.head.len 	= sizeof(msg_head)+strlen(cid);
			strcpy(msg.body,cid);
			send_msg(msg);

			printf("send heartbeat data golbalSocketFd :%d \n",golbalSocketFd);	
		}

	}
}

void start_try_connect_thread(void)
{

	pthread_t pid;
	
	tryIsRun = 1;

	if(pthread_create(&pid,NULL,run_try_connect,(void *)NULL) == 0)
	{
		printf("start_try_connect_thread success \n");
	}
	else
	{
		tryIsRun = 0;
		perror("start_try_connect_thread fail");
	}
}

void start_heartbeat(void)
{
	pthread_t pid;

	if(pthread_create(&pid,NULL,run_heartbeat,(void *)NULL) == 0)
	{
		printf("start_heartbeat success \n");
	}
	else
	{
		perror("start_heartbeat fail");
	}

}
/***
 *
 *connect socket O_NONBLOCK mode
 */
int connect_socket(int fd,char *serverAddr,int port)
{
	int ret;
	int flag;
	fd_set rfds;
	fd_set wfds;
	struct sockaddr_in addr_in;
	struct timeval tv;

	flag = fcntl(fd,F_GETFL,0);
	fcntl(fd,F_SETFL,flag|O_NONBLOCK);

	memset(&addr_in,0,sizeof(addr_in));

	addr_in.sin_family = AF_INET;
	addr_in.sin_addr.s_addr = inet_addr(serverAddr);
	addr_in.sin_port = htons(port);

	ret = connect(fd,(struct sockaddr *)&addr_in,sizeof(addr_in));
	
	FD_ZERO(&rfds);
	FD_ZERO(&wfds);
	FD_SET(fd,&rfds);
	FD_SET(fd,&wfds);
	
	tv.tv_sec = 5;
	tv.tv_usec= 0;

	ret = select(fd+1,&rfds,&wfds,NULL,&tv);

	if(ret > 0)
	{
		printf("select connnet ret %d",ret);
		ret = 0;
	}
	else if(ret == 0)
	{
		ret = -1;
		close(fd);
		printf("connect timeout \n");
	}
	else
	{
		close(fd);
		perror("connect error");
	}
	

	return ret;
}

int create_socket(void)
{

	int fd = socket(AF_INET,SOCK_STREAM,0);

	return fd;
}



int connect_server(char *serverAddr,int port,char *id)
{
	int fd;

	server_addr = serverAddr;
	server_port = port;
	strcpy(cid,id);

	isConnect = 0;

	start_read_data();

	start_try_connect_thread();

	start_heartbeat();

	return 0;
}

int send_msg(package msg)
{
	int i;
	int err = 0;
	ssize_t ret = 0;
	fd_set wfds;
	struct timeval tv;
	char *data;

	if(isConnect)
	{

		FD_ZERO(&wfds);
		FD_SET(golbalSocketFd,&wfds);
		tv.tv_sec = 0;
		tv.tv_usec = 500;

		ret = select(golbalSocketFd+1,NULL,&wfds,NULL,&tv);

		if(ret > 0)
		{

			data = (char *)malloc(sizeof(char)*msg.head.len);
			memcpy(data,(char*)&msg,sizeof(msg_head));
			memcpy(data+sizeof(msg_head),msg.body,msg.head.len -sizeof(msg_head));
			ret = write(golbalSocketFd,data,msg.head.len);
			free(data);

			if(ret == 0)
			{
				err = -1;

				handler_socket_status(0);
			}
			else if(ret < 0)
			{
				err = -1;
				handler_socket_status(errno);
			}
			else
			{
				err = 0;
			}
		}
		else if(ret < 0)
		{
			err = -1;
			handler_socket_status(errno);
		}
		else
		{
			err = -1;
			printf("write timeout \n");
		}

	
	}
	else
	{
		err = -1;
	}

	return err;
}

int send_data(char *data,size_t len)
{
	int i;
	int err = 0;
	ssize_t ret = 0;
	fd_set wfds;
	struct timeval tv;

	for(i = 0 ; i < len ; i++)
	{
		printf("%X ",data[i]);
	}

	printf("\n");

	if(isConnect)
	{

		FD_ZERO(&wfds);
		FD_SET(golbalSocketFd,&wfds);
		tv.tv_sec = 0;
		tv.tv_usec = 500;

		ret = select(golbalSocketFd+1,NULL,&wfds,NULL,&tv);

		if(ret > 0)
		{
			ret = write(golbalSocketFd,data,len);

			if(ret == 0)
			{
				err = -1;

				handler_socket_status(0);
			}
			else if(len < 0)
			{
				err = -1;
				handler_socket_status(errno);
			}
			else
			{
				err = 0;
			}
		}
		else if(ret < 0)
		{
			err = -1;
			handler_socket_status(errno);
		}
		else
		{
			err = -1;
			printf("write timeout \n");
		}

	
	}
	else
	{
		err = -1;
	}

	return err;
}

int close_connect(void)
{
	if(golbalSocketFd > 0)
	{
		close(golbalSocketFd);
	}

	tryIsRun = 0;

	close_read_data();

	printf("close_connect \n");
}
