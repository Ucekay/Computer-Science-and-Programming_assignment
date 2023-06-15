#include <stdio.h>

int rn(int x);
int rn2(int y);

int main() {
  double i[2] = {0};
  int j;
  int k;
  int x = 1;
  int y = 0;
  double rand1;
  double rand2;
  rand1 = (double)x;
  rand2 = (double)y;
  printf("乱数を発生する回数を入力してください（1000万回以下）\n");
  scanf("%d", &k);
  for (j = 0; j < k; j++) {
    x = rn(x);
    rand1 = ((double)(x % 1000)) * 0.001;
    y = rn(y);
    rand2 = ((double)(y % 1000)) * 0.001;
    if (rand1 * rand1 + rand2 * rand2 <= 1) {
      i[1] += 1;
    } else {
      i[0] += 1;
    }
  }
  printf("m:n = 1:%lf\n π=%lf", i[1] / k, 4 * i[1] / k);
}

int rn(int x) {
  int A = 48109;
  int B = 2531011;
  int M = 32768;
  return (A * x + B) % M;
}

int rn2(int y) {
  int A = 48271;
  int B = 0;
  int M = 2147483647;
  return (A * y + B) % M;
}
