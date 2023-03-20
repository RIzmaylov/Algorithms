#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

int qs(int* arr, int first, int last) {
  int i = first;
  int j = last;

  int x = arr[(first + last)/ 2];

  do {
    while (arr[i] < x) i++;
    while (arr[j] > x) j--;

    if (i <= j) {
      swapInt(&arr[i], &arr[j]);
      i++;
      j--;
    }
  } while (i <= j);

  if (i < last) qs(arr, i, last);
  if (first < j) qs(arr, first, j);
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  qs(arr, 0, SIZE - 1);
  printIntArray(arr, SIZE, 3);

  return 0;
}
