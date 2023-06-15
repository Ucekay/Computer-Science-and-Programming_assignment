#include <stdio.h>

int gcd(int n, int m);

int main() {
  int n;
  int m;
  scanf("%d%d", &n, &m);
  return gcd(n, m);
}

int gcd(int n, int m) {
  if (n > m) {
    n = m;
    m = n;
  }
  int i;
  while (i <= n) {
    if (n / i == 0 && m / i == 0) {
      int gcd = i;
      i = i + 1;
    }
  }
  return gcd;
}
