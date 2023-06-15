#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	int data;
	struct cell *next;
}CELL;

CELL head;

void InsertCell(int x){
	CELL *p, *new;
	new = (CELL *)malloc(sizeof(CELL));
	new->data = x;
	for (p = &head; p->next != NULL; p = p->next) {
		if (new->data < (p->next)->data) {
			new->next = p->next;
			p->next = new;
			return;
		}else if (new->data == (p->next)->data) {
			return;
		}
	}
	new->next = NULL;
	p->next = new;
}

void PrintList(){
	CELL *p;
	for (p = &head; p->next != NULL; p = p->next) {
		printf("%d", (p->next)->data);
	}
	printf("\n");
}

int main(void){
	int x;

	while (1) {
		printf("整数を入力してください： ");
		scanf("%d", &x);
		if (x == 0) {
			break;
		}
		InsertCell(x);
	}
	PrintList();
	return 0;
}