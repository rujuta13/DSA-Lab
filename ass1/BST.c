<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef node *BST;

void initBST(BST *t){
	*t = NULL;
	return;
}

void insert(BST *t, int key){
	node *nn;
	nn = (node *)malloc(sizeof(node));
	if(!nn) return;
	
	nn -> right = NULL;
	nn -> left = NULL;
	nn -> data = key;
	
	node *p, *q = NULL;
	p = *t;
	
	//tree empty
	if(!p){ 
		*t = nn;
		return;
	}
	
	while(p){
		if(key == p -> data)
			return;
		q = p;
		if(key < p -> data)
			p = p -> left;
		else
			p = p -> right;
	}
	if(key < q -> data)
		q -> left = nn;
	else
		q -> right = nn;
	return;

}

void inorder(BST t){
	if(!t)	return;
	inorder(t -> left);
	printf("%d ", t -> data);
	inorder(t -> right);
}

int searchNode(BST t, int key){
	//if key is found
	//returns number of comparisons taken for search

	node *p;
	int count = 0; //number of comparisons

	p = t;
	if(p == NULL)
		return count;

	while(p){
		count ++;
		if(p -> data == key)
			break;
		if(p ->data < key)
			p = p -> right;
		else
			p = p -> left;
	}

	//number not found
	return count;
	
}

void createBST(BST *t, int size, char fname[]){
	FILE *fp; 
	
	fp = fopen(fname, "r");
	if(fp == NULL)//unable to open file
		return;
		
	char temp[255]; //max size of each number
	
	for(int i = 0; i < size; i ++){
		fscanf(fp, "%s", temp); 
		insert(t, atoi(temp));
	}
	//inorder(*t);
	printf("Binary Search Tree with %d elements created.\n", size);
	fclose(fp);
}	

void search(BST t, int size, char input[], char output[]){
	//size is the size of t
	FILE *fp1; 
	FILE *fp2;     
	fp1 = fopen(input, "r");
	fp2 = fopen(output, "a");
	char key[255];
	for(int i = 0; i < size/10; i ++){
		//reading number to be searched from input file
		fscanf(fp1, "%s", key); 

		//storing search results in output file
		fprintf(fp2, "%d\n", searchNode(t, atoi(key)));
		//fputs("\n",fp2);
	}
	printf("%d elements searched.\n", size);
	fclose(fp1);
	fclose(fp2);
}


void main(){
    BST T1, T2, T3, T4, T5, T6, T7, T8;
	initBST(&T1);
    initBST(&T2);
    initBST(&T3);
    initBST(&T4);
    	
	createBST(&T1, 10, "Tree/tree1.txt");	
    createBST(&T2, 100, "Tree/tree2.txt");	
    createBST(&T3, 1000, "Tree/tree3.txt");
    createBST(&T4, 10000, "Tree/tree4.txt");

	search(T1, 10, "Random Numbers/numbers1.txt", "ResultsBST.csv");
	search(T2, 100, "Random Numbers/numbers2.txt", "ResultsBST.csv");
	search(T3, 1000, "Random Numbers/numbers3.txt", "ResultsBST.csv");
	search(T4, 10000, "Random Numbers/numbers4.txt", "ResultsBST.csv");
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

typedef node *BST;

void initBST(BST *t){
	*t = NULL;
	return;
}

void insert(BST *t, int key){
	node *nn;
	nn = (node *)malloc(sizeof(node));
	if(!nn) return;
	
	nn -> right = NULL;
	nn -> left = NULL;
	nn -> data = key;
	
	node *p, *q = NULL;
	p = *t;
	
	//tree empty
	if(!p){ 
		*t = nn;
		return;
	}
	
	while(p){
		if(key == p -> data)
			return;
		q = p;
		if(key < p -> data)
			p = p -> left;
		else
			p = p -> right;
	}
	if(key < q -> data)
		q -> left = nn;
	else
		q -> right = nn;
	return;

}

void inorder(BST t){
	if(!t)	return;
	inorder(t -> left);
	printf("%d ", t -> data);
	inorder(t -> right);
}

int searchNode(BST t, int key){
	//if key is found
	//returns number of comparisons taken for search

	node *p;
	int count = 0; //number of comparisons

	p = t;
	if(p == NULL)
		return count;

	while(p){
		count ++;
		if(p -> data == key)
			break;
		if(p ->data < key)
			p = p -> right;
		else
			p = p -> left;
	}

	//number not found
	return count;
	
}

void createBST(BST *t, int size, char fname[]){
	FILE *fp; 
	
	fp = fopen(fname, "r");
	if(fp == NULL)//unable to open file
		return;
		
	char temp[255]; //max size of each number
	
	for(int i = 0; i < size; i ++){
		fscanf(fp, "%s", temp); 
		insert(t, atoi(temp));
	}
	//inorder(*t);
	printf("Binary Search Tree with %d elements created.\n", size);
	fclose(fp);
}	

void search(BST t, int size, char input[], char output[]){
	//size is the size of t
	FILE *fp1; 
	FILE *fp2;     
	fp1 = fopen(input, "r");
	fp2 = fopen(output, "a");
	char key[255];
	for(int i = 0; i < size/10; i ++){
		//reading number to be searched from input file
		fscanf(fp1, "%s", key); 

		//storing search results in output file
		fprintf(fp2, "%d\n", searchNode(t, atoi(key)));
		//fputs("\n",fp2);
	}
	printf("%d elements searched.\n", size);
	fclose(fp1);
	fclose(fp2);
}


void main(){
    BST T1, T2, T3, T4, T5, T6, T7, T8;
	initBST(&T1);
    initBST(&T2);
    initBST(&T3);
    initBST(&T4);
    	
	createBST(&T1, 10, "Tree/tree1.txt");	
    createBST(&T2, 100, "Tree/tree2.txt");	
    createBST(&T3, 1000, "Tree/tree3.txt");
    createBST(&T4, 10000, "Tree/tree4.txt");

	search(T1, 10, "Random Numbers/numbers1.txt", "ResultsBST.csv");
	search(T2, 100, "Random Numbers/numbers2.txt", "ResultsBST.csv");
	search(T3, 1000, "Random Numbers/numbers3.txt", "ResultsBST.csv");
	search(T4, 10000, "Random Numbers/numbers4.txt", "ResultsBST.csv");
>>>>>>> aad6c423ea575c2efb7f74f0e94a40d0a591e050
}