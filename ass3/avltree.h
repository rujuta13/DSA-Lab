#define MAX 15
typedef struct node{
    char *data;
    struct node *parent, *left, *right;
    int bf;
}node;

typedef node * AVL;
void createTree(AVL *t, char *filename, int s);
void initAVL(AVL *t);
void traverse(AVL t);
void insertNode(AVL *t, char *key);
node *removeNode(AVL *t, char *key);
node *destroyTree(AVL t);