#include <stdio.h>
#include <stdlib.h>
#include "dz_1.h"

int i, j;
int input_matrix(int *matrix, int hor, int ver)
{
	

	for(i=0;i<hor;i++){
		for(j=0;j<ver;j++){
			printf("matrix[%d][%d]:",i+1,j+1);
			scanf("%d",&matrix[(i*hor) + j]);		
		}
	}
	return matrix;
	
}


int transponation(int *matrix, int *trans_matrix, int hor, int ver)
{
	for(i=0;i<hor;i++){
		for(j=0;j<ver;j++){
			trans_matrix[(j*ver) + i] = matrix[(i*hor) + j];			
		}
	}
	return trans_matrix;
	
}

int output_matrix(int *trans_matrix, int hor, int ver)
{
		for(i=0;j<ver;j++){
		for(j=0;i<hor;i++){
		printf("%d    ",trans_matrix[(j*ver) + i]);			
		}
		printf("\n");
	}
	
}

