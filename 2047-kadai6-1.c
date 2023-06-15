#include <stdio.h>

typedef struct point {
  double x;
  double y;
} POINT;

POINT getMiddlePoint(POINT p1, POINT p2);

int main(void) {
  POINT pt1;
  POINT pt2;
  POINT pt3;

  printf("> (x_1, y_1)\n");
  scanf("%lf %lf", &pt1.x, &pt1.y);
  printf("> (x_2, y_2)\n");
  scanf("%lf %lf", &pt2.x, &pt2.y);
  pt3 = getMiddlePoint(pt1, pt2);
  printf(
      "Midpoint between (%.1lf, %.1lf) and (%.1lf, %.1lf) is (%.1lf, %.1lf).\n",
      pt1.x, pt1.y, pt2.x, pt2.y, pt3.x, pt3.y);
}

POINT getMiddlePoint(POINT p1, POINT p2) {
  POINT p3;

  p3.x = (p1.x + p2.x) / 2;
  p3.y = (p1.y + p2.y) / 2;
  return p3;
}
