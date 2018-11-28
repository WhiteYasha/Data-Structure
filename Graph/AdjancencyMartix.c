//
//  AdjacencyMartix.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/27.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "AdjacencyMartix.h"

//Union Find
UnionFind CreateUnionFind()
{
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    for (int i = 0; i < MAX_SIZE; i++) (*uf).fa[i] = i;
    return *uf;
}
int FindFather(UnionFind *uf, int x)
{
    return (*uf).fa[x] == x ? x : ((*uf).fa[x] = FindFather(uf, (*uf).fa[x]));
}
void MergeFather(UnionFind *uf, int x, int y)
{
    int fx = FindFather(uf, x), fy = FindFather(uf, y);
    if (fx != fy) (*uf).fa[fx] = fy;
}
//
int cmp(const void *a, const void *b)
{
    return (*(edge *)a).w - (*(edge *)b).w;
}

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
int ShortestPath_Martix(MartixGraph g, int u, int v)              //shortest path between u and v
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
int MinCostSpanTree(MartixGraph g)             //minimum cost spaning tree
{
    //Kruskal Algorithm
    UnionFind uf = CreateUnionFind();
    edge e[g.size * g.size];
    int tot = 0, res = 0;
    for (int i = 0; i < g.size; i++)
        for (int j = 0; j < g.size; j++)
            if (g.map[i][j] != INF) e[tot++] = (edge){i, j, g.map[i][j]};
    qsort(e, tot, sizeof(edge), cmp);
    for (int i = 0; i < tot; i++) {
        if (FindFather(&uf, e[i].u) != FindFather(&uf, e[i].v)) {
            MergeFather(&uf, e[i].u, e[i].v);
            res += e[i].w;
        }
    }
    for (int i = 0; i < g.size; i++)
        if (FindFather(&uf, i) != FindFather(&uf, 0))
            return -1;              //graph disconnected
    return res;
}
