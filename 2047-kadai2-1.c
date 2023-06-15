#include <math.h>
#include <stdio.h>

float S(float x, float y, float z);

int main() {
  float x, y, z;
  printf("三角形の3辺の長さを入力してください\n");
  scanf("%f%f%f", &x, &y, &z);
  float s;
  s = (x + y + z) / 2;
  while (s - x <= 0 || s - y <= 0 || s - z <= 0) {
    printf("三角形を形成できません\n");
    printf("三角形の3辺の長さを入力してください\n");
    scanf("%f%f%f", &x, &y, &z);
    s = (x + y + z) / 2;
  }
  printf("%f\n", S(x, y, z));
}

float S(float x, float y, float z) {
  float s;
  s = (x + y + z) / 2;
  return sqrt(s * (s - x) * (s - y) * (s - z));
}
