//
//  AdjancencyMartix.h
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#ifndef AdjancencyMartix_h
#define AdjancencyMartix_h

//adjancency martix weighted undirected graph

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define INF 0x3f3f3f3f

typedef struct MartixGraph {
    int size;
    int map[MAX_SIZE][MAX_SIZE];
} MartixGraph;

MartixGraph CreateMartixGraph(int size);                //create a new empty graph
void AddEdge_Martix(MartixGraph *g, int u, int v, int w);               //add a new undirected edge (u,v) weighted w
int ShortestPath(MartixGraph g, int u, int v);              //shortest path between u and v

#endif /* AdjancencyMartix_h */
