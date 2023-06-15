#include <stdio.h>

int main(void) {
  int x = 77, y = 115;
  int *p;

  printf("HENSU t ADDRES \t SIZE \t VALUE\n");
  printf("x \t %p \t %lu \t %d\n", &x, sizeof(x), x);
  printf("y \t %p \t %lu \t %d\n", &y, sizeof(y), y);

  p = &x;
  printf(" p = &x is executed.\n");
  printf("p \t %p \t %p \t %d\n", &p, p, *p);

  p = &y;
  printf(" p = &y is executed.\n");
  printf("p \t %p \t %p \t %d\n", &p, p, *p);
}
