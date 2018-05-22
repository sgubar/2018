#include <stdio.h>
#include <stdlib.h>
#include "dz_1.h"

int main(int argc, char *argv[]){
 
 	int *matrix, *trans_matrix, hor, ver;
 	
	printf("enter the length of the lines:");
	scanf("%d",&hor);
	printf("enter the length of the columns:");
	scanf("%d",&ver);
	
	matrix = (int*)malloc((hor+ver)*sizeof(int));  
    trans_matrix = (int*)malloc((ver+hor)*sizeof(int));
	
	matrix = input_matrix(matrix, hor, ver);
	trans_matrix = transponation(matrix, trans_matrix, hor, ver);
	output_matrix(trans_matrix, hor, ver);
	free(matrix);
	free(trans_matrix);
	return 0;
}
   
