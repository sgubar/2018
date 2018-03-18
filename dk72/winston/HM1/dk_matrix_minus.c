#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "dk_matrix_minus.h"


int i, j, n, m;


// Выделение памяти
  a = (int*)malloc(n*m * sizeof(int));


  void entermatr1(a)
  {
      // Ввод элементов массива
  for (i = 0; i<n; i++)  // цикл по строкам
  {
    for (j = 0; j<m; j++)  // цикл по столбцам
    {
      printf("a[%d][%d] = ", i, j);
      scanf("%d", (a + i*m + j));
    }
  }
  return a;
  }

  b = (int*)malloc(n*m * sizeof(int));
    void entermatr2(a)
  {
      // Ввод элементов массива
  for (i = 0; i<n; i++)  // цикл по строкам
  {
    for (j = 0; j<m; j++)  // цикл по столбцам
    {
      printf("b[%d][%d] = ", i, j);
      scanf("%d", (b + i*m + j));
    }
  }
  return a;
  }
