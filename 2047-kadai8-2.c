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

struct cell *pop(struct cell *init) {
	struct cell *q, *r;
	if (init != NULL) {
		q = init;
		printf("ポップします。\n");
		init = init->next;
		free(q);
		return (init);
	}
	else {
		printf("スタックは空のためポップできません。\n");
		return (init);
	}
}


void printstack() {
	struct cell *q;
	q = init;
	
	printf("スタックの中 [");
	while (q != NULL) {
		printf("%d", q->element);
		q = q->next;
		
		if (q != NULL) {
			printf(" ");
		}
	}
	printf("]\n");
}

void printstachaddress(struct cell *init) {
	struct cell *q;
	q = init;
	printf("スタックの中　[");
	while (q != NULL) {
		printf("%p", q->next);
		q = q->next;
		
		if (q != NULL) {
			printf(" ");
		}
	}
	printf("]\n");
}

int command(int c){
	int x;
	switch (c) {
		case 1:
			printf("プッシュする整数を入力してください。\n");
			scanf("%d", &x);
			init = push(x,init);
			return 1;
		case 2:
			init = pop(init);
			return 1;
		case 3:
			printstack();
			return 1;
		case 4:
			printstachaddress(init);
			return 1;
		case 5:
			printf("終了します\n");
			return 0;
		default:
			printf("１から5までの番号を入力してください。\n");
			return 1;
	}
}

int main(void) {
	int c;
	
	
	while (1) {
		printf("番号を入力してください。 (1)PUSH, (2)POP, (3)SHOW, (4)SHOW(address), (5)EXIT>");
		scanf("%d", &c);
		if (!command(c)) {
			break;
		}
	}
	
	return 0;
}