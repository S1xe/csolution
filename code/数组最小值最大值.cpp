#include <stdio.h>

int main() {
  int n = 0, arr[100], i = 0, min_index = 0, max_index = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  for (i = 0; i < n; i++) {
    if (arr[max_index] < arr[i]) {
      max_index = i;
    }
    if (arr[min_index] > arr[i]) {
      min_index = i;
    }
  }

  printf("min arr[%d]=%d , max arr[%d]=%d\n", min_index, arr[min_index],
         max_index, arr[max_index]);
  return 0;
}