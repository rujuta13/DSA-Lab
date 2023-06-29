#include "graph.h"
#define MAX 30

void main(int s, char *A[]){
    //filenameas cmdline arg
    graph g;
    int n = strlen(A[1]);
    char *fname = (char *)malloc(sizeof(char) * n);
    strcpy(fname, A[1]);
    initGraph(&g, fname);
    printf("Graph:\n");
    display(g);
    printf("\nDegrees:\n");
    displayDegree(g);
    printf("\nConnected? %d\n", isConnected(g));
    printf("\nComponents\n");
    printf("\nNo. of components: %d\n", components(g));
    printf("\nAdjacent? %d\n", isAdjacent(g, 0, 1));   
    printf("\nCycles:\n");
    displayCycles(g);  
}

