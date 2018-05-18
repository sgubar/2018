#include "dz4.h"
#include "dz3.h"

void insertion_sort(TriangleArray *theArray, FILE *file){

	int i;
	for ( i = 1; i < theArray->count; i ++)
	{
		Triangle *tmp = theArray->Triangles[i];
		int n = i;

		while (n > 0 && areaTriangle (theArray->Triangles[n - 1])>= areaTriangle(tmp))
		{
			theArray->Triangles[n] = theArray->Triangles[n - 1];
			--n;
		}

		theArray->Triangles[n] = tmp;
	}
   writeArrayToJSON(file, theArray);
}
void printTriangle(TriangleArray *theArray){
	int i;
	for(i=0; i < theArray->count; i++){

	printf("%d\n", areaTriangle(theArray->Triangles[i]));
}
}

