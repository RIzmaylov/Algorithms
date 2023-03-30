#include <stdio.h>
#include <stdlib.h>

#include "geek.h"


//Улучшенная сортировка вставками, где меняются не соседние элементы, а и на определенном расстоянии
//друг от друга. Подходит для небольшого количества элементов

void sortShells(int* arr, int len) {
  int i;                                        //счетчики циклов
  int j;
  int step;                                     //расстояние между сравниваемыми эл-ми
  int temp;                                     //для хранения одного из элементов

  for (step = len / 2; step > 0; step /= 2) {   //расстояние между меняемыми эл-ми сначала пол длины и уменьшается в 2 раза каждый раз
    for (i = step; i < len; ++i) {              //меняем 0 элемент и средний, потом 1 и средний + 1 и etc
      temp = arr[i];                            //текущий элемент в темп
      for (j = i; j >= step; j -= step) {       //делаем замену элементов если меньше
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
