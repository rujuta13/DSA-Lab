#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

void main(){    
    AVL t;
	initAVL(&t);
    createTree(&t, "testnames.txt", 8);

    char* key;
    int ch;
    
    do{
        printf("MENU\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Traverse\n");
        printf("4. Destroy\n");
        printf("5. Quit\n");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:{
                key = (char *)malloc(sizeof(char)*MAX);
                printf("Enter name to enter: ");
                scanf("%s", key);
                insertNode(&t, key);
            }
            break;
            case 2:{
                key = (char *)malloc(sizeof(char)*MAX);
                printf("Enter name to remove: ");
                scanf("%s", key);
                t = removeNode(&t, key);
            }
            break;
            case 3: traverse(t);
            break;
            case 4: t = destroyTree(t);
            break;
            case 5: break;
            default: printf("Please enter a valid no.: ");
        }
    }
    while(ch!=5);

}