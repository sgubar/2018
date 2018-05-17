#include <stdio.h>
#include "dk_rectangle.h"
#include "dk_rectangle_array.h"

int main()
{
    int number, check=0, check_=0;
    int A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y;

    printf("Start!\n\n");
    printf("Enter the number of rectangles: ");
    scanf("%d", &number);

    RectangleArray *theArray = createArray(number);

    do
    {
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

	    Rectangle ABCD={&A, &B, &C, &D};

	    addElement(theArray, &ABCD);

	    check_++;

	    if(check_ == number) break;

	    printf("Choose action:\n"
               "Continue - 1\n"
               "Exit-0\n"
               "Your choise: ");
	    scanf("%d", &check);
	    printf("\n");

    }while(check ==1);

	FILE *theFile = fopen("test.json", "a+");

	writeArrayToJSON(theFile, theArray);

	sort_buble(theArray);

	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);

	freeArray(theArray);

	printf("\nThe End! Check the created file!\n");

    return 0;
}
