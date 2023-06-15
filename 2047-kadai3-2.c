#include <stdio.h>

int rn(int x);

int main() {
  double i[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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
  printf("1が出た割合：\t%5.2f%%です。\n", i[0] / k);
  printf("2が出た割合：\t%5.2f%%です。\n", i[1] / k * 100);
  printf("3が出た割合：\t%5.2f%%です。\n", i[2] / k * 100);
  printf("4が出た割合：\t%5.2f%%です。\n", i[3] / k * 100);
  printf("5が出た割合：\t%5.2f%%です。\n", i[4] / k * 100);
  printf("6が出た割合：\t%5.2f%%です。\n", i[5] / k * 100);
  printf("7が出た割合：\t%5.2f%%です。\n", i[6] / k * 100);
  printf("8が出た割合：\t%5.2f%%です。\n", i[7] / k * 100);
  printf("9が出た割合：\t%5.2f%%です。\n", i[8] / k * 100);
  printf("10が出た割合：\t%5.2f%%です。\n", i[9] / k * 100);
}

int rn(int x) {
  int A = 48109;
  int B = 2531011;
  int M = 32768;
  return (A * x + B) % M;
}
