#include "graph.h"

void initGraph(graph *g, char *filename){
    FILE *fp = fopen(filename, "r");
    if(!fp)
        return;
    fscanf(fp, "%d", &g->n);
    g->A = (int **)malloc(g->n * sizeof(int *));
    for(int i =0; i < g->n ; i++){
        g->A[i] = (int *)malloc(g->n * sizeof(int));
        for(int j = 0; j < g->n; j++){
            fscanf(fp, "%d", &g->A[i][j]);
        }
    }
}
void display(graph g){
	for(int i = 0; i < g.n; i ++){
		for(int j = 0; j < g.n; j ++)
			printf("%d ", g.A[i][j]);
		printf("\n");
	}
}

void displayDegree(graph g){
	int deg;
	//int *dArr = (int *)calloc(g.n, sizeof(int));
	for(int i = 0; i < g.n; i ++){
		deg = 0;
		printf("Vertex: %d", i);
		for(int j = 0; j < g.n; j ++){
			if(g.A[i][j] != 0)
				deg ++;
		}
		//dArr[i] = deg;
		printf("  Degree: %d\n", deg);
	}
}

void DFS(graph* g, int start, int visited[]) {
    printf("%d ", start);
	//mark start as visited
    visited[start] = 1;
    for (int j = 0; j < g->n; j++) {
        if (g->A[start][j] && visited[j] == 0) 
            DFS(g, j, visited);
    }
}

void nonprintDFS(graph* g, int start, int visited[]) {
	//mark start as visited
    visited[start] = 1;
    for (int j = 0; j < g->n; j++) {
        if (g->A[start][j] && visited[j] == 0) 
            nonprintDFS(g, j, visited);
    }
}

int isConnected(graph g){
	int count = 0;
	int *visited = (int *)calloc(g.n, sizeof(int));

	for(int i = 0; i < g.n; i++){
		if(!visited[i]){
		//will only increment count if not visited
		//thus no. of components = count			
			nonprintDFS(&g, i, visited);
			count ++;
		}
	}

	//count = no. of components
	if(count > 1)
		return 0;
	return 1;
}


int components(graph g){
	int count = 0;
	int *visited = (int *)calloc(g.n, sizeof(int));

	for(int i = 0; i < g.n; i++){
		if(!visited[i]){
		//will only increment count if not visited
		//thus no. of components = count			
			DFS(&g, i, visited);
			printf("\n");
			count ++;
		}
	}
	return count;
}

int isAdjacent(graph g, int v1, int v2){
	//true if there is an edge from v1 to v2
	if(g.A[v1][v2]) 
		return 1;
	return 0;
}

void displayCycles(graph g){
	int *visited = (int *)calloc(g.n, sizeof(int));
	for(int i = 0; i < g.n; i++){
		if(!visited[i]){
			DFS(&g, i, visited);
			printf("\n");
		}
	}
}