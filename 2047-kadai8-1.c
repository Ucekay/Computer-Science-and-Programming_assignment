#include <stdio.h>
#define STACK_SIZE 5

int array[STACK_SIZE];
int stack_ptr = 0;

void initstack(void) {
	stack_ptr = 0;
}

int chkempty(void) {
	return stack_ptr == 0;
}

int chkfull(void) {
	return stack_ptr == STACK_SIZE;
}

void push(int x) {
	array[stack_ptr] = x;
	stack_ptr ++;
}

void pop(void) {
	stack_ptr --;
	printf("%dをポップしました。", array[stack_ptr]);
}

void printstack(void) {
	int i;
	
	printf("スタックの中 [");
	for (i = 0; i < stack_ptr; i ++) {
		printf("%d", array[i]);
		if (i != stack_ptr - 1) {
			printf(" ");
		}
	}
	printf("]\n");
}

int command(int c){
	switch (c) {
		case 1:
			if (!chkfull()) {
				int x;
				printf("pushする整数を入力してください。:");
				scanf("%d", &x);
				push(x);
				printstack();
				fflush(stdin);
				return 1;
			} else {
				printf("スタックはフルのためプッシュできません。\n");
				return 1;
			}
		case 2:
			if (!chkempty()) {
				printf("ポップします。\n");
				pop();
				printstack();
				return 1;
			} else {
				printf("スタックは空のためポップできません。\n");
			}
		case 3:
			printstack();
			return 1;
		case 4:
			printf("終了します。\n");
			return 0;
		default:
			printf("１から4までの番号を入力してください。\n");
			return 1;
	}
}

int main(void) {
	int c, i, x;

	
	while (1) {
		printf("番号を入力してください。 (1)PUSH, (2)POP, (3)SHOW, (4)EXIT>");
		scanf("%d", &c);
		if (!command(c)) {
			break;
		}
	}
	return 0;
}