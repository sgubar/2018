#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"


int main(void)
{
	Tree *myTree = NULL;
	Tree *tmp;
	double value;

	for (int i = 0; i < 8; i++)
	{
		printf("Enter value: ");
		scanf("%lf", &value);
		AddNode(&myTree, value);
	}

	printf("Nodes: ");
	PrintElements(myTree);
	printf("\n");

	printf("Enter value that you want to find: ");
	scanf("%lf", &value);
	tmp = Search(&myTree, value);
	if (tmp)
	{
		printf("Searched node = %f\n", tmp->data);
	}
	else
	{
		printf("Element was not found in you tree.\n");
	}

	DeleteElements(myTree);
    
	return 0;
} 
