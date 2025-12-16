#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct adjacencyList {
    int weight;
    struct adjacencyList *next;
} adjacencyList;

typedef struct vertex {
    int label;
    adjacencyList *adjList;
} vertex;

typedef struct {
    vertex *vertexList;
    int n;
} graph;

adjacencyList *adjacencyListPushEdge(vertex *head, int weight);

void adjacencyListDestroy(vertex *head);

graph *graphCreate(int n);

void graphDestroy(graph g);

void Dijkstra(graph g, vertex source, graph *spanningTree);

#endif //GRAPH_H
