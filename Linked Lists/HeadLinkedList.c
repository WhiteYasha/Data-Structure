//
//  HeadLinkedList.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/26.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "HeadLinkedList.h"

HeadLinkedList* CreateHeadLinkedList()             //create a new empty linked list with head node
{
    HeadLinkedList *hll = (HeadLinkedList*)malloc(sizeof(HeadLinkedList));
    hll -> ptr = NULL;
    return hll;
}
void OutputHeadLinkedList(HeadLinkedList *hll)             //output the linked list
{
    HeadLinkedList *node = hll -> ptr;
    while (node) {
        printf("%d ", node -> key);
        node = node -> ptr;
    }
    puts("");
}
void InsertHeadLinkedList(HeadLinkedList *hll, int key)              //insert a element to the linked
{
    HeadLinkedList *node = hll -> ptr;
    HeadLinkedList *tmp = (HeadLinkedList*)malloc(sizeof(HeadLinkedList));
    tmp -> key = key;
    if (!node) {
        tmp -> ptr = NULL;
        hll -> ptr = tmp;
    }
    else if (node -> key > key) {
        tmp -> ptr = node;
        hll -> ptr = tmp;
    }
    else {
        while (node -> ptr && node -> ptr -> key <= key) node = node -> ptr;
        tmp -> ptr = node -> ptr;
        node -> ptr = tmp;
    }
}
void DeleteHead(HeadLinkedList *hll)               //delete the element from the front of the linked list
{
    HeadLinkedList *tmp = hll -> ptr;
    hll -> ptr = tmp -> ptr;
    free(tmp);
}
void DeleteTail(HeadLinkedList *hll)               //delete the element from the back of the linked list
{
    HeadLinkedList *tmp = hll;
    while (tmp -> ptr && tmp -> ptr -> ptr) tmp = tmp -> ptr;
    free(tmp -> ptr -> ptr);
    tmp -> ptr = NULL;
}
void DeleteHeadLinkedList(HeadLinkedList *hll, int key)                //delete the ordered element from the linked list
{
    HeadLinkedList *tmp = hll;
    while (tmp -> ptr) {
        if (tmp -> ptr -> key == key) {
            HeadLinkedList *node = tmp -> ptr;
            tmp -> ptr = node -> ptr;
            free(node);
            break;
        }
        else tmp = tmp -> ptr;
    }
}
int FindHeadLinkedList(HeadLinkedList *hll, int key)              //find if the element is in the linked list
{
    HeadLinkedList *tmp = hll -> ptr;
    while (tmp) {
        if (tmp -> key == key) return 1;
        else tmp = tmp -> ptr;
    }
    return 0;
}
HeadLinkedList* MergeHeadLinkedList(HeadLinkedList *h1, HeadLinkedList *h2)
//merge two linked lists into a new linked list
{
    HeadLinkedList *h3 = (HeadLinkedList*)malloc(sizeof(HeadLinkedList));
    HeadLinkedList *n1 = h1 -> ptr, *n2 = h2 -> ptr, *n3 = h3;
    while (n1 && n2) {
        HeadLinkedList *tmp = (HeadLinkedList*)malloc(sizeof(HeadLinkedList));
        if (n1 -> key <= n2 -> key) {
            tmp -> key = n1 -> key;
            n1 = n1 -> ptr;
        }
        else {
            tmp -> key = n2 -> key;
            n2 = n2 -> ptr;
        }
        n3 -> ptr = tmp;
        n3 = n3 -> ptr;
    }
    for (; n1; n1 = n1 -> ptr) {
        HeadLinkedList *tmp = (HeadLinkedList*)malloc(sizeof(HeadLinkedList));
        tmp -> key = n1 -> key;
        n3 -> ptr = tmp;
        n3 = n3 -> ptr;
    }
    for (; n2; n2 = n2 -> ptr) {
        HeadLinkedList *tmp = (HeadLinkedList*)malloc(sizeof(HeadLinkedList));
        tmp -> key = n2 -> key;
        n3 -> ptr = tmp;
        n3 = n3 -> ptr;
    }
    n3 -> ptr = NULL;
    return h3;
}
