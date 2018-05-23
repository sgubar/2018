#include <stdio.h>
#include "tool.h"
#include "tool_array.h"

int main(int argc, const char * argv[])
{
	int k;
	int i;
	int A_x, A_y, B_x, B_y, C_x, C_y;
	triangle_array *theArray = createArray(5);
	
	do
	{
	printf("Enter the number of triangles, but no less than 2\t");
	scanf("%d", &k);
	}
	while (k <= 1);
	
	
	
	for(i = 1; i <= k; i++)
	 {
	 	printf("\n\tEnter %d triangle\n", i);
	 	
	    entering(&A_x, &A_y);
	 	entering(&B_x, &B_y);
	 	entering(&C_x, &C_y);
	 	   
		Point A = {A_x, A_y};
		Point B = {B_x, B_y};
		Point C = {C_x, C_y};
	 	
		triangle ABC = {&A, &B, &C};
	
		add_element(theArray, &ABC, flat_triangle(&ABC));
	 }
	 
	 
	FILE *before = fopen("before.json", "w");
	
	write_array_to_JSON(before, theArray);
	
	fflush(before);
	fclose(before);
	
	
	insertion_sort(theArray);


	FILE *after = fopen("after.json", "w");

	write_array_to_JSON(after, theArray);

	fflush(after);
	fclose(after);
	
	freeArray(theArray);
	
	return 0;
}
