//
//  SingleLinkedList.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/26.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "SingleLinkedList.h"

SingleLinkedList* CreateSingleLinkedList()             //create a new empty linked list without head node
{
    return (SingleLinkedList*)NULL;
}
void OutputSingleLinkedList(SingleLinkedList *sll)             //Output the linked list
{
    SingleLinkedList *node = sll;
    while (node) {
        printf("%d ", node -> key);
        node = node -> ptr;
    }
    puts("");
}
SingleLinkedList* InsertHead(SingleLinkedList *sll, int key)                //insert a new element to the linked list from the front
{
    SingleLinkedList *node = (SingleLinkedList*)malloc(sizeof(SingleLinkedList));
    node -> key = key;
    if (!sll) {
        node -> ptr = NULL;
        sll = node;
    }
    else {
        node -> ptr = sll;
        sll = node;
    }
    return sll;
}
SingleLinkedList* InsertTail(SingleLinkedList *sll, int key)                //insert a new element to the linked list from the back
{
    SingleLinkedList *node = (SingleLinkedList*)malloc(sizeof(SingleLinkedList));
    node -> key = key;
    node -> ptr = NULL;
    if (!sll) sll = node;
    else {
        SingleLinkedList *tmp = sll;
        while (tmp -> ptr) tmp = tmp -> ptr;
        tmp -> ptr = node;
    }
    return sll;
}
SingleLinkedList* DeleteSingleLinkedList(SingleLinkedList *sll, int key)                //delete the ordered element from the linked list
{
    SingleLinkedList *tmp = sll;
    if (sll -> key == key) {
        sll = sll -> ptr;
        free(tmp);
    }
    else {
        while (tmp -> ptr && tmp -> ptr -> key != key) tmp = tmp -> ptr;
        if (tmp -> ptr) {
            SingleLinkedList *node = tmp -> ptr;
            tmp -> ptr = node -> ptr;
            free(node);
        }
    }
    return sll;
}
