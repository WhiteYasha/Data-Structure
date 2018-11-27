//
//  MaxHeap.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef MaxHeap_h
#define MaxHeap_h

//max heap

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct MaxHeap {
    int size;
    int key[MAX_SIZE];
} MaxHeap;

MaxHeap CreateMaxHeap();                //create a new empty max heap
void OutputMaxHeap(MaxHeap mh);             //output the max heap
void PushMaxHeap(MaxHeap *mh, int key);             //push a new element into the max heap
void PopMaxHeap(MaxHeap *mh);               //pop the front element from the max heap

#endif /* MaxHeap_h */
