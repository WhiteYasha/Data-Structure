//
//  LinkedStack.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef LinkedStack_h
#define LinkedStack_h

//linked stack using single linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedStack {
    int key;
    struct LinkedStack *ptr;
} LinkedStack;

LinkedStack* CreateLinkedStack();               //create a new empty linked stack
int IsEmptyLinkedStack(LinkedStack *ls);                //check if the linked stack is empty
void OutputLinkedStack(LinkedStack *ls);                //output the linekd stack
LinkedStack* PushLinkedStack(LinkedStack *ls, int key);             //push a new element into the linekd stack
LinkedStack* PopLinkedStack(LinkedStack *ls);               //pop the top element from the linekd stack

#endif /* LinkedStack_h */
