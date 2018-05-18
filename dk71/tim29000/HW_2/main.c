#include <stdio.h>
#include "ellipse.h"

int main()
{
	Point A = {-2, 0};
    Point B = {0, 1};
    Point C = {2, 0};
    Point D = {0, -1};
    Point Centre = {0,0};


	Ellipse *Ellipson = createEllipse(&A, &B, &C, &D, &Centre);

    if(Ellipson == NULL)
    {
        printf("ERROR\n");
    }
    else
    {
        printf("The Square of Ellipse = %d\n", Ellipse_Area(Ellipson));
    }

	destroyEllipse(Ellipson);
}
