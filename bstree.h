typedef int BSTREE_TYPE; /* 格納データの型 */

struct bsnode {
   BSTREE_TYPE value;    /* ノードの値 */
   struct bsnode *left;  /* 左ノードのアドレス */
   struct bsnode *right; /* 右ノードのアドレス */
};
typedef struct bsnode BSTREE_NODE;

void error(char *msg);
void destroyNode(BSTREE_NODE *del);
void destroyBSTree(BSTREE_NODE *p);

int isLeafNode(BSTREE_NODE *p);
void printSubBSTree(BSTREE_NODE *p);
void printBSTree(BSTREE_NODE *p, int tabs, int brief);

BSTREE_NODE *createNode(BSTREE_TYPE x);
BSTREE_NODE *findNode(BSTREE_NODE *p,BSTREE_TYPE x);
BSTREE_NODE *insertNode(BSTREE_NODE *p,BSTREE_TYPE x);
BSTREE_NODE *deleteNode(BSTREE_NODE *p,BSTREE_TYPE x);
BSTREE_NODE *deleteRootNode(BSTREE_NODE *p, BSTREE_TYPE x);
BSTREE_NODE *inputBSTree(BSTREE_NODE *btree, char *str[], int len, int *end);

BSTREE_NODE *deleteMinNode(BSTREE_NODE *p, BSTREE_TYPE *min);

