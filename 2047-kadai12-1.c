#include <stdio.h>
#include <stdlib.h>

int n;

void bubble_sort(int *A);

int main(int argc, char *argv[]) {
   int i;
   n = argc - 1;

   int A[n];

   for (i = 1; i < argc; i++) A[i-1] = atoi(argv[i]);

   printf("A = ");
   bubble_sort(A); // 配列A[0]からA[n-1]のバブルソート

   return 0;
}

void bubble_sort(int *A) {
   int i, j, k;
   int compare_count = 0;
   int swap_count = 0;
   for (i = 0; i < n - 1; i++) {
      printf("パス%d: \n", i + 1);
      for (j = n - 1; j > i; j = j - 1) {
         compare_count++;
         for (k = 0; k < j-1; k++) {
            printf(" %d", A[k]);
         }
         if (A[j - 1] > A[j]) {
            int t;
            t = A[j];
            A[j] = A[j - 1];
            A[j - 1] = t;
            swap_count++;
            printf(" %d > %d", A[j], A[j - 1]);
         } else {
            printf(" %d < %d", A[j - 1], A[j]);
         }
         for (k = j + 1; k < n; k++) {
            printf(" %d", A[k]);
         }
         printf("\n");
      }
      for (j = 0; j < n; j++) {
         printf(" %d", A[j]);
      }
      printf("\n");
   }
   printf("比較回数: %d\n", compare_count);
   printf("交換回数: %d\n", swap_count);
}

