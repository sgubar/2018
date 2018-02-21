#include "func.h"


int main () {
  int rows = 0 , colums = 0;
  int *A, *B , *C;                                 //stvoryuyu vkazivnyk na matrytsyu A, B, C
  printf("Enter matrix (rows*colums): \t");        //zapytuyu rozmir matrytsi
  scanf("%d*%d" , &rows , &colums);
  if (rows > 0 && colums > 0) {

    A = (int*)malloc((rows+colums)*sizeof(int));   //vydilyayu pamyat dlya mtarytsi A
    B = (int*)malloc((rows+colums)*sizeof(int));   //vydilyayu pamyat dlya mtarytsi B

    //vykorystovuyemo funktsiyã vvodu matryts
    printf("Matrix A:\n");
    InputMatrix( A , rows , colums);
    printf("Matrix B:\n");
    InputMatrix( B , rows , colums);

    //vyvodymo znachennya matryts A i B
    printf ("______________\n");
    MatrixOutPut ( A, rows, colums);
    printf ("______________\n");
    MatrixOutPut ( B, rows, colums);

    //vykorystovuyemo funktsiyu dodavannya matryts'
    C = MatrixSum (A, B, rows, colums);

    //vyvodymo znachennya rezultuyuchoyi matrytsi
    printf ("______________\n");
    MatrixOutPut ( C, rows, colums);
    free (A);                                       //zvilnyuyemo pamyat
    free (B);
    free (C);

  }
  else { return 0; }

  system ("PAUSE");
  return 0;
}

