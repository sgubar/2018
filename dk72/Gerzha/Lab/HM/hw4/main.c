#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "DZ_3.h"

#define ARR_LEN 2

int main(void)
{
	struct tag_array *array = createArray(ARR_LEN);
	for (int i = 0; i < ARR_LEN; ++i)
	{
		printf("circle %d\n", i);
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


		add_to(array, Circle);
	}
	printf("%s\n", array_to_json(array));

	sort_array(array);

	printf("%s\n", array_to_json(array));
	deleteArray(array);
	
	return 0;
}
