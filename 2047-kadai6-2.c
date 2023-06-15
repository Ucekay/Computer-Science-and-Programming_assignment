#include <math.h>
#include <stdio.h>

typedef struct point {
  double x;
  double y;
} POINT;

void rotationPoint(POINT *p1, double dθ);

int main(void) {
  POINT pt;
  int dt;
  printf("> (x, y)\n");
  scanf("%lf %lf", &pt.x, &pt.y);
  printf("> (dt)\n");
  while (scanf("%d", &dt) != EOF) {
    double dθ = dt * M_PI / 180;
    rotationPoint(&pt, dθ);
    printf("(%.2lf, %.2lf)\n", pt.x, pt.y);
    printf("> (dt)\n");
  }
}

void rotationPoint(POINT *p1, double dθ) {
  POINT p2;
  p2 = *p1;
  p1->x = (p2.x) * cos(dθ) - (p2.y) * sin(dθ);
  p1->y = (p2.x) * sin(dθ) + (p2.y) * cos(dθ);
}
