#include "dk_elips.h"
#include <math.h>
Elips *createElips(Point *A, Point *B, Point *C, Point *D, Point *middle) //function which returns pointer to rectangle created on given points
{
    Elips *theResult = NULL; //declaring resulting pointer, its points to nowhere now

    if(A != NULL && B != NULL && C != NULL && D != NULL && middle != NULL) //validations of pointers
    {
       if(abs(A->x) == abs(C->x) && abs(B->y) == abs(D->y) /*&& A->y == C->y && B->x == D->x*/) //checking for the correctness of the figure
        {
            theResult = ( Elips* )malloc(sizeof(Elips));//allocating memory for the size of the structure with the shape data

            if(theResult != NULL)//checking for proper allocation of memory
            {
                theResult->A = A;
                theResult->B = B;
                theResult->C = C;
                theResult->D = D;
                theResult->middle = middle;
            }
        }

    }

    return theResult;
}

void destroyElips(Elips *aElips)
{
    if(aElips != NULL)//validation of the pointer
    {
        free(aElips->A);//freeing the memory occupied by each point
        free(aElips->B);
        free(aElips->C);
        free(aElips->D);
        free(aElips->middle);
        free(aElips);//freeing memory occupied by whole structure
    }
}

int ElipsArea(Elips *aElips)
{
    int theResult = 0;

    if(aElips != NULL)//validation of pointer
    {
        int aSide = (int)sqrt(pow(aElips->C->x - aElips->middle->x, 2)+pow(aElips->C->y - aElips->middle->y ,2));
        int bSide = (int)sqrt(pow(aElips->B->x - aElips->middle->x, 2)+pow(aElips->B->y - aElips->middle->y ,2));
        theResult = 3.14*aSide * bSide;//calculation of area of Elips
    }

    return theResult;
}
