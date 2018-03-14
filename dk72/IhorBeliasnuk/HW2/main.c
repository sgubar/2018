#include <stdio.h>
#include "dk_rectangle.h"

int main()
{
    Point A = {-1, 2};//declaring points
    Point B = {1, 2};
    Point C = {1, -1};
    Point D = {-1, -1};

    Rectangle *example = createRectangle(&A, &B, &C, &D);

    if(example == NULL)
    {
        printf("An error occurred\n");//if something goes wrong and the rectangle was not created, we get that message
    }
    else
    {
        printf("Square of rectangle = %d\n", rectangleArea(example));
    }

    destroyRectangle(example);
}
