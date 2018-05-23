#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <DZ_1.h>

int main (void)
{
	int number_of_rows = 0;
	int number_of_columns = 0;
	int value_variable = 0;
	printf("\t\t\t\t- This program is a program of operations with matrix array -\n\n- Please define number of rows in your matrix by integer value ...\n\n- Your value: ");
    fflush(stdin);
	scanf("%i", &number_of_rows);
    printf("\n\n- Please define number of columns in your matrix by integer value ...\n\n- Your value: ");
	fflush(stdin);
	scanf("%i", &number_of_columns);
    printf("\n\n- In result you have (%i) rows and (%i) columns ...", number_of_rows, number_of_columns);
    int **matrix_array = (int**) malloc(number_of_rows * sizeof(int*));
   for(int i = 0; i < number_of_rows; ++i)
   		matrix_array[i] = (int*) malloc(number_of_columns * sizeof(int));
   	for(int i = 0; i < number_of_rows; ++i)
    {
    	for(int j = 0; j < number_of_columns; ++j)
    	{
    		printf("\n\n- Value for index [%i][%i]: ", i, j);
    		scanf("%i", &value_variable);
    		matrix_array[i][j] = value_variable;
    	}
    }
    print_matrix(matrix_array, number_of_rows, number_of_columns);
    printf("\n\n- Transposing matrix ...");
    transposing_matrix(matrix_array, number_of_rows, number_of_columns);
    free(matrix_array);
    return 0;
}
