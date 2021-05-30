/*
 * Queue.h
 *
 *  Created on: Jan 13, 2010
 *      Author: root
 */

#ifndef QUEUE_H_
#define QUEUE_H_
//Comment for test
class Queue {
public:
	Queue();
	Queue(int lengthFreme);
	virtual ~Queue();
	void qinsert(unsigned char *Buffer);           /** Inserting character function in queue **/
	char * qremove(char *ret);          /** Deleting character function in queue  **/
	void RemoveAll();      /** Clear Queue                           **/

	unsigned char Length;

private:
	struct list{
				                unsigned char *data;
				                struct list *next;
				           };
			typedef struct list node;
			struct list *front;     /* front pointer in queue */
			struct list *rear;     /* rear pointer in queue  */
			unsigned char temp;

};

#endif /* QUEUE_H_ */
