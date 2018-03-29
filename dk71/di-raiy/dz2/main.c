#include <stdio.h>
#include <math.h>
#include "dz2.h"

int main(int argc, const char * argv[])
{
	Point A = {2,3};
	Point B = {5,6};
	Point C = {2,8};
	Point D = {8,6};

	Trapeze *ABCD = createTrapeze(&A, &B, &C, &D);

	printTrapeze(ABCD);
	printf("The area of Trapeze ABCD = %.2f\n", areaTrapeze(ABCD));

	destroyTrapeze(ABCD);
	return 0;
}
