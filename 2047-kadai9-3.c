#include <stdio.h>
#include <stdlib.h>

struct cell {
    int element;
    struct cell *next;
};

struct queue {
    struct cell *front;
    struct cell *rear;
};

void enqueue(int x, struct queue *Q) {
    struct cell *p;
    p = (struct cell *)malloc(sizeof(struct cell));
    if (Q->rear != NULL) {
        (Q->rear)->next = p;
    }
    Q->rear = p;
    if (Q->front == NULL) {
        Q->front = p;
    }
    (Q->rear)->element = x;
    (Q->rear)->next = NULL;
    return;
}

int dequeue(struct queue *Q) {
    struct cell *q;
    int dltd;
    if (Q->front == NULL) {
        printf("空状態のためデキューできません.\n");
        exit(1);
    }else {
        q = Q->front;
        Q->front = (Q->front)->next;
        dltd = q->element;
        free(q);
    }
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    return dltd;
}

void printQueue(struct queue *Q) {
    struct cell *q;
    q = Q->front;
    printf("\t");
    printf("キューの中 [");
    while (q != NULL) {
        printf("%d ", q->element);
        q = q->next;
    }
    printf("]\n");
    fflush(stdout);
}

int main(void) {
    struct queue Q;
    struct cell *q;
    int x;

    Q.front = Q.rear = NULL;

    while (1) {
        printf("整数を入力してください. :\n");
        scanf("%d", &x);
        if (x >= 0 && x % 2 == 0) {
            q = Q.front;
            int alreadyStored = 0;
            while (q != NULL) {
                if (x == q->element) {
                    printf("すでに格納されています.\n");
                    alreadyStored = 1;
                    break;
                }
                q = q->next;
            }
            if (!alreadyStored) {
                enqueue(x, &Q);
                printf("enqueue(%d) :", x);
                printQueue(&Q);
            }
        } else if (x >= 0 && x % 2 == 1) {
            printf("dequeue() %d :", dequeue(&Q));
            printQueue(&Q);
        } else {
            while (Q.front != NULL) {
                printf("dequeue() %d :", dequeue(&Q));
                printQueue(&Q);
                break;
            }
        }
    }

    return 0;
}