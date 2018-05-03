#include <stdio.h>

#include <stdlib.h>

#include <malloc.h>

#include <math.h>



#include "circle.h"
#include "circle_array.h"







CircleArray *CreateArray(int aNumber)

{

    CircleArray *theResult = NULL;

    if(aNumber > 0)

    {

        theResult = (CircleArray *)malloc(sizeof(CircleArray));

        if(NULL != theResult)

        {

            theResult->Circles = malloc(sizeof(Circle *)*aNumber);


            if(NULL != theResult->Circles)

            {
                theResult->number = aNumber;

                theResult->count = 0;

            }

			else

            {

                free(theResult);

                theResult = NULL;

            }

        }

    }

    return theResult;

}







void freeArray(CircleArray *InstantArray)



{

	int i;
	
	if (NULL != InstantArray)

	{

		for (i = 0; i < InstantArray->count; i ++)

		{

			FreeCircle(InstantArray->Circles[i]);

		}

		free(InstantArray->Circles);
		free(InstantArray);

	}

}





void addElement(CircleArray *InstantArray, Circle *aCircle, float area)

{
    int result = -1;
    if(NULL != InstantArray && NULL != aCircle && InstantArray->count < InstantArray->number)
    {

        InstantArray->Circles[InstantArray->count] = createCircle(aCircle->Center, aCircle->Radius);
        InstantArray->area[InstantArray->count] = area;
        result = InstantArray->count;
        InstantArray->count++;

    }

}




void writeArrayToJSON(FILE *aFile, CircleArray *InstantArray)

{

    if (NULL == InstantArray || NULL == aFile)	return;

    fprintf(aFile, "{\n\"number \" : %d,\n\"count \" : %d,\n",

    InstantArray->number, InstantArray->count);

    fprintf(aFile, "\"Circles\" : \n[\n");
   
    int i;
    for ( i = 0; i < InstantArray->number; i++)

    {

        writeCircletToJSON(aFile, InstantArray->Circles[i]);

        if (i < InstantArray->number - 1)	fprintf(aFile, ",");
        fprintf(aFile, "\n");

    }

    fprintf(aFile, "],\n}");
}





void insertion_sort(CircleArray *InstantArray)

{

    Circle *Element=NULL;

    int  location;
	int i;

    for (i = 1; i < InstantArray->count; i++)

    {
        Element = InstantArray->Circles[i];
        location = i - 1;

        while(location >= 0 && InstantArray->area[location] > InstantArray->area[i])

        {
            InstantArray->Circles[location+1] = InstantArray->Circles[location];
            
            location = location - 1;

        }

        InstantArray->Circles[location+1] = Element;

    }

}


