#include <stdio.h>

int rn(int x);
int main() {
  int i;
  int x = 1;
  double y;
  for (i = 1; i < 10; i++) {
    printf("%d\t%d\t%2.4f\t\t%2.4f\n", x, x % 10 + 1, y, y * 10.0 - 5);
    x = rn(x);
    y = ((double)(x % 1001)) * 0.001;
  }
  return 0;
}

int rn(int x) {
  int A = 48109;
  int B = 2531011;
  int M = 32768;
  return (A * x + B) % M;
}
