#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct heap{
    int *A;
    int s;
    int last;
}heap;

void initHeap(heap *h, int s);
void display(heap h);
void insert(heap *h, int key);
int deleteHeap(heap *h);
void HeapSort(heap *h, int order);
