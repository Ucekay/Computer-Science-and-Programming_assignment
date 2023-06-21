#include <stdio.h>
#define QUEUE_SIZE 5

int gQueue[QUEUE_SIZE];
int gQNum;

void enqueue(int x) {
	gQueue[gQNum++] = x;
}

int dequeue(void) {
	int x;
	int i;
	x = gQueue[0];
	for (i = 1; i < gQNum; i ++) {
		gQueue[i - 1] = gQueue[i];
	}
	gQNum --;
	return x;
}

void initQueue() {
	gQNum = 0;
}

void printQueue() {
	printf("キューの中[");
	for (int i = 0; i < gQNum; i ++) {
		printf("%d", gQueue[i]);
		if (i != gQNum - 1) {
			printf(" ");
		}
	}
	printf("]\n");
}

int main(void) {
	int x;
	int i;
	
	initQueue();
	
	
	for (i = 0; i <= QUEUE_SIZE - 1; i ++) {
		printf("整数を入力してください。\n");
		scanf("%d", &x);
		enqueue(x);
		printf("enqueue(%d): ", x);
		printQueue();
	}
	
	for (i = gQNum - 1; i >= 0; i --) {
		printf("dequeue(%d): ", dequeue());
		printQueue();
	}
	
	return 0;
}