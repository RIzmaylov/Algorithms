#include <stdio.h>
#include <stdlib.h>

#include "geek.h"

//������� ��������� ���������� ���������. �������� ��� �������� ������� ������������� ��������
//� ��������� ���������. �������� 1'000'000 ����� �� 1 �� 1000. ����� ����������� ��� ����������
//������������ ������ ��� ���������� �� �����. ���������� �������������� ������ ��� ������������� ������ �(2n)

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
  int max = findMax(arr, len);                    //������� ����������� � ������������ �������� � �������
  int min = findMin(arr, len);
  const int spread = abs(min) + abs(max) + 1;     //������� ���������� ��������� ����� ���� � ��� ����������
  int support[spread];                            //������� ������ �� ���������� ��������� ����� ���� � ���
                                                  //� ��� ����� �������� ������� ��������� ������� ��������
  for (int i = 0; i < spread; ++i) {              //�������� ������
    support[i] = 0;
  }
  for (int i = 0; i < len; ++i) {                 //������� �� ��������� ������� ��������� ��������������
    support[arr[i] - min]++;                      //����������� ���-�� ������������� ���������
  }
  int count = 0;
  for (int i = 0; i < spread; ++i) {              //��������� �������� ������. �� ��������������� �������
    while (support[i] > 0) {                      //������ ��� ������� �����, � �������� ��� ���-�� ���������
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
