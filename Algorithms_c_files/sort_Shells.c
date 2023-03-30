#include <stdio.h>
#include <stdlib.h>

#include "geek.h"


//Улучшенная сортировка вставками, где меняются не соседние элементы, а и на определенном расстоянии
//друг от друга. Подходит для небольшого количества элементов

void sortShells(int* arr, int len) {
  int i;
  int j;
  int step;
  int temp;

  for (step = len / 2; step > 0; step /= 2) {
    for (i = step; i < len; ++i) {
      temp = arr[i];
      for (j = i; j >= step; j -= step) {
        if (temp < arr[j - step]) {
          arr[j] = arr[j - step];
        } else {
          break;
        }
      }
      arr[j] = temp;
    }
  }
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  sortShells(arr, SIZE);
  printIntArray(arr, SIZE, 3);

  return 0;
}
