<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef node *BT;

void initBT(BT *t){
	*t = NULL;
	return;
}

node *createNode(int value) {
    node *nn = malloc(sizeof(struct node));
    nn -> data = value;
    nn -> left = NULL;
    nn -> right = NULL;

    return nn;
}

/*
// Insert on the left of the node
void insertLeft(BT *t, int value) {
    (*t) -> left = createNode(value);
}

// Insert on the right of the node
void insertRight(BT *t, int value) {
    (*t) -> right = createNode(value);
}*/

void inorder(BT t){
	if(!t)	
        return;
	inorder(t -> left);
	printf("%d ", t -> data);
	inorder(t -> right);
}

int countNodes(BT t){
	if(t == NULL)
		return 0;
	return 1 + countNodes(t->left) + countNodes(t->right);
}

int coinToss(){
    int num = (rand() % 2) ;
    return num;
}

void createBT(BT *t, char fname[], int size){
    FILE *fp; 
    fp = fopen(fname, "r");
	if(fp == NULL)//unable to open file
		return;
		
    node *p, *nn;
    int currCount, i = 0, res;
    char temp[255]; //max size of each number

    if(*t == NULL){
        fscanf(fp, "%s", temp);
        *t = createNode(atoi(temp));
    }

    p = *t; 
    fscanf(fp, "%s", temp); 
    nn = createNode(atoi(temp));

    while(countNodes(*t) < size){
        currCount = countNodes(*t);
        
        //move left if 0
		if(coinToss() == 0){
            if(p->left == NULL)
                p -> left = nn;
            else
                p = p -> left;
        }
    
        //move right if 1
        else{
            if(p->right == NULL)
                p -> right = nn;
            else
                p = p -> right;
        }

        //scan new number ONLY if node has been added
        if(countNodes(*t) > currCount){
            fscanf(fp, "%s", temp); 
            nn = createNode(atoi(temp));
        }
	}
    
	printf("Binary Tree with %d elements created.\n", size);
    fclose(fp);
}

int tree2array(BT t, int A[], int i)
{
     if(t == NULL)
          return i;

     
     if(t->left != NULL)
          i = tree2array(t->left, A, i);

    A[i] = t->data;
     i++;

     if(t->right != NULL)
          i = tree2array(t->right, A, i);

     return i;
}

int LinSearch(int A[], int s, int key){
    int count = 0;
	for(int i = 0; i < s; i++){
        count ++;
		if( key == A[i]){
			break;
		}
	}	
	return count;
}

int searchBT(BT t, int size, char input[], char output[]){
    int A[size];
    tree2array(t, A, 0);
    
    FILE *fp1; 
	FILE *fp2;    

	fp1 = fopen(input, "r");
	fp2 = fopen(output, "a");

	char key[255];

	for(int i = 0; i < size/10; i ++){
        //reading number to be searched from input file
		fscanf(fp1, "%s", key); 

		//storing search results for linear search in output file
		fprintf(fp2, "%d\n", LinSearch(A, size, atoi(key)));
		//fputs("\n",fp2);

	}
    printf("%d elements searched.\n", size);
	fclose(fp1);
	fclose(fp2);
}

