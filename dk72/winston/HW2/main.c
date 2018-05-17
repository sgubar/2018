#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "dk_rectangle.h"

int main()
{
    int A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y;

    printf("Rectangle\n\n");
    printf("Enter the coordinates of point A:\n");
    Enter_Coordinate (&A_x,&A_y);
    printf("Enter the coordinates of point B:\n");
    Enter_Coordinate (&B_x,&B_y);
	printf("Enter the coordinates of point C:\n");
	Enter_Coordinate_Point_C (&C_x,&C_y, A_x, A_y, B_x, B_y);

    D_x=(A_x+C_x)-B_x;
    D_y=(A_y+C_y)-B_y;

    Point A = {A_x,A_y};
	Point B = {B_x,B_y};
	Point C = {C_x,C_y};
	Point D = {D_x,D_y};

	Rectangle *ABCD = createRectangle(&A, &B, &C, &D);

	printRectangle(ABCD);

	printf("Area ABCD = %f\n", areaRectangle(ABCD));

	destroyRectangle(ABCD);

    return 0;
}
