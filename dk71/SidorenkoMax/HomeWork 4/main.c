#include <stdio.h>
#include <stdlib.h>
#include "func_array.h"
#include "func.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int TrianglesNumber, i;
	int A_x, A_y, B_x, B_y, C_x, C_y;
	TriangleArray *theArray = createArray(5);
	printf("Enter TrianglesNumber  ");
	scanf("%d", &TrianglesNumber);
	for( i = 1 ; i <= TrianglesNumber; i ++)
		{
			printf("\nEnter %d Triangle\n", i);
			
			enter(&A_x,&A_y);
	 		enter(&B_x,&B_y);
	 		enter(&C_x,&C_y);
	 	   
			Point A = {A_x,A_y};
			Point B = {B_x,B_y};
			Point C = {C_x,C_y};
	 	
			Triangle ABC = {&A, &B, &C};
	
			addElement(theArray, &ABC, squareTriangle(&ABC));
		}
	
	FILE *theFile = fopen("haha.json", "w");
	
	writeArrayToJSON(theFile, theArray);
	
	fflush(theFile);
	fclose(theFile);
	
	InsertionSort(theArray);



	FILE *theFile2 = fopen("test2.json", "w");

	writeArrayToJSON(theFile2, theArray);

	fflush(theFile2);
	fclose(theFile2);
	
	
	freeArray(theArray);
		
	return 0;
}
