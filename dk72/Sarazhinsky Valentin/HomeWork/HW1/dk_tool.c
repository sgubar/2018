#include "dk_tool.h"
int i,j;
int transponation(int lines, int columns)
{

	int matrix[lines][columns];
	for(i=0;i<lines;i++){
		for(j=0;j<columns;j++){
			printf("matrix[%d][%d]:",i,j);
			scanf("%d",&matrix[i][j]);		
		}
	}
		for(i=0;i<columns;i++){
		for(j=0;j<lines;j++){
			printf("%d    ",matrix[j][i]);			
		}
		printf("\n");
	}
	
	return 0;
}
