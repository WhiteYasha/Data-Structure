//
//  BinarySearchTree.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/28.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "BinarySearchTree.h"

BinarySearchTree* CreateBinarySearchTree()             //create a new empty binary search tree
{
    return (BinarySearchTree*)NULL;
}
void OutputBinarySearchTree(BinarySearchTree *bst)             //pre-order travel
{
    if (!bst) return;
    printf("%d ", bst -> key);
    OutputBinarySearchTree(bst -> leftChild);
    OutputBinarySearchTree(bst -> rightChild);
}
BinarySearchTree* InsertBinarySearchTree(BinarySearchTree *bst, int key)                //insert a new element into the binary search tree
{
    if (!bst) {
        BinarySearchTree *node = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
        node -> key = key;
        node -> leftChild = node -> rightChild = NULL;
        bst = node;
    }
    else if (bst -> key < key) bst -> rightChild = InsertBinarySearchTree(bst -> rightChild, key);
    else bst -> leftChild = InsertBinarySearchTree(bst -> leftChild, key);
    return bst;
}
int FindBinarySearchTree(BinarySearchTree *bst, int key)                   //find if the element is in the binary search tree
{
    if (!bst) return 0;
    else if (bst -> key < key) return FindBinarySearchTree(bst -> rightChild, key);
    else if (bst -> key > key) return FindBinarySearchTree(bst -> leftChild, key);
    else return 1;
}
BinarySearchTree* DeleteBinarySearchTree(BinarySearchTree *bst, int key)                //delete the element from the binary search tree
{
    if (!bst) return (BinarySearchTree*)NULL;
    else if (bst -> key < key) bst -> rightChild = DeleteBinarySearchTree(bst -> rightChild, key);
    else if (bst -> key > key) bst -> leftChild = DeleteBinarySearchTree(bst -> leftChild, key);
    else {
        BinarySearchTree *node = bst;
        if (!(bst -> leftChild) && !(bst -> rightChild)) {
            bst = NULL;
            free(node);
        }
        else if (!(bst -> rightChild)) {
            bst = bst -> leftChild;
            free(node);
        }
        else if (!(bst -> leftChild)) {
            bst = bst -> rightChild;
            free(node);
        }
        else {
            BinarySearchTree *tmp = node;
            node = node -> rightChild;
            while (node -> leftChild) {
                tmp = node;
                node = node -> leftChild;
            }
            bst -> key = node -> key;
            if (tmp -> leftChild == node) tmp -> leftChild = node -> rightChild;
            else tmp -> rightChild = node -> rightChild;
            free(node);
        }
    }
    return bst;
}
