#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
    int verSide = 0;
    int horSide = 0;
    
            printf("This program sums the matrices A and B\n\n");
 		    printf("Enter the number of horizontal cells: ");
 		    scanf("%d", &verSide);
	     	printf("\nEnter the number of vertical cells: ");
  		    scanf("%d", &horSide);
  		    
	  int matrixA[verSide][horSide];
	  int matrixB[verSide][horSide];
	  int matrixC[verSide][horSide];
    
    int* matrixAPoiner = (int *)malloc(sizeof(matrixA[verSide][horSide]));  
    int* matrixBPoiner = (int *)malloc(sizeof(matrixB[verSide][horSide]));        
    int* matrixCPoiner = (int *)malloc(sizeof(matrixC[verSide][horSide]));
    
    
    printf("\n\n\tEnter first matrix:\n\n\n");
    
	scanmatrix(verSide, horSide, matrixA);
	printf("\nA   = ");
	printmatrix( verSide, horSide, matrixA);

    printf("\n\n\tEnter second matrix:\n\n\n");

	scanmatrix(verSide, horSide, matrixB);
	printf("\nB   = ");
	printmatrix( verSide, horSide, matrixB);

	printf("\n\tRulult:\n");

    sumamatrixAB(verSide, horSide, matrixA, matrixB, matrixC); 
   	printf("\nC   = ");
    printmatrix( verSide, horSide, matrixC);
 
    return 0;
}
