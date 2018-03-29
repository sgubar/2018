#include "dk_triangle.h"

Triangle *createTriangle(Point *A, Point *B, Point *C) //function which returns pointer to rectangle created on given points
{
    Triangle *theResult = NULL; //declaring resulting pointer, its points to nowhere now

    if(A != NULL && B != NULL && C != NULL) //validations of pointers
    {
        if(abs(A->y) == abs(C->y) && abs(C->x) == abs(B->x)) //checking for the correctness of the figure
        {
            theResult = ( Triangle* )malloc(sizeof(Triangle));//allocating memory for the size of the structure with the shape data

            if(theResult != NULL)//checking for proper allocation of memory
            {
                theResult->A = A;
                theResult->B = B;
                theResult->C = C;
            }
        }

    }

    return theResult;
}

void destroyTriangle(Triangle *aTriangle)
{
    if(aTriangle != NULL)//validation of the pointer
    {
        free(aTriangle->A);//freeing the memory occupied by each point
        free(aTriangle->B);
        free(aTriangle->C);

        free(aTriangle);//freeing memory occupied by whole structure
    }
}

int triangleArea(Triangle *aTriangle)
{
    int theResult = 0;

    if(aTriangle != NULL)//validation of pointer
    {
        int aSide = (int)sqrt(pow(aTriangle->B->x - aTriangle->C->x, 2) + pow(aTriangle->B->y - aTriangle->C->y, 2));
        int bSide = (int)sqrt(pow(aTriangle->A->x - aTriangle->C->x, 2) + pow(aTriangle->A->y - aTriangle->C->y, 2));
        
        
		
		
		theResult = (aSide * bSide) / 2;//calculation of area of triangle
    }

    return theResult;
}
