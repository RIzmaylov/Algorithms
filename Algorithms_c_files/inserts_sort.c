#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

void fillRandom(int* arr, int len, int border) {
  for (int i = 0; i < len; ++i) {
    *(arr + i) = rand() % border;
  }
}


void insertsSort(int* arr, int len) {
  int temp, pos;
  for (int i = 1; i < len; ++i) {
    temp = arr[i];
    pos = i - 1;
    while (pos >= 0 && arr[pos] > temp) {
      arr[pos + 1] = arr[pos];
      --pos;
    }
    arr[pos + 1] = temp;
  }
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  insertsSort(arr, SIZE);
  printIntArray(arr, SIZE, 3);

  return 0;
}
