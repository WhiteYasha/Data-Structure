//
//  HeadLinkedList.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/26.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef HeadLinkedList_h
#define HeadLinkedList_h

//non-decreasing order linked list with head node

#include <stdio.h>
#include <stdlib.h>

typedef struct HeadLinkedList {
    struct HeadLinkedList *ptr;
    int key;
} HeadLinkedList;

HeadLinkedList* CreateHeadLinkedList();             //create a new empty linked list with head node
void OutputHeadLinkedList(HeadLinkedList *hll);             //output the linked list
void InsertHeadLinkedList(HeadLinkedList *hll, int key);              //insert a element to the linked
void DeleteHead(HeadLinkedList *hll);               //delete the element from the front of the linked list
void DeleteTail(HeadLinkedList *hll);               //delete the element from the back of the linked list
void DeleteHeadLinkedList(HeadLinkedList *hll, int key);                //delete the ordered element from the linked list
int FindHeadLinkedList(HeadLinkedList *hll, int key);              //find if the element is in the linked list
HeadLinkedList* MergeHeadLinkedList(HeadLinkedList *h1, HeadLinkedList *h2);
//merge two linked lists into a new linked list

#endif /* HeadLinkedList_h */
