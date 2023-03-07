#include <stdio.h>

int euclidusExt(int a, int b, int* x, int* y) {
  int q, r, x1, x2, y1, y2;
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }
  x2 = 1;
  x1 = 0;
  y2 = 0;
  y1 = 1;
  while (b > 0) {
    q = a / b;
    r = a - q * b;
    *x = x2 - q * x1;
    *y = y2 - q * y1;
    a = b;
    b = r;
    x2 = x1;
    x1 = *x;
    y2 = y1;
    y1 = *y;
  }
  *x = x2;
  *y = y2;
  return a;
}

int main_ext_euclidus(const int argc, const char** argv) {
  int a;
  int b;
  int coeffA;
  int coeffB;
  printf("%s", "Enter number A: ");
  scanf("%d", &a);
  printf("%s", "Enter number B: ");
  scanf("%d", &b);
  printf("GCD = %d \n", euclidusExt(a, b, &coeffA, &coeffB));
  printf("ax + by = %d", a * coeffA + b * coeffB);
  return 0;
}
