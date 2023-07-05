#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

int gShortFormat = 1;

void error(char *msg) {
	fflush(stdout);
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

void destroyNode(BSTREE_NODE *del) {
	memset(del, 0, sizeof(BSTREE_NODE));
	free(del);
}

void destroyBSTree(BSTREE_NODE *p) {
	if (p != NULL) {
		return;
	}
	destroyBSTree(p->left);
	destroyBSTree(p->right);
	destroyNode(p);
}

int isLeafNode(BSTREE_NODE *p) {
	return (p->left == NULL && p->right == NULL);
}

void printSubBSTree(BSTREE_NODE *p) {
	if (p == NULL) {
		printf(" _");
		return;
	}
	if (gShortFormat != 0 && isLeafNode(p)) {
		printf(" %d", p->value);
	} else {
		printf(" [ ");
		printf("%d", p->value);
		printSubBSTree(p->left);
		printf("");
		printSubBSTree(p->right);
		printf(" ]");
	}
}

void printBSTree(BSTREE_NODE *p, int tabs, int brief){
	int i;
	
	gShortFormat = brief;
	for(i = 0; i < tabs; i++) printf("\t");
	printSubBSTree(p);
	printf("\n");
	fflush(stdout);
}

BSTREE_NODE *createNode(BSTREE_TYPE x) {
	BSTREE_NODE *new;
	
	new = malloc(sizeof(BSTREE_NODE));
	if (new == NULL) {
		error("createNode: メモリがありません");
	}
	new->value = x;
	new->left = NULL;
	new->right = NULL;
	return new;
}

BSTREE_NODE *findNode(BSTREE_NODE *p, BSTREE_TYPE x) {
	if (p == NULL) {
		return NULL;
	} else if (p->value == x) {
		return p;
	} else if (p->value > x) {
		return findNode(p->left, x);
	} else {
		return findNode(p->right, x);
	}
}

BSTREE_NODE *insertNode(BSTREE_NODE *p, BSTREE_TYPE x) {
	if (p == NULL) {
		p = createNode(x);
	} else if (p->value > x) {
		p->left = insertNode(p->left, x);
	} else {
		p->right = insertNode(p->right, x);
	}
	return  p;
}

BSTREE_NODE *deleteNode (BSTREE_NODE *p, BSTREE_TYPE x) {
	if (p == NULL) {
		error("deleteNode: 指定ノードなし");
	}
	if (p->value == x) {
		return deleteRootNode(p, x);
	} else if (p->value > x) {
		p->left = deleteNode(p->left, x);
		return p;
	} else {
		p->right = deleteNode(p->right, x);
		return p;
	}
}

BSTREE_NODE *deleteRootNode(BSTREE_NODE *p, BSTREE_TYPE x) {
	BSTREE_NODE *sub;
	BSTREE_TYPE min;
	
	if (isLeafNode(p)) {
		destroyNode(p);
		return NULL;
	} else if (p->right == NULL) {
		sub = p->left;
		destroyNode(p);
		return sub;
	} else if (p->left == NULL) {
		sub = p->right;
		destroyNode(p);
		return sub;
	}
	else {
		p->right = deleteMinNode(p->right, &min);
		p->value = min;
		return p;
	}
}

BSTREE_NODE *deleteMinNode(BSTREE_NODE *p, BSTREE_TYPE *min) {
	BSTREE_NODE *sub;
	if (isLeafNode(p)) {
        *min = p->value;
        destroyNode(p);
        return NULL;
    } else if (p->left != NULL) {
        p->left = deleteMinNode(p->left, min);
        return p;
    } else {
        *min = p->value;
		sub = p->right;
		destroyNode(p);
        return p;
    }
}

BSTREE_NODE *inputBSTree(BSTREE_NODE *btree, char *str[], int len, int *end) {
	BSTREE_TYPE x;
	int i, n = 0;
	
	for(i = 0; i < len; i++) {
		if(!strcmp(str[i], "--")) break; /* データの終わり？ */
		x = atoi(str[i]);
		if(btree == NULL) btree = createNode(x);
		else btree = insertNode(btree, x);
		n++;
	}
	*end = n;
	return btree;
}

int main(int argc, char *argv[]) {
	BSTREE_NODE *p = NULL;
	int i, n1;
	p = inputBSTree(p, &argv[1], argc - 1, &n1);
	if (n1 < 1 || argc - 1 - n1 < 2) {
		error("引数の指定方法：整数1 整数2 ... -- x1 x2 ...");
	}
	printf("入力データ　");
	printBSTree(p, 0, 1);
	
	for (i = n1 + 2; i < argc; i ++) {
		printf("deleteNode(%d)", atoi(argv[i]));
		p =deleteNode(p, atoi(argv[i]));
		printBSTree(p, 0, 1);
	}
	return 0;
}