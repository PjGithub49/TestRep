/*
 * AppMQLib.h
 *
 *  Created on: May 15, 2009
 *      Author: root
 */

#ifndef APPMQLIB_H_
#define APPMQLIB_H_

void* Open_MQ(void *);
int Send_MQ(char * P_Message,int P_MessageSize);
#endif /* APPMQLIB_H_ */
