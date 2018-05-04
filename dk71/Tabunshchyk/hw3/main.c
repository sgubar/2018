#include <stdio.h>
#include "tool.h"
#include "tool_array.h"

int main()
{
	int n_o_t;
	int pos;
	int A_x, A_y, B_x, B_y, C_x, C_y;
	triangleArray *theArray = createArray(5);
	printf("Number of triangles ");
	
	scanf("%d", &n_o_t);
	for(pos = 1; pos <= n_o_t; pos++)
	 {
	 	printf("\nEnter %d triangle\n", pos);
	 	
	    triangle_entering(&A_x,&A_y);
	 	triangle_entering(&B_x,&B_y);
	 	triangle_entering(&C_x,&C_y);
	 	   
		Point A = {A_x,A_y};
		Point B = {B_x,B_y};
		Point C = {C_x,C_y};
	 	
		triangle ABC = {&A, &B, &C};
	
		addElement(theArray, &ABC);
	 }
	 
	 
	FILE *file = fopen("file.json", "a+");
	
	array_to_json(file, theArray);
	

	fclose(file);
	freeArray(theArray);
	
	return 0;
}
