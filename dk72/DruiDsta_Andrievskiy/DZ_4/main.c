#include <stdio.h>
#include <stdlib.h>
#include "dru_dz.h"
#include "dru_arr.h"

int main(void)
{
	int i;
	int A_x, A_y, B_x, B_y, C_x, C_y;
	int size;
	printf("Entrer size: ");
	scanf("%d",&size);
	triangleArray *theArray = createArray(size);
	
	for(i=1; i<=size; i++)
	{
	 	printf("\nEnter triangle ¹%d \n", i);
		
	    enter(&A_x,&A_y);
	 	enter(&B_x,&B_y);
	 	enter(&C_x,&C_y);

		Point A = {A_x,A_y};
		Point B = {B_x,B_y};
		Point C = {C_x,C_y};

		triangle ABC = {&A, &B, &C};

		addElement(theArray, &ABC);
		printf("\n\tOK\n");
	}
	
	FILE *theFile = fopen("array.json", "w");
	writeArrayToJSON(theFile, theArray);
	fclose(theFile);

	bubble_sort(theArray);
	
	FILE *theFile2 = fopen("sort_array.json", "w");
	writeArrayToJSON(theFile2, theArray);
	fclose(theFile2);

	freeArray(theArray);

	return 0;
}

