#include <stdio.h>

int main(void) {
  int x = 77;
  int *p;

  p = &x;
  printf("HENSU t ADDRES \t SIZE \t VALUE\n");
  printf("x \t %p \t %lu \t %d\n", &x, sizeof(x), x);
  printf("p \t %p \t %p \t %d\n", &p, p, *p);

  *p = 15;
  printf(" p = 15 is executed.\n");
  printf("p \t %p \t %p \t %d\n", &p, p, *p);

  return 0;
}
