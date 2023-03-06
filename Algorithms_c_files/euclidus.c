#include <stdio.h>

int euclidus(int a, int b) {
  while (a != b) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  return a;
}

int euclidusFast(int a, int b) {
  int c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int main(const int argc, const char** argv) {
  int a;
  int b;
  printf("%s", "Enter number A: ");
  scanf("%s", &a);
  printf("%s", "Enter number B: ");
  scanf("%s", &b);
  printf("GCD = %d \n", euclidusFast(a, b));
  return 0;
}
