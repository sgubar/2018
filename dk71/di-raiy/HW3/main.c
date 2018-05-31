#include <stdio.h>
#include "dk_triangle2.h"
#include "dk_triangle_array.h"

int main(int argc, const char * argv[])
{

	int kol, i, Ax, Ay, Bx, By, Cx, Cy;

	printf("Enter kol");
	scanf("%d", &kol);
	triangleArray *theArray = createArray(kol);
	for(i=1; i<=kol; i++)
	 {
	 	printf("\n\tEnter %d triangle\n", i);

	    enter(&Ax,&Ay);
	 	enter(&Bx,&By);
	 	enter(&Cx,&Cy);

		point_t A = {Ax,Ay};
		point_t B = {Bx,By};
		point_t C = {Cx,Cy};
		triangle_t ABC = {&A, &B, &C};

		addElement(theArray, &ABC);
	 }


	FILE *theFile = fopen("test2.json", "a+");

	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);
	destroyA(theArray);

	return 0;
}
