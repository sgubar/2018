#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Point A = {0,4};
	Point B = {3,0};
	Point C = {0,0};
	
	Triangle *ABC = createTriangle(&A ,&B , &C);
	
	printTriangle(ABC);
	
	printf("Square of triangle ABC = %f\n", squareTriangle(ABC));
	
	
	destroyTriangle(ABC);
	
	
	return 0;
}
