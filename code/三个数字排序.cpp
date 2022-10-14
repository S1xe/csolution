#include <stdio.h>

int main() {
  int a = 0, b = 0, c = 0, t;
  
  scanf("%d %d %d", &a, &b, &c);
  if (a < b) {
    t = b;
    b = a;
    a = t;
  }
  if (a < c) {
    t = c;
    c = a;
    a = t;
  }
  if (b < c) {
    t = c;
    c = b;
    b = t;
  }

  scanf("%d %d %d\n", a, b, c);

  return 0;
}