#include <stdio.h>
#include "dz3.h"
#include "dz5.h"

int main(int argc, const char * argv[])
{
	TrapezeArray *theArray = createArray(5);
	
	Point A = {2,0};
	Point B = {0,2};
	Point C = {0,0};
	Point D = {2,2};
	Trapeze ABCD = {&A, &B, &C, &D};
	
	addElement(theArray, &ABCD);
	
	A.y = 4;
	B.x = 4;
	
	addElement(theArray, &ABCD);
	
	A.x = 6;
	B.y = 6;
	C.x = 0;
	C.y = 0;
	D.y = 6;
	D.x = 6;
	
	addElement(theArray, &ABCD);
	
    A.x = 4;
	A.y = 0;
	B.x = 0;
	B.y = 4;
	C.y = 0;
	D.x = 4;
	D.y = 4;
	
	addElement(theArray, &ABCD);
	
	FILE *file = fopen("test.json", "w+");
	shellSortArray(theArray,file);
	
	fflush(file);
	fclose(file);
	
	freeArray(theArray);
	
	system("PAUSE");
	return 0;
}