void main(){
    srand(time(0));

    BT t1, t2, t3, t4, t5;
    initBT(&t1);
    initBT(&t2);
    initBT(&t3);
    initBT(&t4);
    initBT(&t5);

    createBT(&t1, "Tree/tree1.txt", 10);
    createBT(&t2, "Tree/tree2.txt", 100);
    createBT(&t3, "Tree/tree3.txt", 1000);
    createBT(&t4, "Tree/tree4.txt", 10000);
    
    searchBT(t1, 10, "Random Numbers/numbers1.txt", "ResultsBT.csv");
	searchBT(t2, 100, "Random Numbers/numbers2.txt", "ResultsBT.csv");
	searchBT(t3, 1000, "Random Numbers/numbers3.txt", "ResultsBT.csv");
	searchBT(t4, 10000, "Random Numbers/numbers4.txt", "ResultsBT.csv");
    
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef node *BT;

void initBT(BT *t){
	*t = NULL;
	return;
}

node *createNode(int value) {
    node *nn = malloc(sizeof(struct node));
    nn -> data = value;
    nn -> left = NULL;
    nn -> right = NULL;

    return nn;
}

/*
// Insert on the left of the node
void insertLeft(BT *t, int value) {
    (*t) -> left = createNode(value);
}

// Insert on the right of the node
void insertRight(BT *t, int value) {
    (*t) -> right = createNode(value);
}*/

void inorder(BT t){
	if(!t)	
        return;
	inorder(t -> left);
	printf("%d ", t -> data);
	inorder(t -> right);
}

int countNodes(BT t){
	if(t == NULL)
		return 0;
	return 1 + countNodes(t->left) + countNodes(t->right);
}

int coinToss(){
    int num = (rand() % 2) ;
    return num;
}

void createBT(BT *t, char fname[], int size){
    FILE *fp; 
    fp = fopen(fname, "r");
	if(fp == NULL)//unable to open file
		return;
		
    node *p, *nn;
    int currCount, i = 0, res;
    char temp[255]; //max size of each number

    if(*t == NULL){
        fscanf(fp, "%s", temp);
        *t = createNode(atoi(temp));
    }

    p = *t; 
    fscanf(fp, "%s", temp); 
    nn = createNode(atoi(temp));

    while(countNodes(*t) < size){
        currCount = countNodes(*t);
        
        //move left if 0
		if(coinToss() == 0){
            if(p->left == NULL)
                p -> left = nn;
            else
                p = p -> left;
        }
    
        //move right if 1
        else{
            if(p->right == NULL)
                p -> right = nn;
            else
                p = p -> right;
        }

        //scan new number ONLY if node has been added
        if(countNodes(*t) > currCount){
            fscanf(fp, "%s", temp); 
            nn = createNode(atoi(temp));
        }
	}
    
	printf("Binary Tree with %d elements created.\n", size);
    fclose(fp);
}

int tree2array(BT t, int A[], int i)
{
     if(t == NULL)
          return i;

     
     if(t->left != NULL)
          i = tree2array(t->left, A, i);

    A[i] = t->data;
     i++;

     if(t->right != NULL)
          i = tree2array(t->right, A, i);

     return i;
}

int LinSearch(int A[], int s, int key){
    int count = 0;
	for(int i = 0; i < s; i++){
        count ++;
		if( key == A[i]){
			break;
		}
	}	
	return count;
}

int searchBT(BT t, int size, char input[], char output[]){
    int A[size];
    tree2array(t, A, 0);
    
    FILE *fp1; 
	FILE *fp2;    

	fp1 = fopen(input, "r");
	fp2 = fopen(output, "a");

	char key[255];

	for(int i = 0; i < size/10; i ++){
        //reading number to be searched from input file
		fscanf(fp1, "%s", key); 

		//storing search results for linear search in output file
		fprintf(fp2, "%d\n", LinSearch(A, size, atoi(key)));
		//fputs("\n",fp2);

	}
    printf("%d elements searched.\n", size);
	fclose(fp1);
	fclose(fp2);
}

void main(){
    srand(time(0));

    BT t1, t2, t3, t4, t5;
    initBT(&t1);
    initBT(&t2);
    initBT(&t3);
    initBT(&t4);
    initBT(&t5);

    createBT(&t1, "Tree/tree1.txt", 10);
    createBT(&t2, "Tree/tree2.txt", 100);
    createBT(&t3, "Tree/tree3.txt", 1000);
    createBT(&t4, "Tree/tree4.txt", 10000);
    
    searchBT(t1, 10, "Random Numbers/numbers1.txt", "ResultsBT.csv");
	searchBT(t2, 100, "Random Numbers/numbers2.txt", "ResultsBT.csv");
	searchBT(t3, 1000, "Random Numbers/numbers3.txt", "ResultsBT.csv");
	searchBT(t4, 10000, "Random Numbers/numbers4.txt", "ResultsBT.csv");
    
>>>>>>> aad6c423ea575c2efb7f74f0e94a40d0a591e050
}