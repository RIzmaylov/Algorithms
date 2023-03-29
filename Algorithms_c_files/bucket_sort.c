#include <stdio.h>
#include <stdlib.h>

#include "geek.h"


//Сортировка, в которой исходный массив распределяется по блокам(корзинам), таким образом,
//что каждый элемент в каждом следующем блоке был больше или меньше предыдущего и затем каждый блок
// сортируется по отдельности

// + - относится к быстрым алгоритмам с О(n)
// - - сильно деградирует при большом количестве близких по значению элементов (на константное время)

void BucketSort(int* arr, int len) {
  const int max = len;                        //константа для обозначения максимального кол-ва элементов в корзине
  const int b = 10;                           //количество корзин

  int buckets[b][max + 1];                    //создаем массив для хранения корзин указанной глубины и счетчика заполнения
  for (int i = 0; i < b; ++i) {
    buckets[i][max] = 0;                      //обнуляем счетчики в каждой корзине
  }

  for (int digit = 1; digit < 1000000000; digit *= 10) {      //поразрядно разбираем исходный массив
    for (int i = 0; i < max; ++i) {         //распределяем исходные данные по корзинам (с 0 на конце в первой, с 0 - на десятках, etc)
      int d = (arr[i] / digit) % b;

//      int counter = buckets[d][max];      //после того как положили число в корзину, увеличиваем счетчик
//      buckets[d][counter] = arr[i];
//      counter++;
//      buckets[d][max] = counter;

      buckets[d][buckets[d][max]++] = arr[i];   //та же запись, что и 4 пред. строки, но короче
    }
    int idx = 0;                                //собираем элементы обратно в массив из корзин
    for (int i = 0; i < b; ++i) {
      for (int j = 0; j < buckets[i][max]; ++j) {
        arr[idx++] = buckets[i][j];
      }
      buckets[i][max] = 0;
    }
  }
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  BucketSort(arr, SIZE);
  printIntArray(arr, SIZE, 3);

  return 0;
}
