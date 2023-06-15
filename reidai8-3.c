#include <stdio.h>
#include <stdlib.h>

struct cell {
	int element;
	struct cell *next;
};

struct cell *init;

struct cell *push(int x, struct cell *init) {
	struct cell *q, *r;
	
	r = (struct cell *)malloc(sizeof(struct cell));
	q =init;
	init = r;
	r->element = x;
	r->next = q;
	return (init);
}

struct cell *pop(struct cell *init, int i) {
	struct cell *q, *r;
	if (init != NULL) {
		q = init;
		printf("pop %d回目 %dをpopします。\n", i, q->element);
		init = init->next;
		free(q);
		return (init);
	}
	else {
		printf("Error: Stack is empty.\n");
		exit(1);
	}
}


void printstack() {
	struct cell *s;
	s = init;
	
	printf("スタックの中 [");
	while (init != NULL) {
		printf("%d", init->element);
		init = init->next;
		
		if (init != NULL) {
			printf(" ");
		}
	}
	printf("]\n");
	
	init = s;
}

int main(void) {
	int x;
	
	while (1) {
		printf("整数を入力してください。\n");
		scanf("%d", &x);
		if (x == 0) {
			break;
		}else {
			init = push(x, init);
			printstack();
		}
	}
	int i = 1;
	while (init != NULL) {
		init = pop(init, i);
		i ++;
	}
	return 0;
}