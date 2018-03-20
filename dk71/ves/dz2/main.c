#include <stdio.h>
#include "dz2.h"
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	Point A = {0,0};
	Point B = {0,2};
	Point C = {5,2};
	Point D = {5,0};
	
	Rectangle *ABCD = createRectangle(&A, &B, &C, &D);

	printRectangle(ABCD);

	printf("Square rectangle ABCD = %d\n", squareRectangle(ABCD));



	destroyRectangle(ABCD);
	return 0;
}
