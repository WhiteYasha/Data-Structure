//
//  BinarySearchTree.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/28.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

//binary search tree

#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree {
    int key;
    struct BinarySearchTree *leftChild, *rightChild;
} BinarySearchTree;

BinarySearchTree* CreateBinarySearchTree();             //create a new empty binary search tree
void OutputBinarySearchTree(BinarySearchTree *bst);             //pre-order travel
BinarySearchTree* InsertBinarySearchTree(BinarySearchTree *bst, int key);                //insert a new element into the binary search tree
int FindBinarySearchTree(BinarySearchTree *bst, int key);                   //find if the element is in the binary search tree
BinarySearchTree* DeleteBinarySearchTree(BinarySearchTree *bst, int key);                //delete the element from the binary search tree

#endif /* BinarySearchTree_h */
