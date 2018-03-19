#include <stdio.h>
#include "dk_triangle.h"

int main()
{
	Point A = {0,0};
	Point B = {4,0};
	Point C = {0,5};
	
	triangle *ABC = create_triangle(&A, &B, &C);

	print_triangle(ABC);

	printf("The flat of triangle ABC = %f\n", flat_triangle(ABC));
	
	destroy_triangle(ABC);
	return 0;
}
