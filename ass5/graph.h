#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph{
    int **A;
    int n;
}graph;

void initGraph(graph *g, char *filename);
void display(graph g);
void displayDegree(graph g);
int isConnected(graph g);
int components(graph g);
int isAdjacent(graph g, int v1, int v2);
void displayCycles(graph g);
void DFS(graph* g, int start, int visited[]);