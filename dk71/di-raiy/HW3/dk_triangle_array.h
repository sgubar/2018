#include <stdio.h>
#include "dk_triangle2.h"

typedef struct triangleSqure
{
	int number;
	int count;

	triangle_t **triangles;
}triangleArray;


triangleArray *createArray(int aNumber);
void destroyA(triangleArray *anArray);
int addElement(triangleArray *anArray, triangle_t *atriangle);
void writeArrayToJSON(FILE *aFile, triangleArray *anArray);
