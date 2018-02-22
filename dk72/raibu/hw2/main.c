#include "right_triangle.h"


int main(int argc, char const *argv[])
{
	
	// prtriangle2d x = enter_params();
	// print_rtriangle(x); 
	// triangle_free(x);
	prtriangle2d arr[3];
	for (int i = 0; i < 3; ++i)
	{
		arr[i] = enter_params();
	}
	for (int i = 0; i < 3; ++i)
	{
		printf("\n\nTriangles you entered are valid and params of %dth are:\n\n", i);
		print_rtriangle(arr[i]);
	}
	for (int i = 0; i < 3; ++i)
	{
		printf("Freeing memory  allocated to %dth triangle\n", i);
		triangle_free(arr[i]);
	}


	return 0;
}










