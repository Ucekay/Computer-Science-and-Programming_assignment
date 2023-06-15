#include <stdio.h>

int main() {
  int n;
  int m;
  printf("2つの自然数を入力してください。\n");
  printf("1つ目の自然数 = ");
  scanf("%d", &n);
  printf("2つ目の自然数 = ");
  scanf("%d", &m);

  if (n > m) {
    int tmp;
    tmp = n;
    n = m;
    m = tmp;
  }

  int i;
  int g;
  for (i = 1; i <= n; i++) {
    if (n % i == 0 && m % i == 0) {
      g = i;
    }
  }
  printf("%d\n", g);
}
