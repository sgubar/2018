#include <stdio.h>
#include "tool.h"

int main()
{
	Point A={9,0};
	Point B={3,0};
	Point C={0,0};
	
	
	
	
	triangle *ABC= create_triangle(&A, &B, &C);
	print_triangle(ABC);
	printf("Perimetr ABC=%f\n \a", sqr_triangle(ABC));
	destroy_triangle(ABC);
	
	
	
	
	
	
	
	
	
	return 0;
}
