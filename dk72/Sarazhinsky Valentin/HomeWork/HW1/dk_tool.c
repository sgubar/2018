#include "dk_tool.h"

int i, j, lines, columns;
int matrix[][100],trans_matrix[][100];

int input_matrix()
{
	printf("enter the length of the lines:");
	scanf("%d",&lines);
	printf("enter the length of the columns:");
	scanf("%d",&columns);

	for(i=0;i<lines;i++){
		for(j=0;j<columns;j++){
			printf("matrix[%d][%d]:",i,j);
			scanf("%d",&matrix[i][j]);		
		}
	}
	
}

int transponation()
{
	for(i=0;i<lines;i++){
		for(j=0;j<columns;j++){
			trans_matrix[j][i]=matrix[i][j];			
		}
	}
}

int output_matrix()
{
	for(i=0;i<columns;i++){
		for(j=0;j<lines;j++){
			printf("%d    ",trans_matrix[i][j]);			
		}
		printf("\n");
	}
	
}
