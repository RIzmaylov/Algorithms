#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

//Вариант алгоритма сортировки подсчетом. Подходит для большого массива целочисленных значений
//в маленьком диапазоне. Например 1'000'000 чисел от 1 до 1000. Часто применяется для сортировки
//библиотечный данных при сортировке по ключу. Использует дополнительный массив для повторяющихся данных О(2n)

int findMin(int* arr, int len) {
  int min = arr[0];
  for (int i = 0; i < len; ++i) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

int findMax(int* arr, int len) {
  int max = arr[0];
  for (int i = 0; i < len; ++i) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void SortCount(int* arr, int len) {
  int max = findMax(arr, len);                    //Находим минимальное и максимальное значения в массиве
  int min = findMin(arr, len);
  const int spread = abs(min) + abs(max) + 1;     //находим количество элементов между макс и мин элементами
  int support[spread];                            //создаем массив из количества элементов между макс и мин
                                                  //в нем будет хранится частота вхождения каждого элемента
  for (int i = 0; i < spread; ++i) {              //обнуляем массив
    support[i] = 0;
  }
  for (int i = 0; i < len; ++i) {                 //проходя по основному массиву заполняем впомогательный
    support[arr[i] - min]++;                      //подсчитывая кол-ва повторяющихся элементов
  }
  int count = 0;
  for (int i = 0; i < spread; ++i) {              //заполянем исходный массив. Во вспомогательном массиве
    while (support[i] > 0) {                      //индекс это номинал числа, а значение это кол-во элементов
      arr[count++] = i + min;
      support[i]--;
    }
  }
}


int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  SortCount(arr, SIZE);
  printIntArray(arr, SIZE, 3);

  return 0;
}
