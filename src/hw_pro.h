/*********************************************************************
File Name: hw_pro.h
Author: fuweicheng
mail: fu_huaicheng@163.com
Created Time: Wed 08 Aug 2018 02:24:53 PM CST
Description:hardware tel protocol
*************************************************************/

#ifndef HW_PRO_H
#define HW_PRO_H
typedef struct hw_pre_head
{
	unsigned char type;
	int 		  index;
	int 		  len;
}

typedef struct hw_pro_body
{
	unsigned char cmd;
	char 		  *data;
}

typedef struct hw_pro
{
	hw_pre_head head;
	hw_pro_body body;
}hw_msg

#endif

