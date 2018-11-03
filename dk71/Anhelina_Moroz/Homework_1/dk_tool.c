#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dk_tool.h"

void subtraction (int size, int matrix_A[size][size], int matrix_B[size][size], int matrix_result[size][size])
{
	int i, j;
	
	for (i = 0; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
		{
			matrix_result[i][j] = matrix_A[i][j] - matrix_B[i][j];
		}
	}
}

void scan_matrix (int size, int matrix[size][size]) 
{
	int i, j;
	for (i = 0; i < size; i++) 
	{
		for (j = 0; j < size; j++) 
		{
			printf("[%d,%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
			printf("\n");
		}
	}	
}
