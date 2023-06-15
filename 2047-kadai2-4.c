#include <stdio.h>

int euclid(int x, int y);

int main() {
  int x, y;
  printf("2つの自然数を入力してください\n");
  scanf("%d%d", &x, &y);
  printf("最大公約数は　%d\n", euclid(x, y));
}

int euclid(int x, int y) {
  if (y > x) {
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
  }
  if (y == 0) {
    return x;
  } else {
    int r;
    r = x % y;
    if (r == 0) {
      return y;
    }
    while (r != 0) {
      r = x % y;
      x = y;
      y = r;
    }
    return x;
  }
}
