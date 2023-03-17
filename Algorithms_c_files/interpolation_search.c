#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

int interpolationSearch(const int* arr, int len, int value) {
  int mid;
  int l = 0;
  int r = len - 1;

  while (arr[l] < value && arr[r] > value) {
    mid = l + (value - arr[l]) * (r - l) / (arr[r] - arr[l]);
    if (arr[mid] < value)
      l = mid + 1;
    else if (arr[mid] > value)
      r = mid - 1;
    else return mid;
  }

  if (arr[l] == value)
    return l;
  else if (arr[r] == value)
    return r;
  else return -1;
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  sortIntInserts(arr, SIZE);
  printIntArray(arr, SIZE, 3);
  printf("Num 55 was find on index: %d \n", interpolationSearch(arr, SIZE, 55));

  return 0;
}
