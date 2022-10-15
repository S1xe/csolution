#include <stdio.h>
#include <string.h>
void convert(char *str, double num, int bits) {
  char num_str[100];
  sprintf(num_str, "%lf", num);
  int count = 0;
  int i = 0;
  int j = 0;
  int rest = 0;
  for (i = 0; num_str[i]; i++) {
    str[i] = num_str[i];
    // 计算有效位数
    if (num_str[i] != '.') {
      count++;
    }

    // 有效长度达到后,进行进位判断
    if (count == bits) {
      if (num_str[i + 1] && num_str[i + 1] >= '5') {

        // 进行逐个进位操作,
        rest = 1;
        for (j = i; j >= 0; j--) {
          if (str[j] == '.')
            continue;
          rest = rest + str[j] - '0';
          str[j] = rest % 10 + '0';
          if (rest < 10) {
            rest = 0;
            break;
          }
          rest = rest / 10;
        }
        // 若最后一直进位,如0.9998 => 1.000
        if (rest == 1) {
          for (j = i; j >= 0; j--) {
            str[j + 1] = str[j];
          }
          str[0] = rest + '0';
        }
      }
      break;
    }
  }

  // 去除后缀0和.
  j = 0;
  while (str[j])
    j++;
  for (j = j - 1; j >= 0; j--) {
    if (str[j] == '0') {
      str[j] = '\0';
    } else if (str[j] == '.') {
      str[j] = '\0';
      break;
    } else {
      break;
    }
  }
}

void clean(char *s, int len) {
  int i = 0;
  for (i = 0; i < 100; i++) {
    s[i] = '\0';
  }
}

int main() {
  char s[100];
  clean(s, 100);
  convert(s, 114.5149, 6);
  if (strcmp(s, "114.515") != 0) {
    printf("114.5149 convert fail %s\n", s);
  }

  clean(s, 100);
  convert(s, 9198.10, 6);
  if (strcmp(s, "9198.1") != 0) {
    printf("9198.10 convert fail %s\n", s);
  }

  clean(s, 100);
  convert(s, 15.999999999, 6);
  if (strcmp(s, "16") != 0) {
    printf("9198.10 convert fail %s\n", s);
  }

  clean(s, 100);
  convert(s, 15.899999999, 6);
  if (strcmp(s, "15.9") != 0) {
    printf("9198.10 convert fail %s\n", s);
  }
}
