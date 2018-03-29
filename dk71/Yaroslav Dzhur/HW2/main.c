
#include <stdio.h>
#include "dk_triangle.h"

int main()
{
	Point A = {2,1};
	Point B = {-1,5};
	Point C = {-1,1};

    Triangle *example = createTriangle(&A, &B, &C);

    if(example == NULL)
    {
        printf("An error occurred\n");
    }
    else
    {
        printf("Square of triangle = %d\n", triangleArea(example));
    }

    destroyTriangle(example);
}
