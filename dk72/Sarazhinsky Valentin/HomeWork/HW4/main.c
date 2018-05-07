#include "dk_square.h"
#include "dk_square_array.h"
#include <Math.h>


int main(int argc, const char * argv[])
{

    SquareArray *theArray = createArray(5);

 int A_x, A_y, B_x, B_y, C_x, C_y, D_x, D_y;
 int count=1, N=1;

do
 {
    printf("SQUARE %d\n\n",N);
    printf("enter the coordinates of the point A:\n");
    enter_coordinates(&A_x,&A_y);
    printf("enter the coordinates of the point B:\n");
    enter_coordinates(&B_x,&B_y);
	printf("enter the coordinates of the point C:\n");
	enter_coordinates(&C_x,&C_y);
	while(((B_x-A_x)*(C_x-B_x)+(B_y-A_y)*(C_y-B_y)) != 0 ){
		printf("ERROR! Invalid coordinates of the point C!\n enter other coordinates of the point C:\n");
		enter_coordinates (&C_x,&C_y);
	}

	Point A = {A_x,A_y};
	Point B = {B_x,B_y};
	Point C = {C_x,C_y};
	Point D = {(A_x+C_x)-B_x,(A_y+C_y)-B_y};

	Square ABCD={&A, &B, &C, &D};

	printf("Area ABCD = %f\n\n", areaSquare(&ABCD));

	addElement(theArray, &ABCD, areaSquare(&ABCD));

	printf("continue - 1; exit - 0 :\n");
	scanf("%d",&count);
	N++;
 }while(count==1 && N<=5);

	FILE *theFile = fopen("squares.json", "w+");

	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);

	sort_vybora(theArray);


	FILE *theFile2 = fopen("sort_squares.json", "w+");

	writeArrayToJSON(theFile2, theArray);

	fflush(theFile2);
	fclose(theFile2);
	printArray(theArray);

	freeArray(theArray);

	printf("\nthe program has completed work!\n");

	return 0;
}
