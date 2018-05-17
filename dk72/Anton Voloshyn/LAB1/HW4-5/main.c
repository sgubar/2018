#include <stdlib.h>
#include <stdio.h>
#include "dk_tool.h"
#include "lab2.h"

int main()
{
    ArrayOfTriangle *theArray = createArray(3);
    
    Point A = {4,9};
    Point B = {-2,5};
    Point C = {-2,9};
    
    Point X = {-5,5};
    Point Y = {-1,2};
    Point Z = {-1,5};
    
    Triangle *ABC = createTriangle(&A, &B, &C);
    Triangle *XYZ = createTriangle(&X, &Y, &Z);
    if(ABC == NULL && XYZ == NULL)
    {
        printf("oop, error\n");
    }
    else
    {
        printf("Square(ABC) = %.2f\n", (float)AreaOfTriangle(ABC));
        printf("Square(XYZ) = %.2f\n", (float)AreaOfTriangle(XYZ));
    }
    FILE *theFile = fopen("file.json", "a+");
    writeFileToJSON(theFile, theArray);
    fflush(theFile);
	fclose(theFile);
    
	quickSort( theArray, 0, theArray->count-1);


	FILE *theFile2 = fopen("D:/file_sort.json", "a+");

	writeArrayToJSON(theFile2, theArray);

	fflush(theFile2);
	fclose(theFile2);
	while(1)
	{
		printf("Vedit' shukane znachennia:");
		int i, find;
		scanf("%i", &find);
		i = binary_find(theArray,find);

		if (i!=-1)
		{
			break;
		}

	freeArray(theArray);


	return 0;
	}
}

