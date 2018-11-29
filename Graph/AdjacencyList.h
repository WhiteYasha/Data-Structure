//
//  AdjacencyList.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/28.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef AdjacencyList_h
#define AdjacencyList_h

//adjacency list weighted directed graph (array form)

#include <stdio.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f
#define MAX_NODE 30
#define MAX_EDGE MAX_NODE * MAX_NODE / 2

typedef struct edge {
    int to, next, len;
} edge;
typedef struct Queue {
    int data[MAX_EDGE];
    int front, back;
} Queue;
typedef struct ListGraph {
    edge e[MAX_EDGE];
    int head[MAX_NODE];
    int indegree[MAX_NODE];
    int tot;
} ListGraph;

ListGraph CreateListGraph();               //create a new empty list graph
void AddEdge_List(ListGraph *lg, int u, int v, int w);              //add a new edge
int ShortestPath_List(ListGraph lg, int u, int v);             //shortest path from u to v
void TopoSort(ListGraph lg);               //AOV Network Sort

#endif /* AdjacencyList_h */
