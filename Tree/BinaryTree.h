//
//  BinaryTree.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

//binary tree

#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a > b ? a : b

typedef struct BinaryTree {
    char key;
    struct BinaryTree *leftChild, *rightChild;
} BinaryTree;

BinaryTree* CreateBinaryTree();             //create a new binary tree with pre-order
void Preorder(BinaryTree *bt);              //pre-order travel
void Inorder(BinaryTree *bt);               //in-order travel
void Postorder(BinaryTree *bt);             //post-order travel
int CountLeaf(BinaryTree *bt);              //count the leaves of the binary tree
int CountDepth(BinaryTree *bt);             //count the depth of the binary tree

#endif /* BinaryTree_h */
