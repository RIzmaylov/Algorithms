#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

int binarySearch(const int* arr, int len, int value) {
  int l = 0;
  int r = len - 1;
  int mid = (l + r) / 2;

  while (l != r && arr[mid] != value) {
    if (arr[mid] < value)
      l = mid;
    else
      r = mid;
    mid = (l + r) / 2;
  }

  if (arr[mid] == value)
    return mid;
  else
    return -1;
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  sortIntInserts(arr, SIZE);
  printIntArray(arr, SIZE, 3);
  printf("Num 4 was find on index: %d \n", binarySearch(arr, SIZE, 4));

  return 0;
}
