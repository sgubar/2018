#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "hometask_1.h"

int check_value_func(void)
{
    int value;
    int check_result;
     do
    {
        check_result = 0;
        check_result = scanf("%i", &value);
        fflush(stdin);
        if (check_result != 1)
        {
           printf("\n- The value was not defined by integer value.\n\n- Please try again:\n\n- Your value:");
        }
    }while(check_result != 1);
    return value;
}

void print_matrix(int **matrix, int strings, int columns)
{
    printf("\n- Your matrix is: [%i][%i]\n\n", strings, columns);
    printf("\n\n- Your matrix consist of the next values: \n\n");
    for(int i = 0; i < strings; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            printf("\t%i", matrix[i][j]);
        }
        printf("\n\n");
    }
}

void transposing_matrix(int **matrix,  int strings, int columns)
{
    int **transposing_matrix = (int **) malloc(columns * sizeof(int *));
    for(int i = 0; i < columns; ++i)
        transposing_matrix[i] = (int *) malloc(strings * sizeof(int));
    for(int i = 0; i < strings; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            transposing_matrix[j][i] = matrix[i][j];
        }
    }
    print_matrix(transposing_matrix, columns, strings);
    free(transposing_matrix);
}
