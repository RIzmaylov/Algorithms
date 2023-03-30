#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

//Быстрая сортировка, улучшенная сортировкой вставками при остатке небольшого кол-ва несортированных элементов

void sortInsert (int* arr, int first, int last) {
    int temp, pos;
    for (int i = first; i <= last; ++i) {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

int indexOfMidOfNum (int* arr, int first, int last) {
    int mid = (first + last) / 2;
    if (arr[first] > arr[last] || arr[first] > arr[mid]) {
        if (arr[last] > arr[mid]) mid = last;
    } else mid = first;
    return mid;
}

void bqs (int* arr, int first, int last) {
    int i = first;
    int j = last;
    if (j - i > 10) {
        swapInt(&arr[(first + last) / 2], &arr[indexOfMidOfNum(arr, i, j)]);
        int x = arr[(first + last) / 2];
        do {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;
            if (i <= j) {
                swapInt(&arr[i], &arr[j]);
                i++;
                j--;
            }

        } while (i <= j);
        if (i < last) bqs(arr, i, last);
        if (first < j) bqs(arr, first, j);
    } else sortInsert(arr, i, j);
}

int main(const int argc, const char** argv) {
  const int SIZE = 100;
  int arr[SIZE];
  fillIntRandom(arr, SIZE, 100);
  printIntArray(arr, SIZE, 3);
  bqs(arr, 0, SIZE - 1);
  printIntArray(arr, SIZE, 3);

  return 0;
}
