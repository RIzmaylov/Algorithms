#include <stdio.h>
#include <stdlib.h>

#include "geek.h"


void selectionSort(int* arr, int len) {
  int min;
  for (int i = 0; i < len - 1; ++i) {
    min = i;
    for (int j = i + 1; j < len; ++j) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swapInt(&arr[i], &arr[min]);
  }
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  selectionSort(arr, SIZE);
  printIntArray(arr, SIZE, 3);

  return 0;
}
