#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

int qs_Lomuto(int* arr, int first, int last) {
  if (first < last) {
    int x = arr[last];
    int i = first;
    int j = 0;
    for (j = first; j <= last - 1; j++) {
      if (arr[j] <= x) {
        swapInt(&arr[i], &arr[j]);
        i++;
      }
    }
    swapInt(&arr[i], &arr[last]);
    qs_Lomuto(arr, first, i - 1);
    qs_Lomuto(arr, i + 1, last);
  }
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  qs_Lomuto(arr, 0, SIZE - 1);
  printIntArray(arr, SIZE, 3);

  return 0;
}
