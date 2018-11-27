//
//  BinaryTree.cpp
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "BinaryTree.h"

BinaryTree* CreateBinaryTree()             //create a new binary tree with pre-order
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#') return NULL;
    else {
        BinaryTree *node = (BinaryTree*)malloc(sizeof(BinaryTree));
        node -> key = ch;
        node -> leftChild = CreateBinaryTree();
        node -> rightChild = CreateBinaryTree();
        return node;
    }
}
void Preorder(BinaryTree *bt)              //pre-order travel
{
    if (!bt) return ;
    printf("%c", bt -> key);
    Preorder(bt -> leftChild);
    Preorder(bt -> rightChild);
}
void Inorder(BinaryTree *bt)               //in-order travel
{
    if (!bt) return ;
    Inorder(bt -> leftChild);
    printf("%c", bt -> key);
    Inorder(bt -> rightChild);
}
void Postorder(BinaryTree *bt)             //post-order travel
{
    if (!bt) return ;
    Postorder(bt -> leftChild);
    Postorder(bt -> rightChild);
    printf("%c", bt -> key);
}
int CountLeaf(BinaryTree *bt)              //count the leaves of the binary tree
{
    if (!bt) return 0;
    else if (!(bt -> leftChild) && !(bt -> rightChild)) return 1;
    else return CountLeaf(bt -> leftChild) + CountLeaf(bt -> rightChild);
}
int CountDepth(BinaryTree *bt)             //count the depth of the binary tree
{
    if (!bt) return 0;
    else if (!(bt -> leftChild) && !(bt -> rightChild)) return 1;
    else return max(CountDepth(bt -> leftChild), CountDepth(bt -> rightChild)) + 1;
}
