#include <stdio.h>

int rn(int x);

int main() {
  int i[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int j;
  int k;
  int x = 1;
  double y;
  y = (double)x;
  printf("乱数を発生する回数を入力してください（1000万回以下）\n");
  scanf("%d", &k);
  for (j = 1; j < k; j++) {
    i[x % 10] += 1;
    x = rn(x);
  }
  double max_i = 0;
  for (j = 0; j < 10; j++) {
    if (i[j] > max_i) {
      max_i = (double)i[j];
    }
  }
  double l = max_i / 20;
  int m;
  for (j = 0; j < 10; j++) {
    int num = (double)i[j] / l + 0.5;
    printf("　　%d: ", j + 1);
    for (m = 1; m <= num; m++) {
      printf("*");
    }
    for (m = 1; m <= 20 - num; m++) {
      printf(" ");
    }
    printf("　　　%8d\n", i[j]);
  }
  printf("=========================================\n TOTAL:%34d\n", k);
}

int rn(int x) {
  int A = 48109;
  int B = 2531011;
  int M = 32768;
  return (A * x + B) % M;
}
