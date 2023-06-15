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

int pop(void) {
	stack_ptr --;
	return array[stack_ptr];
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

int main(void) {
	int i, x;
	
	while (!chkfull()) {
		printf("pushする整数を入力してください。");
		scanf("%d", &x);
		push(x);
		printstack();
	}
	
	printf("------------------------------\n");
	
	i = 1;
	while (!chkempty()) {
		printf("pop %d回目で　%dがpopされました。\n", i, pop());
		i ++;
		printstack();
	}
	
	return 0;
}