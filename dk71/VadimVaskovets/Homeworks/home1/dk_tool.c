#include <stdio.h>
#include <locale.h>
#include "dk_tool.h"

int home1()
{
	setlocale(LC_ALL, "RUS");
	int i, j, m, n, x;
  printf("¬ведите количество строк матрици : ");
  scanf ("%d", & m);
  printf("¬ведите количество столбцов матрици : ");
  scanf ("%d", & n);
	int A[m][n];
	for ( i = 0; i < m; i ++ )
	for ( j = 0; j < n; j ++ ) {
	printf ("A[%d][%d]=", i, j);
	scanf ("%d", & A[i][j]);
	
 }
   printf("¬ведите число на которое умножить матрицу : ");
  scanf ("%d", & x);
 for ( i = 0; i < m; i ++ )
{
   for ( j = 0; j < n; j ++ )
  {
    printf ("%d ", A[i][j]*x);
     }
   printf("\n");
}
 
}
