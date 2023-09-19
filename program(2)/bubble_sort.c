#include <stdio.h>
#include <stdlib.h>

int n;

void bubble_sort(int *A);

int main(int argc, char *argv[]) {
   int i;
   n = argc - 1;
   printf("n = %d\n", n);

   int A[n];

   for (i = 1; i < argc; i++) A[i-1] = atoi(argv[i]);

   printf("A[] =");
   for (i = 0; i < n; i++) printf(" %d", A[i]);
   printf("\n");

   bubble_sort(A); // 配列A[0]からA[n-1]のバブルソート

   printf("A[] =");
   for (i = 0; i < n; i++) printf(" %d", A[i]);
   printf("\n");

   return 0;
}

void bubble_sort(int *A) {
   int i, j;
   for (i = 0; i < n - 1; i = i + 1) {
      for (j = n - 1; j > i; j = j - 1) {
         if (A[j - 1] > A[j]) {
            int t;
            t = A[j];
            A[j] = A[j - 1];
            A[j - 1] = t;
         }
      }
   }
}

