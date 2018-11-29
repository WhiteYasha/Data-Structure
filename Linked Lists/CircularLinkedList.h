//
//  CircularLinkedList.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/29.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef CircularLinkedList_h
#define CircularLinkedList_h

//disordered circular linked list with head node

#include <stdio.h>
#include <stdlib.h>

typedef struct CircularLinkedList {
    struct CircularLinkedList *ptr;
    int key;
} CircularLinkedList;

CircularLinkedList* CreateCircularLinkedList();             //create a new empty circular linked list with head node
void OutputCircularLinkedList(CircularLinkedList *cll);             //output the circular linked list
void InsertFront(CircularLinkedList *cll, int key);             //insert a new element from the front
void InsertBack(CircularLinkedList *cll, int key);              //insert a new element from the back
int Length(CircularLinkedList *cll);                //count the number of elements in the circular linked list
void DeleteFront(CircularLinkedList *cll);              //delete the front element
void DeleteBack(CircularLinkedList *cll);               //delete the back element

#endif /* CircularLinkedList_h */
