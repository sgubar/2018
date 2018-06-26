#include <stdio.h>
#include "dk_rectangle_array.h"

int main(int argc, const char * argv[])
{
   RectangleArray *theArray = createArray(5);
   int mass[8];
    char symbols[4]={'A','B','C','D'};
    int i,j=0,m=0;
    for(i=0;i<4;i++)
    {
        printf("Enter the x and y of point %c:\n",symbols[i]);
        for(j=0+m;j<2+m;j++)
        {
            scanf("%d",&mass[j]);
        }
        m+=2;
    }

    Point A = {mass[0],mass[1]};
	Point B = {mass[2],mass[3]};
	Point C = {mass[4],mass[5]};
	Point D = {mass[6],mass[7]};

 if(checktherectangle(&A, &B, &C, &D)==0)
        printf("Coordinate is not right, try again\n");
    else
    {
	Point ABCD = {&A, &B,&C,&D};

	addElement(theArray, &ABCD);
	FILE *theFile = fopen("D:/КПІ/кпі/Інформатика/hw3/hw3/test.json", "a+");

	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);

	freeArray(theArray);


	return 0;
    }
}
