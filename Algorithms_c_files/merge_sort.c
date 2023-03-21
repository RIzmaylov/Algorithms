#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

//Алгоритм сортировки слиянием. Подходит для структур данных с последовательным доступам к данным(потоки)

void merge(int* arr, int first, int mid, int last) {
  int l = first;
  int r = mid + 1;
  int* tmp = (int*) malloc((last + 1) * sizeof(int)); //создаем буфер для записи отсортированных элементов
  int step = 0;
  while (l <= mid && r <= last) {                     //попарно сравниваем элементы и записываем в буфер
    if (arr[l] < arr[r]) {
      tmp[step++] = arr[l++];
    } else {
      tmp[step++] = arr[r++];
    }
  }

  while (r <= last) {             //так как в предыдущем цикле может быть случай, что не все элементы перенесены в буфер
    tmp[step++] = arr[r++];       //эти два цикла копируют оставшиеся элементы
  }
  while (l <= mid) {
    tmp[step++] = arr[l++];
  }
  for (int k = 0; k < last - first + 1; ++k) {  //копируем из буфера в исходный массив
    arr[first + k] = tmp[k];
  }
}

int mergeSort(int* arr, int first, int last) {
  int split;
  if (first < last) {                 //если массив больше чем из одного элемента
    split = (first + last) / 2;       //разделяем его
    mergeSort(arr, first, split);     //и рекурсивно проходим по его половинам
    mergeSort(arr, split + 1, last);  //тем самым получатся массивы из одного элемента, теперь их надо слить
    merge(arr, first, split, last);
  }

}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  mergeSort(arr, 0, SIZE - 1);
  printIntArray(arr, SIZE, 3);

  return 0;
}
