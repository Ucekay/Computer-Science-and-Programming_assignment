#include <stdio.h>

#include <math.h>

int rn(int x);
double S1(double a, double b);

int main() {
  double a;
  double b;
  double i[2] = {0};
  int j;
  int k;
  int x = 1;
  int y = 0;
  double rand1;
  double rand2;
  rand1 = (double)x;
  rand2 = (double)y;
  printf("積分区間（a,b)の値を入力してください\n");
  scanf("%lf%lf", &a, &b);
  while (a > b) {
    printf("値の大小を確認してもう一度入力してください。");
    scanf("%lf%lf", &a, &b);
  }
  if (a == b) {
    printf("面積 = %d", 0);
  }
  printf("乱数を発生する回数を入力してください（1000万回以下）\n");
  scanf("%d", &k);
  for (j = 0; j < k; j++) {
    x = rn(x);
    rand1 = ((double)(x % 1001)) * 0.001 * (b - a) + a;
    y = rn(y);
    if (a * a >= b * b) {
      rand2 = ((double)(y % 1001)) * 0.001 * a * a;
    } else {
      rand2 = ((double)(y % 1001)) * 0.001 * b * b;
    }

    if (rand2 <= rand1 * rand1) {
      i[1] += 1;
    } else {
      i[0] += 1;
    }
  }
  double S2 = (b * b * b - a * a * a) / 3;
  double S3 = i[1] / k * S1(a, b);
  double diff = S2 - S3;
  double abs_diff = fabs(diff);
  printf("方法1で求めた面積 = %lf\n", S2);
  printf("方法2で求めた面積 = %lf\n", S3);
  printf("積分値の差 = %lf\n", abs_diff);
}

int rn(int x) {
  int A = 48109;
  int B = 2531011;
  int M = 32768;
  return (A * x + B) % M;
}

double S1(double a, double b) {
  double width = b - a;
  double height;
  if (a * a >= b * b) {
    height = a * a;
  } else {
    height = b * b;
  }
  return width * height;
}
