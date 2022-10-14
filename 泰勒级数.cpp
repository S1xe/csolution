#include <stdio.h>

int main() {
  int x = 0;
  double s = 1;
  double t = 0;
  int i = 0;
  int n = 0;
  scanf("%d %d", &x, &n);
  for (i = 1; i <= n; i++) {
    if (i == 1) {
      t = x * 1.0 / i;
    } else {
      t = t * x * 1.0 / i;
    }
    s += t;
  }
  printf("e^%d=%f\n", x, s);
}