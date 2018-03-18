#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "dk_matrix_minus.h"


int main()
{
    int *a; // указатель на массив
    int *b;
    int *c;
    int i, j, n, m;
  system("chcp 1251>nul");
  system("cls");
  printf("Введите количество строк: ");
  scanf("%d", &n);
  printf("Введите количество столбцов: ");
  scanf("%d", &m);

  entermatr1(a);

  i=0;
  j=0;

  entermatr2(b);



  free(a);
  getchar();   getchar();
  return 0;
}
