#include <stdio.h>

struct point {
  int x;
  int y;
};

int main() {
  struct point table[5][100] = {0};

  int n;
  printf("確認したい座標の個数（100個以下）を入力してください：\n");
  scanf("%d", &n);
  while (n > 100) {
    printf("100以下の自然数で入力してください。");
    printf("確認したい座標の個数（100個以下）を入力してください：\n");
    scanf("%d", &n);
  }

  int i;
  int p, q;
  int c_0 = 0;
  int c_1 = 0;
  int c_2 = 0;
  int c_3 = 0;
  int c_4 = 0;
  for (i = 1; i <= n; i++) {
    printf("%d個目の座標のx座標を入力してください。:", i);
    scanf("%d", &p);

    printf("%d個目の座標のy座標を入力してください。:", i);
    scanf("%d", &q);

    if (p > 0 && q > 0) {
      table[1][c_1].x += p;
      table[1][c_1].y += q;
      c_1 = c_1 + 1;
    } else if (p < 0 && q > 0) {
      table[2][c_2].x += p;
      table[2][c_2].y += q;
      c_2 = c_2 + 1;
    } else if (p < 0 && q < 0) {
      table[3][c_3].x += p;
      table[3][c_3].y += q;
      c_3 = c_3 + 1;
    } else if (p > 0 && q < 0) {
      table[4][c_4].x += p;
      table[4][c_4].y += q;
      c_4 = c_4 + 1;
    } else {
      table[0][c_0].x += p;
      table[0][c_0].y += q;
      c_0 = c_0 + 1;
    }
  }
  printf("The number of Ⅰ quadrant (RUQ)\t%d\n", c_1);
  for (i = 0; i < c_1; i++) {
    printf("(%d, %d)\n", table[1][i].x, table[1][i].y);
  }
  printf("The number of Ⅱ quadrant (LUQ)\t%d\n", c_2);
  for (i = 0; i < c_2; i++) {
    printf("(%d, %d)\n", table[2][i].x, table[2][i].y);
  }
  printf("The number of Ⅲ quadrant (LLQ)\t%d\n", c_3);
  for (i = 0; i < c_3; i++) {
    printf("(%d, %d)\n", table[3][i].x, table[3][i].y);
  }
  printf("The number of Ⅳ quadrant (RLQ)\t%d\n", c_4);
  for (i = 0; i < c_4; i++) {
    printf("(%d, %d)\n", table[4][i].x, table[4][i].y);
  }
}
