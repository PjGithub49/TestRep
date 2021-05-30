#include <pthread.h>
#include <mqueue.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream.h>
#include <sys/types.h>
#include <errno.h>
#include "AppMQLib.h"

//fot CTM
#define max(x,y) ((x) > (y) ? (x) : (y))
#define PRIORITY    1
#define APP_MQ_SEND         "/AppMQSend"
#define APP_MQ_RECV         "/AppMQRecv"

mqd_t AppMqSend_des,AppMqRecv_des;

void AppRecvMQ_DataArrival(void * Buf,int BufLen);
void LogBuffer(char *Buffer, int Lenght);

void MqNotify_DataArrival(mqd_t P_mqdes)
{
	while( true)
	{
	   struct mq_attr attr;
	   void *buf;
	   mq_getattr(P_mqdes, &attr);

	   if (attr.mq_curmsgs <= 0){   break;   	   }
	   else
	   {
		   buf = malloc(attr.mq_msgsize);
		   if(buf == NULL)
			   exit(1);

		   int nr = mq_receive(P_mqdes, (char *)buf, attr.mq_msgsize, NULL);

           AppRecvMQ_DataArrival((void *) buf,nr);
		   free(buf);
	   }
	}
}

void* Open_MQ(void *)
{
	int MQ_MaxMSG=100,MQ_MSGSIZE=300;
	 struct mq_attr sendqueue_att;
	 sendqueue_att.mq_maxmsg = MQ_MaxMSG;
	 sendqueue_att.mq_msgsize =MQ_MSGSIZE;
	 AppMqSend_des = mq_open(APP_MQ_SEND, O_CREAT | O_RDWR| O_NONBLOCK, S_IRWXU,&sendqueue_att);
  //  if (AppMqSend_des == (mqd_t) -1)   return errno;

	 struct mq_attr recvqueue_att;
	 recvqueue_att.mq_maxmsg = MQ_MaxMSG;
	 recvqueue_att.mq_msgsize =MQ_MSGSIZE;
    AppMqRecv_des = mq_open(APP_MQ_RECV,O_CREAT | O_RDWR | O_NONBLOCK, S_IRWXU,&recvqueue_att);
 //   if (AppMqRecv_des == (mqd_t) -1)   return errno;

    cout <<"Ready MQ "<<endl;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(AppMqRecv_des, &rfds);
    int nfds = max(nfds, AppMqRecv_des);
    while(true)
    {
		   int retval = select(nfds+1,&rfds, NULL, NULL, NULL);

		   //if (retval == -1)    return errno;
		   if (retval>0)
			   MqNotify_DataArrival(AppMqRecv_des);
    }
}
int Send_MQ(char * P_Message,int P_MessageSize)
{
	LogBuffer((char*) P_Message, P_MessageSize);
    if (mq_send(AppMqSend_des, P_Message, P_MessageSize, PRIORITY) == -1)  cout<<"error/n";
    return 0;
}
