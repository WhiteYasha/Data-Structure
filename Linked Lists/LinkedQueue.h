//
//  LinkedQueue.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef LinkedQueue_h
#define LinkedQueue_h

//linked queue using single linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedQueue {
    int key;
    struct LinkedQueue *ptr;
} LinkedQueue;

LinkedQueue* CreateLinkedQueue();               //create a new empty linekd queue
int IsEmptyLinkedQueue(LinkedQueue *lq);                //check if the linked queue is empty
void OutputLinkedQueue(LinkedQueue *lq);                //output the linked queue
LinkedQueue* PushLinkedQueue(LinkedQueue *lq, int key);             //push a new element into the linked queue
LinkedQueue* PopLinkedQueue(LinkedQueue *lq);               //pop the front element from the linked queue

#endif /* LinkedQueue_h */
