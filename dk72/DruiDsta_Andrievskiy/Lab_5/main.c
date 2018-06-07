#include <stdio.h>
#include <stdlib.h>
#include "dru_lib.h"

int main() 
{
    intTree *theTree = createIntTree();
	int size, i=0, aValue;
	printf("Enter size:");
	scanf("%d",&size);
	printf("///////////////////\n");
	srand(time(0));
	for(; i!=size; i++)
	{
		/*printf("Enter value:");
		scanf("%d",&aValue);*/
		aValue=rand()%100;
		insertIntValueToTree(theTree, aValue);
		printf("%d ", aValue);
	}
	printf("\n///////////////////\n");
	printTree(theTree);
    destroyIntTree(theTree);
    return 0;
}
