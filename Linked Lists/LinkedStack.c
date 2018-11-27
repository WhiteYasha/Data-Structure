//
//  LinkedStack.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "LinkedStack.h"

LinkedStack* CreateLinkedStack()               //create a new empty linked stack
{
    return (LinkedStack*)NULL;
}
int IsEmptyLinkedStack(LinkedStack *ls)                //check if the linked stack is empty
{
    return !ls;
}
void OutputLinkedStack(LinkedStack *ls)                //output the linekd stack
{
    LinkedStack *node = ls;
    while (node) {
        printf("%d ", node -> key);
        node = node -> ptr;
    }
    puts("");
}
LinkedStack* PushLinkedStack(LinkedStack *ls, int key)             //push a new element into the linekd stack
{
    LinkedStack *node = (LinkedStack*)malloc(sizeof(LinkedStack));
    node -> key = key;
    if (!ls) {
        node -> ptr = NULL;
        ls = node;
    }
    else {
        node -> ptr = ls;
        ls = node;
    }
    return ls;
}
LinkedStack* PopLinkedStack(LinkedStack *ls)               //pop the top element from the linekd stack
{
    if (IsEmptyLinkedStack(ls)) return NULL;
    else {
        LinkedStack *tmp = ls;
        ls = ls -> ptr;
        free(tmp);
        return ls;
    }
}
