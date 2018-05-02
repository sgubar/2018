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
	
			addElement(theArray, &ABC);
		}
	
	FILE *theFile = fopen("roflanPominki.json", "a+");
	
	writeArrayToJSON(theFile, theArray);
	
	fflush(theFile);
	fclose(theFile);
	
	freeArray(theArray);
		
	return 0;
}
