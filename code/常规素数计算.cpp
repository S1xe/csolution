#include <math.h>
#include <stdio.h>

int is_prime(int num) {
  if (num <= 1)
    return 0;
  if (num == 2)
    return 1;
  int i = 0;
  for (i = 2; i <= sqrt(num) + 1; ++i) {
    if (num % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  if (is_prime(2) != 1) {
    printf("is_prime error, error num:2\n");
  }
  if (is_prime(3) != 1) {
    printf("is_prime error, error num:3\n");
  }

  if (is_prime(4) != 0) {
    printf("is_prime error, error num:4\n");
  }

  if (is_prime(7) != 1) {
    printf("is_prime error, error num:7\n");
  }

  return 0;
}