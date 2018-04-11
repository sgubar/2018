#include "dk_tool.h"
int i, j;
int input_matrix(int *matrix, int lines, int columns)
{
	

	for(i=0;i<lines;i++){
		for(j=0;j<columns;j++){
			printf("matrix[%d][%d]:",i+1,j+1);
			scanf("%d",&matrix[(i*lines) + j]);		
		}
	}
	return matrix;
	
}


int transponation(int *matrix, int *trans_matrix, int lines, int columns)
{
	for(i=0;i<lines;i++){
		for(j=0;j<columns;j++){
			trans_matrix[(j*columns) + i] = matrix[(i*lines) + j];			
		}
	}
	return trans_matrix;
	
}

int output_matrix(int *trans_matrix, int lines, int columns)
{
		for(i=0;j<columns;j++){
		for(j=0;i<lines;i++){
		printf("%d    ",trans_matrix[(j*columns) + i]);			
		}
		printf("\n");
	}
	
}
