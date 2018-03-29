#include <stdio.h>
#include "dz3.h"

int main(int argc, const char * argv[])
{
	TrapezeArray *theArray = createArray(5);

	Point A = {3,4};
	Point B = {5,6};
	Point C = {10,9};
	Point D = {7,1};
	Trapeze ABCD = {&A, &B, &C, &D};

	addElement(theArray, &ABCD);

	A.y = 6;
	B.x = 6;

	addElement(theArray, &ABCD);

	FILE *file = fopen("test.json", "w+");

	writeArrayToJSON(file, theArray);

	fflush(file);
	fclose(file);

	freeArray(theArray);

	system("PAUSE");
	return 0;
}
