#include <stdio.h>

int main(void) {
  int x = 77, y = 0;
  int *p = &x;

  printf("HENSU t ADDRES \t SIZE \t VALUE\n");
  printf("x \t %p \t %lu \t %d\n", &x, sizeof(x), x);
  printf("y \t %p \t %lu \t %d\n", &y, sizeof(y), y);
  printf("p \t %p \t %lu \t %d\n", &p, sizeof(*p), *p);

  y = *p + 20;
  printf(" y = *p + 20 is executed.\n");

  printf("x \t %p \t %lu \t %d\n", &x, sizeof(x), x);
  printf("y \t %p \t %lu \t %d\n", &y, sizeof(y), y);
  printf("p \t %p \t %lu \t %d\n", &p, sizeof(*p), *p);
}
