#include <stdio.h>

void pinc(int *x, int d) {
  printf("Kari-Hikisu x \t %p \t %p\n", &x, x);
  *x = *x + d;
}

int main(void) {
  int x, d;
  printf("xの初期値とdの値を入力してください。\n");
  scanf("%d%d", &x, &d);
  printf("              \t ADDRESS \t VALUE\n");
  printf("Jitu-Hikisu x \t %p \t %d\n", &x, x);
  pinc(&x, d);
  printf("x + d = %d\n", x);
}
