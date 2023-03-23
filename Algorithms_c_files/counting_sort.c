#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

//Алгоритм сортировки подсчетом. Подходит для большого массива целочисленных значений
//в маленьком диапазоне. Например 1'000'000 чисел от 1 до 1000

void countingSort (int* arr, int len, int max) {  //на вход подаестя массив, его длина и максимальное значение из элементов
  int counts[max];                                //создается массив из колчества возможных значений элементов
  for (int i = 0; i < max; ++i) {                 //пока что количество элементов каждого значение = 0
    counts[i] = 0;                                //заполняем нулями
  }
  for (int i = 0; i < len; ++i) {                 //теперь подсчитываем сколько в исходном массиве раз встречается
    counts[arr[i]]++;                             //каждое число и заполняем временный массив подсчетов
  }
  int index = 0;                                  //теперь заполняем исходный массив цифрами из временного
  for (int i = 0; i < max; ++i) {
    for (int j = 0; j < counts[i]; ++j) {
      arr[index] = i;
      index++;
    }
  }
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  countingSort(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);

  return 0;
}
