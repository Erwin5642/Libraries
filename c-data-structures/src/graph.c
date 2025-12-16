//
// Created by jvgam on 21/10/2025.
//

#include "graph.h"
#include "vector.h"

adjacencyList *adjacentListPushEdge(vertex *head, const int weight) {
    adjacencyList *newEdge = malloc(sizeof(adjacencyList));

    newEdge->weight = weight;
    newEdge->next = head->adjList;
    head->adjList = newEdge;
    return newEdge;
}

void adjacencyListDestroy(vertex *head) {
    adjacencyList *current = head->adjList;
    while (current) {
        adjacencyList *next = current->next;
        free(current);
        current = next;
    }
    head->adjList = NULL;
}

graph *createGraph(const int vertexCount) {
    graph *newGraph = malloc(sizeof(graph));
    newGraph->n = vertexCount;
    newGraph->vertexList = malloc(sizeof(vertex) * vertexCount);
    return newGraph;
}

void graphDestroy(graph g) {
    for (int i = 0; i < g.n; i++) {
        adjacencyListDestroy(&g.vertexList[i]);
    }
    free(g.vertexList);
}