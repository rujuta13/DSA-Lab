#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void main(){
    FILE *fp; 
    fp = fopen("numbers.txt", "r");

    if(!fp){
        ("Unable to open file");
        return;
    }

    int filesize = 20;
    heap h;
    initHeap(&h, filesize);
    int key;

    for(int i = 0; i < filesize; i ++){
		//reading numbers from input file
		fscanf(fp, "%d", &key); 
        insert(&h, key);
    }

    int ch;
    printf("1. Ascending\n0. Descending\n");
    printf("Enter choice:");
    scanf("%d", &ch);

    printf("Before sorting:\n");
    display(h);

    if(ch == 1)
        HeapSort(&h, 1);
    else if(ch == 0)
        HeapSort(&h, 0);
    else{
        printf("Invalid choice!\n");
        return;
    }
    printf("After sorting:\n");
    display(h);
}