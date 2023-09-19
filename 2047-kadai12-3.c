#include <stdio.h>
#include <stdlib.h>

void sift_down(int *A, int x, int m);
void build_heap(int *A);
void heap_sort(int *A);
void print_heap(int *A, int i, int m, int root);

int n;

int main(int argc, char *argv[]) {
    int i;
    n = argc - 1;
    printf("n = %d\n", n);

    int A[n];

    for (i = 1; i < argc; i++) A[i-1] = atoi(argv[i]);

    printf("A[] =");
    for (i = 0; i < n; i++) printf(" %d", A[i]);
    printf("\n");

    heap_sort(A); // 配列A[0]からA[n-1]のヒープソート

    printf("A[] =");
    for (i = 0; i < n; i++) printf(" %d", A[i]);
    printf("\n");

    return 0;
}

// 注目する節点とその子の節点の間でヒープ条件が成立していない状態からヒープを回復
// A: ヒープのデータを格納している配列, x: 注目する節点の番号, m: ヒープのデータ数
void sift_down(int *A, int x, int m) {
    int snode, svalue;
    while (2 * x + 1 <= m - 1) {              // 注目する節点に子が存在する間，実行
        if (2 * x + 1 == m - 1) {                 // 左の子しかいない場合
            snode = 2 * x + 1;  svalue = A[2 * x + 1];
        } else {                              // 左右の子が存在する場合
        // 値の大きい子を調べる
            if (A[2 * x + 1] > A[2*x+2]) {        // 左の子の方が大きい
                snode = 2 * x + 1;  svalue = A[2 * x + 1];
            } else {                            // 右の子の方が大きい
                snode = 2 * x + 2;  svalue = A[2 * x + 2];
            }
        }
        // 子のデータ（大きい方）と親のデータを比較
        if (A[x] < svalue) {                // 親の方が小さいため節点を交換
            A[snode] = A[x];  A[x] = svalue;  x = snode;
        }
        else return;                        // 子の方が小さい（終了）
    }
}

// 要素数Nの配列Aをもとにヒープを構築
void build_heap(int *A) {
    int x;
    for (x = n/2-1; x >= 0; x = x-1)
    sift_down(A, x, n);
}

// 要素数nの配列Aをヒープソートにより整列
void heap_sort(int *A) {
    int m;
    build_heap(A);
    print_heap(A, 0, n, 1);
    printf("\n");
    for (m = n-1; m > 0; m = m-1) {
        { int t; t = A[0]; A[0] = A[m]; A[m] = t; }
        sift_down(A, 0, m);
        print_heap(A, 0, m, 1);
        printf("\n");

        for (int i = m; i < n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}

void print_heap(int *A, int i, int m, int root) {
    if (i >= m) {
        return;
    }

    if (2 * i + 1 < m) {
        printf(" [");
    }

    if (i == m - 1 && i % 2 == 1) {
        printf(" %d ", A[i]);
        printf(" _ ]");
    } else {
        printf(" %d", A[i]);
    }

    print_heap(A, 2*i+1, m, 0);
    print_heap(A, 2*i+2, m, 0);

    if (i % 2 == 0 && root == 0) {
        printf(" ]");
    }
}