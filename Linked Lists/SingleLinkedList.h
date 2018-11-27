//
//  SingleLinkedList.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/26.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef SingleLinkedList_h
#define SingleLinkedList_h

//disordered single linked list without head node

#include <stdio.h>
#include <stdlib.h>

typedef struct SingleLinkedList {
    struct SingleLinkedList *ptr;
    int key;
} SingleLinkedList;

SingleLinkedList* CreateSingleLinkedList();             //create a new empty linked list without head node
void OutputSingleLinkedList(SingleLinkedList *sll);             //Output the linked list
SingleLinkedList* InsertHead(SingleLinkedList *sll, int key);                //insert a new element to the linked list from the front
SingleLinkedList* InsertTail(SingleLinkedList *sll, int key);                //insert a new element to the linked list from the back
SingleLinkedList* DeleteSingleLinkedList(SingleLinkedList *sll, int key);                //delete the ordered element from the linked list

#endif /* SingleLinkedList_h */
