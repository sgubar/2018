int* MatrixSubtraction ( int *A , int *B ,int rows , int colums )
 {
  int i, j;
  int* C = (int*)malloc((rows+colums)*sizeof(int));
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < colums; j++)
    {
      C[i*rows + j] = A[i*rows + j] - B[i*rows + j] ;
    }
  }
  return C;
}

void MatrixOutPut (int* M , int rows , int colums)
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

void InputMatrix( int* M , int rows , int colums)
{
  int i , j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < colums; j++) {
      printf("Element (%d)(%d) :" , i+1 , j+1);
      scanf("%d" , &M[(i*rows)+j] );
    }
  }
}
