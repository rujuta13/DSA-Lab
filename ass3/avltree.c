#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"
#include <string.h>

void initAVL(AVL *t){
    *t = NULL; 
}

node * createNode(char *key){
    node *nn;
	nn = (node *)malloc(sizeof(node));
	if(!nn) 
        return NULL;
	
    nn -> data = key;
	nn -> right = NULL;
	nn -> left = NULL;
	nn -> parent = NULL;
    nn->bf = 0;
    return nn;
}

int height(AVL t) {
    //if tree empty or only root
	if(t == NULL)
		return -1;

    if(t->left == NULL && t->right == NULL)
        return 0;

    int lHeight = height(t -> left);
    int rHeight = height(t -> right);
    
    //max height is the height
    if(lHeight >= rHeight)
        return lHeight + 1;
    else 
        return rHeight + 1;
}

void traverse(AVL t){
	if(!t)	return;
	traverse(t -> left);
    if(t->parent)
	    printf("name: %s  bf: %d  parent: %s\n", t -> data, t->bf, t->parent->data);
    else
        printf("name: %s  bf: %d  parent: NULL\n", t -> data, t->bf);
	traverse(t -> right);
}

void updateBF(AVL *t){
    //newly added node's parent is passed as arg
    node *p = *t;

    while(p){
        p->bf = height(p->left) - height(p->right);
        p = p->parent;
    }
}

node * getImbalance(node *n){
    node *p = n;
    node *im;
    //find imbalanced node
    while(p){
        if(p->bf == -2 || p->bf == 2){
            im = p;
            return im;
        }
        p = p->parent;
    }
    return NULL;
}

void LLrotate(AVL *t, node *im){
    //imbalanced node is given as one parameter
    node *A = im;
    node *B = A -> left;
    node *Br = B ->right;
    node *Ap = A -> parent;

    //handling B's connection to its parent
    if(!Ap) //root is imbalanced (Ap is null)
        *t = B;
    else if(Ap->left == A) // A is on left of Ap
        Ap->left = B;
    else
        Ap->right = B;
    
    B->parent = Ap;

    B->right = A;
    A->parent = B;

    A->left = Br;
    if(Br)
        Br->parent = A;
    
    updateBF(&A);
    updateBF(&B);
    return;
}

void RRrotate(AVL *t, node *im){
    //imbalanced node is given as one parameter
    node *A = im;
    node *B = A -> right;
    node *Bl = B ->left;
    node *Ap = A -> parent;

    //handling B's connection to its parent

    //root is imbalanced (Ap is null)
    if(!Ap) 
        *t = B;
    // A is on left of Ap
    else if(Ap->left == A) 
        Ap->left = B;
    // A is on right of Ap
    else
        Ap->right = B;
    
    B->parent = Ap;

    B->left = A;
    A->parent = B;

    A->right = Bl;
    if(Bl)
        Bl->parent = A;

    
    updateBF(&A);
    updateBF(&B);
    return;
}

void LRrotate(AVL *t, node *im){
    RRrotate(t, im->left);
    LLrotate(t, im);
}

void RLrotate(AVL *t, node *im){
    LLrotate(t, im->right);
    RRrotate(t, im);
}

void balanceTree(AVL *t, node *nn){
    node *im; //imbalanced node
    im = getImbalance(nn);
    if(!im)
        return;

    //imbalance is there
    //left imbalance
    if(im->bf == 2){
        if(strcmp(nn->data, im->left->data) < 0) 
            LLrotate(t, im);
        else
            LRrotate(t,im);//printf("LR\n");
    }
    else if(im->bf == -2){
        if(strcmp(nn->data, im->right->data) < 0)
            RLrotate(t,im); //printf("RL\n");
        else
            RRrotate(t, im); //printf("RR\n");
    }
}

void insertNode(AVL *t, char *key){
	node *nn;
    nn = createNode(key);
	//tree empty
	if(!(*t)){ 
		*t = nn;
		return;
	}
	node *p, *q = NULL;
	p = *t;

	while(p){
		if(strcmp(key,p->data) == 0){ //equal
            free(nn);
			return;
        }
		q = p;
		if(strcmp(key,p->data) < 0){ //key is smaller
			p = p -> left;
        }
		else{
			p = p -> right;
        }
	}
    //q points to a leaf node now
    nn->parent = q;
    //attach new node
	if(strcmp(key,q->data) < 0) //key is smaller
		q -> left = nn;
	else
		q -> right = nn;
    //node now inserted
    
    //update BF's
    updateBF(&(nn->parent));
    // we now adjust the imbalances
    balanceTree(t, nn);
    return;
}

void createTree(AVL *t, char *filename, int s){
    FILE *fp; 
    fp = fopen(filename, "r");

    if(!fp){
        ("Unable to open file");
        return;
    }
    
    char *name;
    for(int i = 0; i < s; i ++){
        name = (char *)malloc(sizeof(char)*MAX);
		//reading names input file
		fscanf(fp, "%s", name); 
        //fscanf(fp, " %[^\n]", name);
        insertNode(t, name);
    }
    fclose(fp);
}

node *inorderPre(AVL t, node *p){
	if(p->right == NULL)
		return p;

	while(p->right != NULL){
		p = p->right;
	}
	return p;
}

node *removeNode(AVL *t, char *key){
    //tree empty
    if(*t == NULL)
		return *t;

    node *p = *t;
    while (p) {
        if(strcmp(key, p->data) == 0)//key found
			break;
        if (strcmp(key, p->data) < 0) //key smaller than data
            p = p->left;
        else //key bigger than data
            p = p->right;
    }
    //now p points to node to be deleted

    if (!p) //no element found
        return *t;

    //leaf node
    if (!p->left && !p->right){
        //p is root node and the only node
        if (p == *t)
            *t = NULL;
        else {
            if (p->parent->left == p) //p is left child
                p->parent->left = NULL;
            else //p is the right child
                p->parent->right = NULL;

            updateBF(&p->parent);
            balanceTree(t, p->parent);
        }
        free(p->data);
        free(p);
    }

    //one child
    else if(p->left && !p->right){
        if (p->parent->left == p)
            p->parent->left = p->left;
        else
            p->parent->right = p->left;
        updateBF(&p->left->parent);
        balanceTree(t, p->left->parent);  
        free(p->data);
        free(p);
        return *t;
    }
    else if (!p->left && p->right){
        if (p->parent->left == p)
            p->parent->left = p->right;
        else
            p->parent->right = p->right;
            
        updateBF(&p->right->parent);
        balanceTree(t, p->right->parent);  
        free(p->data);
        free(p);
        return *t;
    }

    //two children
    else {
        node* inP = inorderPre(*t, p->left);
        //free(p->data);

        //p->data = malloc(strlen(inP->data) + 1);
        strcpy(p->data, inP->data);
        
        return removeNode(&(p->left), inP->data);
    }
    return *t;
}

node *destroyTree(AVL t){
    if(!t) //tree is empty
        return NULL; 

    node *t1;
    t1 = destroyTree(t->left);
    t1 = destroyTree(t->left);
    free(t1);
    return NULL;
}