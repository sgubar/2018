#include <stdio.h>
#include "dz2_array.h"

int main(int argc, const char * argv[])
{
	RactangleArray *theArray = createArray(2);
	
	Point A = {0,0};
	Point B = {0,7};
	Point C = {2,7};
	Point D = {2,0};
	Ractangle ABCD = {&A, &B, &C, &D};
 
 	addElement(theArray, &ABCD);
 	
 	B.y=5;
 	C.y=5;
 	
 	addElement(theArray, &ABCD);
 	
	FILE *theFile = fopen("test.json", "w+");
	
	writeArrayToJSON(theFile, theArray);
	
	fflush(theFile);
	fclose(theFile);
	
	freeArray(theArray);
	
	printf("UUURRAAA! Polychulos'\n");
	return 0;
}


