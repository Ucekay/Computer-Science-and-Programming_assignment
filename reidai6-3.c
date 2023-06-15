#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int x = 19;
  int *p1;
  int *p2;

  p1 = &x;

  p2 = malloc(sizeof(int));
  if (p2 == NULL) {
    fprintf(stderr, "Memory Shortage\n");
    exit(1);
  }
  *p2 = 77;

  printf("HENSU \t VALUE \t INDIRECT \n");
  printf("p1 \t %10p \t %d\n", p1, *p1);
  printf("p2 \t %10p \t %d\n", p2, *p2);
  free(p2);
  return 0;
}
