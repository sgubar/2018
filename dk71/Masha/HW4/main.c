#include <stdio.h>
#include <stdlib.h>
#include "dk_rectangle_array.h"
#include"dk_rectangle.h"
int main()
{
   RectangleArray *theArray = createArray(5);

 int A_x, A_y, B_x, B_y, C_x, C_y,D_x,D_y;
int K=1,Check=1;
printf("Rectangle\n\n");
do
{

    printf("Enter the coordinate of point  A:\n");
    Enter_the_Coordinate(&A_x,&A_y);
    printf("Enter the coordinate of point  B:\n");
    Enter_the_Coordinate(&B_x,&B_y);
    printf("Enter the coordinate of point  C:\n");
    Enter_the_Coordinate(&C_x,&C_y);
    printf("Enter the coordinate of point  D:\n");
    Enter_the_Coordinate(&D_x,&D_y);
	Point A = {A_x,A_y};
	Point B = {B_x,B_y};
	Point C = {C_x,C_y};
	Point D = {D_x,D_y};

	Point ABCD={&A, &B, &C, &D};

	printf("Ploscha (Area) ABCD = %f\n\n", Ploscha(&ABCD));

	addElement(theArray, &ABCD, Ploscha(&ABCD));
printf("Choose the next step 1-continue,0-stop\n");
scanf("%d",&Check);
K++;
}
while(Check==1&&K<=5);


	FILE *theFile = fopen("test.json", "a+");

	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);

	inception_sort(theArray);


	FILE *theFile2 = fopen("sort.json", "a+");

	writeArrayToJSON(theFile2, theArray);

	fflush(theFile2);
	fclose(theFile2);

	freeArray(theArray);

	printf("\END,please check created file\n");

	return 0;
}
