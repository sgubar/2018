#include <stdio.h>
#include "dk_triangle.h"
#define R 2.5
int main(int argc, const char * argv[])
{
    Point A = {0,6};
    Point B = {0,3};
    Point C = {8,0};

    Triangle *ABC = createTriangle(&A, &B,&C);

    printTriangle(ABC);

    printf("The square of triangle ABC = %f\n", flatTriangle(ABC));

    destroyTriangle(ABC);
    return 0;
}
