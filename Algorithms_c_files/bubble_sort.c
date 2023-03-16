#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

void fillRandom(int* arr, int len, int border) {
  for (int i = 0; i < len; ++i) {
    *(arr + i) = rand() % border;
  }
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(int* arr, int len) {
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  bubbleSort(arr, SIZE);
  printIntArray(arr, SIZE, 3);

  return 0;
}
