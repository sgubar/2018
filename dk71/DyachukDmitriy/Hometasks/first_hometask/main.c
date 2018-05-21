#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "hometask_1.h"

int main(void)
{
    int strings = 0;
    int columns = 0;
    printf("\t\t\t\t- THIS PROGRAMM WILL TRANSPOSE YOUR MATRIX -\n");
    printf("\n- Please, define number of strings in matrix by integer value ...\n- Number of strings in matrix = ");
    strings = check_value_func();
    printf("\n- Please, define number of columns in matrix by integer value ...\n- Number of columns in matrix = ");
    columns = check_value_func();
    int **array = (int **) malloc(sizeof(int *) * strings);
    for(int i = 0; i < strings; ++i)
    {
        array[i] = (int *) malloc(sizeof(int) * columns);
    }
    for(int i = 0; i < strings; ++i)
        for(int j = 0; j < columns; ++j)
        {
            printf("- Please enter an integer value for component [%i][%i] in your matrix: ", i, j);
            array[i][j] = check_value_func();
            printf("\n\n");
        }
    print_matrix(array, strings, columns);
    printf("- Transposing your matrix ...\n\n");
    transposing_matrix(array, strings, columns);
    free(array);
    return 0;
}