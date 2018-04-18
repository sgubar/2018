#include "dk_square.h"
#include "dk_square_array.h"


int main(int argc, const char * argv[])
{

    SquareArray *theArray = createArray(5);

 int A_x, A_y, B_x, B_y, C_x, C_y;
 int count=1, N=1;

do
 {
   
    printf("enter the coordinates of the point A:\n");
    input_coordinates (&A_x,&A_y);
    printf("enter the coordinates of the point B:\n");
    input_coordinates (&B_x,&B_y);
	printf("enter the coordinates of the point C:\n");
	input_coordinates_C (&C_x,&C_y, A_x, A_y, B_x, B_y);

	Point A = {A_x,A_y};
	Point B = {B_x,B_y};
	Point C = {C_x,C_y};
	Point D = {(A_x+C_x)-B_x,(A_y+C_y)-B_y};

	Square ABCD={&A, &B, &C, &D};

	addElement(theArray, &ABCD);
	printf("input next square - 1; finish -0?\n");
	scanf("%d",&count);
	K++;
 }while(count==1 && N<=5);

	FILE *theFile = fopen("C:/test.json", "a+");

	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);

	freeArray(theArray);

	printf("\n code finished work...\n");

	return 0;
}
