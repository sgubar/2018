#include <stdio.h>
#include "dk_triangle.h"

int main()
{
	Point_t A = {0,0};
	Point_t B = {4,0};
	Point_t C = {0,5};

	triangle_t *ABC = create(&A, &B, &C);

	print_t(ABC);

	printf("S( ABC ) = %f\n ", square(ABC));

	delete_(ABC);
	return 0;
}
