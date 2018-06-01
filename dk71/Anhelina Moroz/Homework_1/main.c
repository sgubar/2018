#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) 
{
	int size, matrix_A[size][size], matrix_B[size][size], matrix_result[size][size], i, j;
	
	printf("Enter matrices' dimensionality (only natural values)\n");
	printf("Size = ");
	scanf("%d", &size);
		
	
	printf("Enter matrix A: \n");
	scan_matrix(size, matrix_A);
	
	/*
	for (i = 0; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
		{
			printf("[%d,%d]: ", i, j);
			scanf("%d", &matrix_A[i][j]);
			printf("\n");
		}
	}
	*/
	
	printf("Enter matrix B:\n");
	scan_matrix(size, matrix_B);
	
	/*
	for (i = 0; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
		{
			printf("[%d,%d]: ", i, j);
			scanf("%d", &matrix_B[i][j]);
			printf("\n");
		}
	}	
	*/
	
	subtraction (size, matrix_A, matrix_B, matrix_result);
	
	for(i = 0; i < size; i++)                                           
    {
        for(j = 0; j < size; j++)
        {
            printf("%i\t", matrix_result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
