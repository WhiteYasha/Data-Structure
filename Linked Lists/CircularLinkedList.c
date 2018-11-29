//
//  CircularLinkedList.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/29.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "CircularLinkedList.h"

CircularLinkedList* CreateCircularLinkedList()             //create a new empty circular linked list with head node
{
    CircularLinkedList *cll = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    cll -> ptr = cll;
    return cll;
}
void OutputCircularLinkedList(CircularLinkedList *cll)             //output the circular linked list
{
    CircularLinkedList *node = cll -> ptr;
    while (node != cll) {
        printf("%d ", node -> key);
        node = node -> ptr;
    }
    puts("");
}
void InsertFront(CircularLinkedList *cll, int key)             //insert a new element from the front
{
    CircularLinkedList *node = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
    node -> key = key;
    node -> ptr = cll -> ptr;
    cll -> ptr = node;
}
void InsertBack(CircularLinkedList *cll, int key)              //insert a new element from the back
{
    CircularLinkedList *node = (CircularLinkedList*)malloc(sizeof(CircularLinkedList)), *tmp = cll;
    node -> key = key;
    node -> ptr = cll;
    while (tmp -> ptr != cll) tmp = tmp -> ptr;
    tmp -> ptr = node;
}
int Length(CircularLinkedList *cll)                //count the number of elements in the circular linked list
{
    CircularLinkedList *tmp = cll;
    int res = 0;
    while (tmp -> ptr != cll) {
        res++;
        tmp = tmp -> ptr;
    }
    return res;
}
void DeleteFront(CircularLinkedList *cll)              //delete the front element
{
    CircularLinkedList *node = cll -> ptr;
    if (node == cll) return ;
    else {
        cll -> ptr = node -> ptr;
        free(node);
    }
}
void DeleteBack(CircularLinkedList *cll)               //delete the back element
{
    CircularLinkedList *node = cll -> ptr;
    if (node == cll) return ;
    else if (node -> ptr == cll) {
        cll -> ptr = cll;
        free(node);
    }
    else {
        while (node -> ptr -> ptr && node -> ptr -> ptr != cll) node = node -> ptr;
        CircularLinkedList *tmp = node -> ptr;
        node -> ptr = tmp -> ptr;
        free(tmp);
    }
}
