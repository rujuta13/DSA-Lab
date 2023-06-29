#include <stdio.h>
#include "header.h"

void main(){
    aBST t;
    initaBST(&t);
    insert(&t, 8);    
	insert(&t, 3);     
	insert(&t, 1);
	insert(&t, 6);
	insert(&t, 4);   
	insert(&t, 7);
	insert(&t, 10);
	insert(&t, 14);
	insert(&t, 13);

    printf("Height: %d\n", height(t));
    printf("Leaf Nodes: %d\n", countLeaf(t));
    printf("Complete? %d\n", isComplete(t));
    printf("Level Order:");
    levelorder(t);
}