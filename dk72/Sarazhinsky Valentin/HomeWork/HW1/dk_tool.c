#include "dk_tool.h"

#include <stdio.h>
#include <stdlib.h>

int input_matrix(int lines, int columns)
{
	int i, j;
	int **matrix = (int **) malloc(columns * sizeof(int *));
    for(i = 0; i < columns; ++i){
    	matrix[i] = (int *) malloc(lines * sizeof(int));
	}    
	for(i=0;i<lines;i++){
		for(j=0;j<columns;j++){
			printf("matrix[%d][%d]:",i+1,j+1);
			scanf("%d",&matrix[i][j]);		
		}
	}
	return matrix;
}


void transponation(int **matrix, int lines, int columns)
{
	int i,j;
	int **transposing_matrix = (int **) malloc(columns * sizeof(int *));
    for(i = 0; i < columns; ++i)
        transposing_matrix[i] = (int *) malloc(lines * sizeof(int));
    for(i = 0; i < lines; ++i)
    {
        for(j = 0; j < columns; ++j)
        {
            transposing_matrix[j][i] = matrix[i][j];
        }
    }
    output_matrix(transposing_matrix, columns, lines);
    free(matrix);
    free(transposing_matrix);
	
}

void output_matrix(int **trans_matrix, int lines, int columns)
{
	int i, j;
	for(i=0;i<lines;i++){
		for(j=0;j<columns;j++){
			printf("%d    ",trans_matrix[i][j]);			
		}
		printf("\n");
	}
	
}
