#include <stdio.h>
#include "dk_tools.h"

int main()
{

  int rows = 0 , colums = 0;
  int *A, *B , *C;


      printf("Enter size matrix:\n");

      do
      {
          printf("quantity rows: ");
          scanf("%d" , &rows );
          printf("quantity colums: ");
          scanf("%d" , &colums);
          if(rows < 0 || colums < 0)
          {
              printf("\nError! Number of rows and columns must be positive. Enter again!\n\n");
          }


      }while(rows < 0 || colums < 0);

    A = (int*)malloc((rows+colums)*sizeof(int));
    B = (int*)malloc((rows+colums)*sizeof(int));

    printf("\nMatrix A:\n");
    InputMatrix( A , rows , colums);
    printf("\nMatrix B:\n");
    InputMatrix( B , rows , colums);

    printf ("______________\n");
    MatrixOutPut ( A, rows, colums);
    printf ("______________\n");
    MatrixOutPut ( B, rows, colums);

    C = MatrixSubtraction (A, B, rows, colums);

    printf ("______________\n");
    MatrixOutPut ( C, rows, colums);

    free (A);
    free (B);
    free (C);

 return 0;
}
