#include "func.h"

int* MatrixSum ( int *A , int *B ,int rows , int colums ) //funktsiya dla dodavanna matrytsi
 {
  int i, j;
  int* C = (int*)malloc((rows+colums)*sizeof(int));      //vydilyayu pamyat dlya mtarytsi C
  for (i = 0; i < rows; i++)                             //prokhodzhus po ryadkam
  {
    for (j = 0; j < colums; j++)                         //prokhodzhus po stopchykakh
    {
      C[i*rows + j] = A[i*rows + j] + B[i*rows + j] ;
      //dodayu znachennya matrytsi A do znachennya matrytsi B i prysvoyuyu otrymane znachennya matrytsi C
    }
  }
  return C;
}


void MatrixOutPut (int* M , int rows , int colums) // stvoryuyemo funktsiyu dlya vyvoda danykh matrytsi
 {
  int i, j;
  for (i = 0; i < rows; i++)
    {
    for (j = 0; j < colums; j++)
    {
      printf ("%d\t", M[(i*rows) + j]);
    }
    printf ("\n");
  }
}

void InputMatrix( int* M , int rows , int colums)  // stvoryuyemo funktsiyu dlya vvoda dynykh vkhidnykh matrytsi
{
  int i , j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < colums; j++) {
      printf("Element (%d)(%d) :" , i+1 , j+1);
      scanf("%d" , &M[(i*rows)+j] );
    }
  }
}
