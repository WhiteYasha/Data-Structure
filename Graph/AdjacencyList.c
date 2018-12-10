//
//  AdjacencyList.c
//  Data Structures
//
//  Created by 倪思涛 on 2018/11/28.
//  Copyright © 2018 倪思涛. All rights reserved.
//

#include "AdjacencyList.h"

//Queue
Queue CreateQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    (*q).front = (*q).back = 0;
    return *q;
}
int IsEmpty(Queue q)
{
    return q.front == q.back;
}
void PushQueue(Queue *q, int key)
{
    (*q).data[(*q).back++] = key;
}
void PopQueue(Queue *q)
{
    (*q).front++;
}

ListGraph CreateListGraph()               //create a new empty list graph
{
    ListGraph *lg = (ListGraph*)malloc(sizeof(ListGraph));
    (*lg).tot = 0;
    for (int i = 0; i < MAX_NODE; i++) (*lg).head[i] = -1, (*lg).indegree[i] = 0;
    return *lg;
}
void AddEdge_List(ListGraph *lg, int u, int v, int w)              //add a new edge
{
    (*lg).e[(*lg).tot] = (edge){v, (*lg).head[u], w};
    (*lg).head[u] = (*lg).tot++;
    (*lg).indegree[v]++;
}
int ShortestPath_List(ListGraph lg, int u, int v)             //shortest path from u to v
{
    //SPFA Algorithm
    int dis[MAX_NODE], vis[MAX_NODE];
    for (int i = 0; i < MAX_NODE; i++) dis[i] = INF, vis[i] = 0;
    dis[u] = 0;
    vis[u] = 1;
    Queue q = CreateQueue();
    PushQueue(&q, u);
    while (!IsEmpty(q)) {
        int now = q.data[q.front];
        PopQueue(&q);
        for (int i = lg.head[now]; i != -1; i = lg.e[i].next) {
            int next = lg.e[i].to;
            if (dis[next] > dis[now] + lg.e[i].len) {
                dis[next] = dis[now] + lg.e[i].len;
                if (!vis[next]) {
                    PushQueue(&q, next);
                    vis[next] = 1;
                }
            }
        }
    }
    if (dis[v] == INF) return -1;               //can't reach
    return dis[v];
}
void TopoSort(ListGraph lg)               //AOV Network Sort
{
    Queue q = CreateQueue();
    int res[MAX_NODE], cnt = 0;
    for (int i = 0; i < MAX_NODE; i++)
        if (!lg.indegree[i] && lg.head[i] != -1) {
            PushQueue(&q, i);
            res[cnt++] = i;
        }
    while (!IsEmpty(q)) {
        int u = q.data[q.front];
        PopQueue(&q);
        for (int i = lg.head[u]; i != -1; i = lg.e[i].next) {
            int v = lg.e[i].to;
            if (--lg.indegree[v] == 0) {
                res[cnt++] = v;
                PushQueue(&q, v);
            }
        }
    }
    for (int i = 0; i < cnt; i++) printf("%d%c", res[i], i == cnt - 1 ? '\n' : ' ');
}
