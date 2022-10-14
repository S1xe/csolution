#include <stdio.h>

int is_leap_year(year) {
  if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  int months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year = 0, month = 0, day = 0;
  int days = 0;
  int i = 0;
  scanf("%d %d %d", &year, &month, &day);
  for (i = 1; i < month; i++) {
    days += months[i];
    if (i == 2 && is_leap_year(year) == 1) {
      days += 1;
    }
  }

  printf("%d-%d-%d spend %d day(s)\n", year, month, day, days);
  return 0;
}