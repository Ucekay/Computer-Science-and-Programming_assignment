#include <stdio.h>

int main(void) {
  int x = 77, y = 115;
  int tmp;
  int *p = &tmp;

  printf("HENSU \t ADDRESS \t VALUE\n");
  printf("x \t %p \t %d\n", &x, x);
  printf("y \t %p \t %d\n", &y, y);

  tmp = x;
  x = y;
  y = *p;

  printf(" exchange x and y\n");
  printf("x \t %p \t %d\n", &x, x);
  printf("y \t %p \t %d\n", &y, y);
}
