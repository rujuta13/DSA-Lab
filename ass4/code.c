#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <limits.h>

void initHeap(heap *h, int s){
    h->s = s;
    h->A = (int *)malloc(sizeof(int) * h->s);
    h->last = -1;
}

void display(heap h){
    for (int i = 0; i <= h.last; i++)
		printf("%d ",h.A[i]);
    printf("\n");        
}

void swap(int *n1, int *n2){
    int temp = *n2;
    *n2 = *n1;
    *n1 = temp;
}

void adjust_max(heap *h){
    //parent = (child-1)//2 (floor div 2)
    int i = h->last;
   
    int parent;
    int temp;
    while(i > 0){
        parent = (i-1)/2;
        if(h->A[parent] < h->A[i])
            swap(&h->A[parent], &h->A[i]);
        else    
            return;
        i = (i-1)/2;
    }
    return;
}

void heapify_max(heap *h){
    int i = 0;
    int temp;
    int largest, lc, rc;
    // largest is the index of the largest node
    while(i <= h->last){
         //compare children
        lc = 2*i + 1; //left
        rc = 2*i + 2; //right

        largest = i; 
        //finding largest among both children
        if(lc <= h->last && h->A[lc] > h->A[largest])
            largest = lc;
        if(rc <= h->last && h->A[rc] > h->A[largest])
            largest = rc;

        //swapping if largest child is bigger than the current node
        if(h->A[largest] > h->A[i]){
            swap(&h->A[largest], &h->A[i]);
            i = largest;
        }
        else  //already a heap
            break;
    }
}

void insert(heap *h, int key){
    if(!h->A)
        return;
   //insert at (last+1)th location to preserve completeness
   h->A[++h->last] = key;
   int parent = h->A[(h->last-1)/2];

    //adjust only if newly added number is > parent
    if(key > parent)
        adjust_max(h);
    return;
}

int deleteHeap(heap *h){
    //root is always deleted

    if(!h->A) //array not created
        return INT_MIN;
        
    if(h->last == -1) //heap empty
        return INT_MIN;
    
    int value = h->A[0];
    h->A[0] = h->A[h->last]; //last element now root
    //swap(&h->A[0], &h->A[h->last]);
    h->last --;
    
    heapify_max(h);
    return value;
}
