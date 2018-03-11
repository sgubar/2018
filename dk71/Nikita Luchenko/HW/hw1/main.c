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
  		    

    int* matrixAPoiner = (int *)malloc(verSide*horSide * sizeof (int));  
    int* matrixBPoiner = (int *)malloc(verSide*horSide * sizeof (int));       
    int* matrixCPoiner = (int *)malloc(verSide*horSide * sizeof (int));
    
    
    printf("\n\n\tEnter first matrix:\n\n\n");
    
	scanmatrix(verSide, horSide, matrixAPoiner);
	printf("\nA   = ");
	printmatrix( verSide, horSide, matrixAPoiner);

    printf("\n\n\tEnter second matrix:\n\n\n");

	scanmatrix(verSide, horSide, matrixBPoiner);
	printf("\nB   = ");
	printmatrix( verSide, horSide, matrixBPoiner);

	printf("\n\tRulult:\n");

    sumamatrixAB(verSide, horSide, matrixAPoiner, matrixBPoiner, matrixCPoiner); 
   	printf("\nC   = ");
    printmatrix( verSide, horSide, matrixCPoiner);
    free(matrixAPoiner);
    free(matrixBPoiner);
    free(matrixCPoiner);
    
 
    return 0;
}
