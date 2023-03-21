#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

//�������� ���������� ��������. �������� ��� �������� ������ � ���������������� �������� � ������(������)

void merge(int* arr, int first, int mid, int last) {
  int l = first;
  int r = mid + 1;
  int* tmp = (int*) malloc((last + 1) * sizeof(int)); //������� ����� ��� ������ ��������������� ���������
  int step = 0;
  while (l <= mid && r <= last) {                     //������� ���������� �������� � ���������� � �����
    if (arr[l] < arr[r]) {
      tmp[step++] = arr[l++];
    } else {
      tmp[step++] = arr[r++];
    }
  }

  while (r <= last) {             //��� ��� � ���������� ����� ����� ���� ������, ��� �� ��� �������� ���������� � �����
    tmp[step++] = arr[r++];       //��� ��� ����� �������� ���������� ��������
  }
  while (l <= mid) {
    tmp[step++] = arr[l++];
  }
  for (int k = 0; k < last - first + 1; ++k) {  //�������� �� ������ � �������� ������
    arr[first + k] = tmp[k];
  }
}

int mergeSort(int* arr, int first, int last) {
  int split;
  if (first < last) {                 //���� ������ ������ ��� �� ������ ��������
    split = (first + last) / 2;       //��������� ���
    mergeSort(arr, first, split);     //� ���������� �������� �� ��� ���������
    mergeSort(arr, split + 1, last);  //��� ����� ��������� ������� �� ������ ��������, ������ �� ���� �����
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
