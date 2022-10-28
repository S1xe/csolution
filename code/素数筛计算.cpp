#include <stdio.h>
#include <string.h>
const int N = 10000000;
int nums[N] = {0};

void init() {
  nums[0] = 1;
  nums[1] = 1;
  int i = 0;
  int j = 0;
  for (i = 2; i < N; i++) {
    if (!nums[i]) {
      for (j += i + i; j < N; j += i) {
        nums[j] = 1;
      }
    }
  }
}

int is_prime(int num) { return !nums[num]; }

int main() {
  init();
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
  if (is_prime(100000) != 0) {
    printf("is_prime error, error num:100000\n");
  }

  return 0;
}
