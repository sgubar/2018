#include <stdio.h>
#include "dk_line.h"

int main(int argc, const char * argv[])
{
	int x1, x2, x3, y1, y2, y3;
	printf("enter the coordinates of point A: ");
	scanf("%d,%d",&x1,&y1);
	printf("enter the coordinates of point B: ");
	scanf("%d,%d",&x2,&y2);
	printf("enter the coordinates of point C: ");
	scanf("%d,%d",&x3,&y3);
	Point A = {x1,y1};
	Point B = {x2,y2};
	Point C = {x3,y3};
	
	Square *ABC = createSquare(&A, &B, &C);

	printSquare(ABC);

	printf("The area of square ABC = %f\n", areaSquare(ABC));
	
	// insert code here...
	printf("Hello, World!\n");

	destroySquare(ABC);
	return 0;
}
