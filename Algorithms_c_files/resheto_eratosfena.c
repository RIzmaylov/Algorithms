#include <stdio.h>

int main_resheto_eratosfena(const int argc, const char** argv) {
  int arr[255] = {2, 3};
  int capacity = 2;

  for (int i = 4; i < 255; ++i) {
    int isPrime = 1;
    for (int j = 0; j < capacity; ++j) {
      if (i % arr[j] == 0) {
        isPrime = 0;
        break;
      }
    }
    if (isPrime) {
      arr[capacity++] = i;
    }
  }

  for (int k = 0; k < capacity; ++k) {
    printf("%d ", arr[k]);
  }
  return 0;
}
