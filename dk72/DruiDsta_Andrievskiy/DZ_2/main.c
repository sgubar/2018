#include <stdio.h>
#include <stdlib.h>
#include "dru_lib.h"

int main(int argc, char *argv[]) 
{
	Point A={0,0};
	Point B={0,0};
	Point C={0,0};
	
	printf("Enter A->x ");
	scanf("%d",&A.x);
	printf("Enter A->y ");
	scanf("%d",&A.y);
	printf("Enter B->x ");
	scanf("%d",&B.x);
	printf("Enter B->y ");
	scanf("%d",&B.y);
	printf("Enter C->x ");
	scanf("%d",&C.x);
	printf("Enter C->y ");
	scanf("%d",&C.y);
	
	Fig *ABC=createFig(&A, &B, &C);
	printFig(ABC);
	
	Param *ParamABC=enterParam(ABC);
	printParam(ParamABC);
	
	destroyFig(ABC);
	free(ParamABC);
	
	return 0;
}
