/*
 * Queue.cpp
 *
 *  Created on: Jan 13, 2010
 *      Author: root
 */

#include "Queue.h"
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue::Queue() {
	// TODO Auto-generated constructor stub
			 rear=front=NULL;
			 Length=2;
}

Queue::Queue(int lengthFreme) {
	// TODO Auto-generated constructor stub
			 rear=front=NULL;
			 Length=22;
}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
}
void Queue::qinsert(unsigned char *Buffer)
{

	node *newnode;      /* New node to be inserted */
    newnode=(node*)malloc(sizeof(node));

    newnode->next=NULL;
    newnode->data= Buffer;
    	printf("\n====================QInserData: %d ,  %d", *(newnode->data),*(newnode->data+1) );
//    cout<<*(newnode->data);
//    cout<<(int)(newnode->data)<<endl;
    if((front)==NULL && (rear)==NULL)
    {
        front=newnode;
        rear=newnode;
     }
    else
    {
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
    |*  "rear" points to last node whose next field must be pointed to *|
    |*  newnode and then rear points to the latest node i.e. new node  *|
    \* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
      	(rear->next)=newnode;
        rear=newnode;
     }
//    cout<<(int)(front->data)<<"\n";
//    cout<<*(front->data);
}

char * Queue::qremove(char* ret)
{

//	cout<<*(front->data)<<endl;
	node *delnode;      /* Node to be deleted */
	if((front)==NULL && (rear)==NULL)
        return NULL;
    else
    {
        delnode=front;
       // cout<<(int)(front->data)<<endl;
       // cout<<*(front->data)<<endl;
        for(int i=0; i<Length; i++)
        	*(ret+i) = (char)(*(front->data + i));
        if((front)==(rear))
        {
          (front)=(front)->next;
          (rear)=(rear)->next;
        }
        else
        {
        	(front)=(front)->next;
        }
      free(delnode);
      return ret;
    }
}

void Queue::RemoveAll()
{
	(rear)=(front)=NULL;
}
