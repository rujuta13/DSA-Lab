#include <stdio.h>
#include <stdlib.h>
#include "heapsort.h"

void HeapSort(heap *h, int order){
    int temp;
    int end = h->last;
    while(h->last != -1){ //while heap is not empty 
        temp = deleteHeap(h);
        h->A[h->last + 1] = temp;
    }
    h->last = end;
    if(order == 1) //ascending
        return;

    //descending
    int i = 0, j = end;
    while(i<j){
        swap(&h->A[i], &h->A[j]);
        i ++;
        j --;
    } 
}
