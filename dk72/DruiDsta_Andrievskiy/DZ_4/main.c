#include <stdio.h>
#include <stdlib.h>
#include "dru_dz.h"
#include "dru_arr.h"

int main(int argc, char *argv[]) 
{	
	FigArr *theArr=createArr();
	Point A, B, C;
	
	do{
		
		
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
		printf("\n\n\n");
		
		/*Fig *ABC=createFig(&A, &B, &C);
		printFig(ABC);
			
		Param *ParamABC=enterParam(ABC);
		printParam(ParamABC);*/
		
		addElement(theArr, createFig(&A, &B, &C), enterParam(createFig(&A, &B, &C)));
		
		/*destroyFig(ABC);
		free(ParamABC);*/
		
	}while(theArr->count!=theArr->num);
	
	FILE *theFile = fopen("DZ.json", "w");
	
	writeArrayToJSON(theFile, theArr);
	/*bubbleSort(theArr);
	
	printArr(theArr);
	writeArrayToJSON(theFile, theArr);*/
	
	fclose(theFile);
	
	freeArr(theArr);
	
	return 0;
}


