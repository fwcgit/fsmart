//
//  msg.h
//  TelServer
//
//  Created by fwc on 2018/5/28.
//  Copyright © 2018年 fwc. All rights reserved.
//

#ifndef msg_h
#define msg_h

#define MSG_TYPE_ID     0x01 //上报唯一客户端ID
#define MSG_TYPE_CMD    0x02 //执行指令
#define MSG_TYPE_DATA   0x03 //数据
#define MSG_TYPE_HEART  0x04 //心跳

typedef struct m_head
{
    unsigned char   type;
    unsigned char 	len;

}msg_head;

typedef struct m_package
{
    msg_head 	head;
    char 		body[128];	
	int 		fd;
}package;



#endif /* msg_h */
