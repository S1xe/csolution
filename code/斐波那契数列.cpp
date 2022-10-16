#include <stdio.h>
int main() {
  int arr[50];
  int i = 0;
  // 初始化前两位
  arr[0] = 0;
  arr[1] = 1;

  // 按公式计算
  for (i = 2; i < 50; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  printf("arr[%d]=%d\n", 10, arr[10]);

  return 0;
}