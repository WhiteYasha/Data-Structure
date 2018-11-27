//
//  LinkedQueue.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "LinkedQueue.h"

LinkedQueue* CreateLinkedQueue()               //create a new empty linekd queue
{
    return (LinkedQueue*)NULL;
}
int IsEmptyLinkedQueue(LinkedQueue *lq)                //check if the linked queue is empty
{
    return !lq;
}
void OutputLinkedQueue(LinkedQueue *lq)                //output the linked queue
{
    LinkedQueue *node = lq;
    while (node) {
        printf("%d ", node -> key);
        node = node -> ptr;
    }
    puts("");
}
LinkedQueue* PushLinkedQueue(LinkedQueue *lq, int key)             //push a new element into the linked queue
{
    LinkedQueue *node = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    node -> key = key;
    node -> ptr = NULL;
    if (!lq) lq = node;
    else {
        LinkedQueue *tmp = lq;
        while (tmp -> ptr) tmp = tmp -> ptr;
        tmp -> ptr = node;
    }
    return lq;
}
LinkedQueue* PopLinkedQueue(LinkedQueue *lq)               //pop the front element from the linked queue
{
    if (IsEmptyLinkedQueue(lq)) return NULL;
    else {
        LinkedQueue *tmp = lq;
        lq = lq -> ptr;
        free(tmp);
        return lq;
    }
}
