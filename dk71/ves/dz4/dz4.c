#include "dz4.h"
#include "dz2_array.h"

void insertion_sort(RactangleArray *theArray, FILE *file){
	int i;
	for ( i = 1; i < theArray->count; i ++)
	{
		Ractangle *tmp = theArray->ractangles[i];
		int n = i;
	
		while (n > 0 && squareRactangle (theArray->ractangles[n - 1])>= squareRactangle(tmp))
		{
			theArray->ractangles[n] = theArray->ractangles[n - 1];
			--n;
		}
	
		theArray->ractangles[n] = tmp;
	}
   writeArrayToJSON(file, theArray);
}
void printSquare(RactangleArray *theArray){
	int i;
	for(i=0; i < theArray->count; i++){
	
	printf("%d\n", squareRactangle(theArray->ractangles[i]));
}
}

