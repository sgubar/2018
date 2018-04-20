#include <stdio.h>
#include "dk_tool.h"

int main()
{
	Point A = {4,9};
	Point B = {-2,5};
	Point C = {-2,9};

    Triangle *ABC = createTriangle(&A, &B, &C);

    if(ABC == NULL)
    {
        printf("An error occurred\n");
    }
    else
    {
        printf("Square = %.2f\n", (float)AreaOfTriangle(ABC));
    }

    destroyTriangle(ABC);
}
