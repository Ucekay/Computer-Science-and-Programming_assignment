#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5
typedef int  QUEUE_TYPE;

QUEUE_TYPE gQueue[QUEUE_SIZE + 1];
int gQFront = 0;
int gQRear = 0;

void error(char *s) {
    fflush(stdout);
    fprintf(stderr, "\n%s\n", s);
    exit(1);
}

void initQueue(void) {
    gQFront = gQRear = 0;
}

int queueNext(int n) {
    return (n + 1) % (QUEUE_SIZE + 1);
}

int chkempty(void) {
    return (gQFront == gQRear);
}

int chkfull(void) {
    return (queueNext(gQRear) == gQFront);
}

void enqueue(QUEUE_TYPE x) {
    if (chkfull()) {
        error("enpueue: フル状態のためエンキューできません.");
    }

    gQueue[gQRear] = x;
    gQRear = queueNext(gQRear);
}

int dequeue(void) {
    QUEUE_TYPE x;

    if (chkempty()) {
        error("dequeue: 空状態のためデキューできません.");
    }

    x = gQueue[gQFront];
    gQFront = queueNext(gQFront);

    return x;
}

void printQueue(void) {
    int i;

    printf("\t");
    printf("キューの中 [");
    for (i = gQFront; i != gQRear; i = queueNext(i)) {
        printf("%d", gQueue[i]);
        if (i != gQRear - 1) {
            printf(" ");
        }
    }
        printf("]");
        printf("先頭 = %d, 末尾 = %d\n", gQFront, gQRear);
        fflush(stdout);
}

int main(void) {
    QUEUE_TYPE x;

    initQueue();

    while (1) {
        printf("整数を入力してください.\n");
        scanf("%d", &x);
        if (x >= 0 && x % 2 == 0) {
            int alreadyStored = 0;
            for (int j = 0; j < gQRear; j ++) {
                if (x == gQueue[j]) {
                    printf("既に格納されています.\n");
                    alreadyStored = 1;
                    break;
                }
            }
            if (!alreadyStored) {
                enqueue(x);
                printf("enqueue(%d)", x);
                printQueue();
            }
        }
        else if (x >= 0 && x % 2 == 1) {
            printf("dequeue() %d :", dequeue());
            printQueue();
        }else {
            while (!chkempty()) {
                printf("dequeue() %d :", dequeue());
                printQueue();
            }
            break;
        }
    }

    return 0;
}
