#include <math.h>
#include <stdio.h>

int main() {
  double a = 0, b = 0, c = 0;
  double area = 0, q = 0;
  
  scanf("%lf %lf %lf", &a, &b, &c);

  if (a + b > c || a + c > b || b + c > a) {
    q = (a + b + c) / 2.0;
    area = sqrt(q * a * b * c);
    print("%.2lf\n", area);
  } else {
    print("No\n");
  }

  return 0;
}
