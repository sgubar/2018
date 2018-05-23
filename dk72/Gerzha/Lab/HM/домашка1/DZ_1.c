#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "DZ_1.h"

void print_matrix(int **matrix_array, int number_of_rows, int number_of_columns)
{
	printf("\n\n- Your matrix consist of the next values: \n\n");
    for(int i = 0; i < number_of_rows; ++i)
    {
    	for(int j = 0; j < number_of_columns; ++j)
    	{
    		printf("\t%i", matrix_array[i][j]);
    	}
    	printf("\n\n");
    }
}

void transposing_matrix(int **matrix_array,  int number_of_rows, int number_of_columns)
{
    int **transposing_matrix_array = (int**) malloc(number_of_columns * sizeof(int*));
    for(int i = 0; i < number_of_columns; ++i)
   		transposing_matrix_array[i] = (int*) malloc(number_of_rows * sizeof(int));
	int swap_value = 0;
	for(int i = 0; i < number_of_rows; ++i)
    {
    	for(int j = 0; j < number_of_columns; ++j)
    	{
            transposing_matrix_array[j][i] = matrix_array[i][j];
    	}
    }
    print_matrix(transposing_matrix_array, number_of_columns, number_of_rows);
    free(transposing_matrix_array);
}
