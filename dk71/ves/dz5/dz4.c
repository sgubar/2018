#include "dz4.h"
#include "dz2_array.h"

void shell_sort(RactangleArray *theArray)
{
   int i, j, step;
    int *buffer;
    for (step = theArray->count / 2; step > 0; step = step/ 2)
	{
        for (i = step; i < theArray->count; i++)
        {
            buffer = theArray->ractangles[i];
            for (j = i; j >= step; j -= step)
            {
                if (squareRactangle(buffer) < squareRactangle(theArray->ractangles[j-step]))
                    {
			        theArray->ractangles[j] = theArray->ractangles[j-step];
			        }
                else
                    {
                    break;
                }

            theArray->ractangles[j-step] = buffer;
        	}
		}
	}
}

int binary_find(RactangleArray *theArray, int search)
{
int i, left, right;
left = 0; right = theArray->count-1;
while (1)
 {
    if (left > right) return (-1);
    i = left + (right - left) / 2;
    if (squareRactangle(theArray->ractangles[i]) < search) left = i + 1;
    if (squareRactangle(theArray->ractangles[i]) > search) right = i - 1;
    if (squareRactangle(theArray->ractangles[i]) == search) return i+1;
 }

}
void printSquare(RactangleArray *theArray)
{
	int i;
	for(i=0; i < theArray->count; i++)
	{
	
	printf("%d\n", squareRactangle(theArray->ractangles[i]));
	}
}

