#include <stdio.h>

int main(void) {
  int x;
  int *p = &x;

  printf("HENSU t ADDRES \t SIZE \t VALUE\n");
  printf("x \t %p \t %lu \t %d\n", &x, sizeof(x), x);
  printf("p \t %p \t %lu \t %d\n", &p, sizeof(*p), *p);
  return 0;
}
