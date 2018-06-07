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





void addElement(CircleArray *InstantArray, Circle *aCircle, float area )



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


int line_search(CircleArray *InstantArray, float key)

{

	int i;

	int pos;

    for(i = 0; i < InstantArray->count; i++)

    {

         if (SquareCircle(InstantArray->Circles[i]) == key)

        {

		printf("\nIt's right,you find it.'\n");

		pos=i;

		return pos+1;

		}

    }	
    return -1;

}




void quick_sort(CircleArray *InstantArray, int first, int last)

{

int mid, left, right;

  left = first;
  right = last;


  mid = InstantArray->area[(left + right) / 2];

  while (left <= right)

  {

    while (InstantArray->area[left] < mid) left++;

    while (InstantArray->area[right] > mid) right--;

    if (left <= right)

	{

        swap(&InstantArray->Circles[left], &InstantArray->Circles[right]);

        left++;
        right--;

	}

  }

  if (first < right) quick_sort(InstantArray, first, right);

  if (left < last) quick_sort(InstantArray, left, last);

}
