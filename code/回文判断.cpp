#include <stdio.h>

int slove(int n) {
  int num = n;
  int r = 0;
  while (num > 0) {
    r = r * 10 + num % 10;
    num /= 10;
  }
  return r == n ? 1 : 0;
}

int main() {
  if (slove(121) != 1) {
    printf("%d sovle error\n", 121);
  }
  if (slove(1) != 1) {
    printf("%d sovle error\n", 1);
  }

  if (slove(12) == 1) {
    printf("%d sovle error\n", 12);
  }
  
  return 0;
}