#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "header.h"

int power2(int x){
    int res = 1;
    for(int i = 1; i <= x; i++){
        res *= 2;
    }
    return res;
}

void initaBST(aBST *t){
    t->A = NULL;
    t->s = 0;
    t->rear = -1;
}

void insert(aBST *t, int key){
    int p = 0;

    //root node
    if(t->s == 0){
        t->A = (int *)malloc(sizeof(int));
        if(!(t->A))
            return;
        t->A[0] = key;
        (t->s) ++;
        t->rear = 0;
        return;
    }

    while(p < t->s && t->A[p] != INT_MIN){
        if(key == t->A[p])
            return;
        if(key < t->A[p])
            p = 2*p + 1;
        else
            p = 2*p + 2;
    }
    if(p < t->s && t->A[p] == INT_MIN){
        t->A[p] = key;
        if(p > t->rear)
            t->rear = p;
        return;
    }

    //no space left
    t->A = realloc(t->A, (p+1)*sizeof(int));
    if(!(t->A))
        return;
    
    for(int i = t->s; i < p; i++)
        t->A[i] = INT_MIN;
    
    t->A[p] = key;
    if(p > t->rear)
        t->rear = p;
    t->s = p+1;
}

int height(aBST t){
    int i, height = 0;

    //tree is empty
    if(t.A[0] == INT_MIN)
        return -1;

    //find last node in the array
    for(i = t.s - 1; i >= 0; i--){
        if(t.A[i] != INT_MIN) 
            break;
    }
    // i is the index at which last
    // node is present

    //retracing till node
    while(i){
        i = (i- 1) / 2;        
        height++;
    }
    return height;
}

int countLeaf(aBST t){
    //tree empty
    if(t.A[0] == INT_MIN)
        return 0;

    //only root
    if(t.s == 1)
        return 1;
    
    int count = 0;
    for(int i = t.rear; i>=0; i--){
        if(t.A[i] != INT_MIN){ 
            if(2*i + 1 >= t.s)
                count++;
            else if(t.A[2*i + 1] == INT_MIN && t.A[2*i + 2] == INT_MIN)
                count++;
        }
    }
    return count;
}

int isComplete(aBST t){
	int flag = 1;
	for (int i = 0; i < t.s ; i++){
		if (t.A[i] == INT_MIN && t.A[i + 1] != INT_MIN){
			flag = 0;
			break;
		}
	}
	return flag;
}

void levelorder(aBST t){
    int order = 1;
    printf("\n");
    for (int i = 0; i <= t.rear; i++){
		if(t.A[i] != INT_MIN)
            printf("%d ",t.A[i]);               
		if(i >= (power2(order) - 2)){
		     printf("\n");
		     order++;
        } 
    }        
}