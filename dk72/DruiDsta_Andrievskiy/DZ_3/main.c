#include <stdio.h>
#include <stdlib.h>
#include "dru_lib.h"
#include "dru_lib_arr.h"

int main(int argc, char *argv[]) 
{	
	FigArr *theArr=createArr();
	
	do{
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
		
		addElement(theArr, ABC, ParamABC);
		
		destroyFig(ABC);
		free(ParamABC);
	}while(theArr->count!=theArr->num);
	
	FILE *theFile = fopen("DZ.json", "a+");
	
	writeArrayToJSON(theFile, theArr);
	
	fflush(theFile);
	fclose(theFile);
	
	freeArr(theArr);
	
	return 0;
}

