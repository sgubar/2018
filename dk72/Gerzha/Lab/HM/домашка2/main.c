#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "DZ_2.h"

int main(void)
{
	struct tag_circle *Circle = createCircle();
	printf("\n\t- Center point [x] : ");
	*(Circle->center->dot_x) = checkValidity();
	printf("\n\t- Center point [y] : ");
	*(Circle->center->dot_y) = checkValidity();
	printf("\n\t- Point on circle [x] : ");
	*(Circle->radius->point_B->dot_x) = checkValidity();
	printf("\n\t- Point on circle [y] : ");
	*(Circle->radius->point_B->dot_y) = checkValidity();
	calculateArea(Circle);
	printCircle(Circle);
	destroyCircle(Circle);
	return 0;
}
