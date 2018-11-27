//
//  MaxHeap.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "MaxHeap.h"

MaxHeap CreateMaxHeap()                //create a new empty max heap
{
    MaxHeap *mh = (MaxHeap*)malloc(sizeof(MaxHeap));
    (*mh).size = 0;
    for (int i = 0; i < MAX_SIZE; i++) (*mh).key[i] = 0;
    return *mh;
}
void OutputMaxHeap(MaxHeap mh)             //output the max heap
{
    for (int i = 1; i <= mh.size; i++) printf("%d%c", mh.key[i], i == mh.size ? '\n' : ' ');
}
void PushMaxHeap(MaxHeap *mh, int key)             //push a new element into the max heap
{
    int pos = ++(*mh).size;
    while (pos != 1 && (*mh).key[pos / 2] < key) {
        (*mh).key[pos] = (*mh).key[pos / 2];
        pos /= 2;
    }
    (*mh).key[pos] = key;
}
void PopMaxHeap(MaxHeap *mh)               //pop the front element from the max heap
{
    int tmp = (*mh).key[(*mh).size--];
    int fa = 1, ch = 2;
    while (ch <= (*mh).size) {
        if (ch < (*mh).size && (*mh).key[ch] < (*mh).key[ch + 1]) ch++;
        if (tmp >= (*mh).key[ch]) break;
        (*mh).key[fa] = (*mh).key[ch];
        fa = ch;
        ch *= 2;
    }
    (*mh).key[fa] = tmp;
}
