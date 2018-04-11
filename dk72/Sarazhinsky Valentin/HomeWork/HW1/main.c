#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

 
int main(int argc, char *argv[]){
 
 	int *matrix, *trans_matrix, lines, columns;
 	
	printf("enter the length of the lines:");
	scanf("%d",&lines);
	printf("enter the length of the columns:");
	scanf("%d",&columns);
	
	matrix = (int*)malloc((lines+columns)*sizeof(int));  
    trans_matrix = (int*)malloc((columns+lines)*sizeof(int));
	
	matrix = input_matrix(matrix, lines, columns);
	trans_matrix = transponation(matrix, trans_matrix, lines, columns);
	output_matrix(trans_matrix, lines, columns);
	free(matrix);
	free(trans_matrix);
	return 0;
}
