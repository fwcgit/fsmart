//
// Created by fwc on 2018/6/20.
//

#include "usart.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <pthread.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>

int         tty_fd;
char 		*tty_comm;
char 		isConn 	= 0;
char 		isRun 	= 0;

int init_usart(int fd);
int read_thread();


void usart_status_ctl()
{
	
	isConn = 0;
	
}

u8 code_check(u8 *data,size_t len)
{
    int val = 0;
    int i = 0;
    while(i < len)
    {
        val += *(data+i++);
    }

    return (u8)(val & 0xff);
}

void try_open_usart(void)
{
	int ret;
	int fd;


	printf("try_open_usart %s \n",tty_comm);

	if(tty_fd > 0)
	{
		close(tty_fd);
		tty_fd = 0;
	}

    fd 		= open(tty_comm,O_RDWR | O_NOCTTY | O_NDELAY);

	if(fd > 0)
	{

		if(fcntl(fd,F_SETFL,0) == -1)
    	{
        	perror("set usart setfl fail");
    	}

    	if(isatty(fd) == 0)
    	{
        	perror("this deivce not usart");
    	}
	
		fd = init_usart(fd);
	
		isConn = 1;

		printf("try_open_usart %s success \n",tty_comm);
	}

    if(fd == -1)
    {
        perror("open usart fail");
    }

}

int  open_usart(const char *ttys)
{
	int ret;
	int fd;
	int flag;

    fd 		= open(ttys,O_RDWR | O_NOCTTY | O_NDELAY);
	tty_comm 	= (char *)malloc(sizeof(char) * 20);
	strcpy(tty_comm,ttys);

    if(fd == -1)
    {
        perror("open usart fail");
    }
	
	if(fd > 0)
	{
		flag = fcntl(fd,F_GETFL,0);
	    if(fcntl(fd,F_SETFL,flag | O_NONBLOCK) == -1)
	    {
    	    perror("set usart setfl fail");
        	return -1;
    	}

    	if(isatty(fd) == 0)
    	{
        	perror("this deivce not usart");
        	return -1;
    	}
	
		fd = init_usart(fd);	
		isConn = 1;

		printf("open_usart %s success \n",tty_comm);
	}
	else
	{
		isConn = 0;
	}

	ret = read_thread();
    return ret;
}

int init_usart(int fd)
{
    struct termios attr;

    if(tcgetattr(fd,&attr) == -1)
    {
        perror("get usart attr fail");
        return -1;
    }

    cfsetispeed(&attr,B115200);
    cfsetospeed(&attr,B115200);

    attr.c_cflag |= CLOCAL | CREAD;
    attr.c_cflag &= ~CRTSCTS;
    attr.c_cflag &= ~CSIZE;
    attr.c_cflag |= CS8;
    attr.c_cflag &= ~PARENB;
    attr.c_iflag &= ~(INPCK|ICRNL|IGNCR);
    attr.c_cflag &= ~CSTOPB;
    attr.c_cc[VMIN] = 0;
    attr.c_cc[VTIME] = 5;
    attr.c_oflag &= ~OPOST;
    attr.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    tcflush(fd,TCIOFLUSH);

    if(tcsetattr(fd,ICANON,&attr) == -1)
    {
        perror("set usart attr fail");
        return -1;
    }

    tty_fd = fd;
    return fd;
}

void listener_usart_data(void (*call)(char* data,size_t len))
{

}

void parser_device_data(u8 *data,size_t len)
{
  int i = 0;

  printf("tty recv len:%d,data:",len);

  for(i = 0 ; i < len ; i++)
  {
  	printf("%x ",*(data+i));
  }
  printf("\n");

}

int readData(int fd)
{

		int totalBytes;
		int bodyLen;
		ssize_t len;
		char buff[100];
		memset(buff,0, sizeof(buff));
		totalBytes 	= 0;
		bodyLen 	= 0;

		len = read(fd,buff,sizeof(buff));

		if(len <= 0)
		{
			usart_status_ctl();
		}
		else
		{
			totalBytes = len;

			while(totalBytes < 2)
			{
				len = read(fd,buff+totalBytes,sizeof(buff) - totalBytes);

				if(len <= 0)
				{
					usart_status_ctl();
					break;
				}
				else
				{
					totalBytes+=len;
				}
			}
			
			if(totalBytes >= 2)
			{
				bodyLen = buff[1] & 0x000000ff;

				while(totalBytes -2  < bodyLen)
				{
					len = read(fd,buff+totalBytes,sizeof(buff)-totalBytes);
				
					if(len <= 0)
					{
						usart_status_ctl();

						break;
					}
					else
					{
						totalBytes+=len;
					}
				}

				if(totalBytes >= bodyLen)
				{
					parser_device_data(buff,len);
				}

			}
		}

}

void *thread_exeute(void *args)
{

    int ret;
    int fd = *((int *)args);
    struct timeval time;
    fd_set read_set;


    time.tv_sec = 1;
    time.tv_usec =0;

    while(isRun)
    {
        
		if(isConn == 1)
		{

			time.tv_sec = 0;
       	 	time.tv_usec = 100;
        	FD_ZERO(&read_set);
        	FD_SET(fd,&read_set);
        	ret = select(fd+1,&read_set,NULL,NULL,NULL);

        	if(ret < 0)
        	{
				usart_status_ctl(0);
        	}
        	else if(ret == 0){
        	}
        	else
        	{
				readData(fd);
			}
		}
		else
		{
			sleep(10);

			try_open_usart();
		}
    }

    return NULL;
}

int read_thread()
{
    pthread_t  pt;

	isRun = 1;
    if(pthread_create(&pt,NULL,thread_exeute,(void *)&tty_fd) == -1)
    {
        perror("start thread fail");
        return -1;
    }

    return 0;
}

void usart_parser_data(u8 *data,size_t len)
{
    u8 check = *(data+3);

}

void usart_send_data(u8 *data,size_t len)
{
	fd_set wfds;
	int ret;
	struct timeval tv;

	FD_ZERO(&wfds);
	FD_SET(tty_fd,&wfds);

	tv.tv_sec = 1;
	tv.tv_usec = 0;

	ret = select(tty_fd+1,NULL,&wfds,NULL,&tv);

	if(ret == 0)
	{
	}
	else if(ret < 0)
	{
		isConn = 0;	
	}
	else
	{
		 ssize_t  slen = write(tty_fd,data,len);

		 if(slen <= 0)
		 {
		 	isConn = 0;
		 }
		 else
		 {
			 if(slen == len)
    		{
    		}
    		else{
        		tcflush(tty_fd,TCIOFLUSH);
    		}	 
		 }
	}

   }

void close_usart()
{
	isRun = 0;
    close(tty_fd);
	printf("close_usart \n");
}
