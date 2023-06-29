typedef struct aBST{
    int *A;
    int s;
    int rear;
} aBST;

void initaBST(aBST *t);
void insert(aBST *t, int key);
int height(aBST t);
int countLeaf(aBST t);
int isComplete(aBST t);
void levelorder(aBST t);