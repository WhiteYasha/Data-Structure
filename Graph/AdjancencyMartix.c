//
//  AdjacencyMartix.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "AdjacencyMartix.h"

MartixGraph CreateMartixGraph(int size)                //create a new empty graph
{
    MartixGraph *g = (MartixGraph*)malloc(sizeof(MartixGraph));
    (*g).size = size;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            (*g).map[i][j] = INF;
    return *g;
}
void AddEdge_Martix(MartixGraph *g, int u, int v, int w)               //add a new undirected edge (u,v) weighted w
{
    (*g).map[u][v] = (*g).map[v][u] = w;
}
int ShortestPath(MartixGraph g, int u, int v)              //shortest path between u and v
{
    //Dijkstra Algorithm
    int dis[MAX_SIZE], vis[MAX_SIZE];
    for (int i = 0; i < g.size; i++) dis[i] = g.map[u][i], vis[i] = 0;
    for (int i = 0; i < g.size; i++) {
        int p = -1, minn = INF;
        for (int j = 0; j < g.size; j++)
            if (!vis[j] && dis[j] < minn) minn = dis[p = j];
        if (!p) break;
        vis[p] = 1;
        for (int j = 0; j < g.size; j++)
            if (!vis[j] && dis[j] > dis[p] + g.map[p][j])
                dis[j] = dis[p] + g.map[p][j];
    }
    return dis[v];
}
