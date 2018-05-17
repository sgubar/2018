#include <stdio.h>
#include "dz3.h"

int main(int argc, const char * argv[])
{
	TriangleArray *theArray = createArray(4);

	Point A = {2,1};
	Point B = {-1,5};
	Point C = {-1,1};
	Triangle ABC = {&A, &B, &C};

	addElement(theArray, &ABC);

	A.y = 6;
	B.x = 6;

	addElement(theArray, &ABC);

	FILE *file = fopen("test.json", "w+");

	writeArrayToJSON(file, theArray);

	fflush(file);
	fclose(file);

	freeArray(theArray);

	system("PAUSE");
	return 0;
}
