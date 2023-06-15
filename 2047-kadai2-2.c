#include <stdio.h>

unsigned long F(int n);

int main() {
  int n;
  printf("自然数を入力してください\n");
  scanf("%d", &n);
  printf("%d! = %lu\n", n, F(n));
}

unsigned long F(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * F(n - 1);
  }
}
