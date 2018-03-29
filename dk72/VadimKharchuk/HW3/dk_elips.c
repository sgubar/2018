#include "dk_elips.h"
#include <math.h>
Elips *createElips(Point *A, Point *B, Point *C, Point *D, Point *middle) //function which returns pointer to rectangle created on given points
{
    Elips *theResult = NULL; //declaring resulting pointer, its points to nowhere now

    if(A != NULL && B != NULL && C != NULL && D != NULL && middle != NULL) //validations of pointers
    {
       if(abs(A->x) == abs(C->x) && abs(B->y) == abs(D->y) && A->y == C->y && B->x == D->x) //checking for the correctness of the figure
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

float ElipsArea(Elips *aElips)
{
    float theResult = 0;

    if(aElips != NULL)//validation of pointer
    {
        float aSide = (float)sqrt(pow(aElips->C->x - aElips->middle->x, 2)+pow(aElips->C->y - aElips->middle->y ,2));
        float bSide = (float)sqrt(pow(aElips->B->x - aElips->middle->x, 2)+pow(aElips->B->y - aElips->middle->y ,2));
        theResult = 3.14*aSide * bSide;//calculation of area of Elips
    }

    return theResult;
}
Point *copyPointWithPoint(Point *aPoint)
{
    Point *theResult = (Point *)malloc(sizeof(Point));
    if (NULL != theResult)
    {
        theResult->x = aPoint->x;
        theResult->y = aPoint->y;
    }

    return theResult;
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
    if (NULL == aPoint || NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writeElipsToJSON(FILE *aFile, Elips *aElips)
{
    if (NULL == aElips|| NULL == aFile)
    {
        return ;
    }

    fprintf(aFile, "{\n\t\"A\" : ");
    writePointToJSON(aFile, aElips->A);
    fprintf(aFile, ", \n\t\"B\" : ");
    writePointToJSON(aFile, aElips->B);
    fprintf(aFile, ", \n\t\"C\" : ");
    writePointToJSON(aFile, aElips->C);
    fprintf(aFile, ", \n\t\"D\" : ");
    writePointToJSON(aFile, aElips->D);
    fprintf(aFile, ", \n\t\"middle\" : ");
    writePointToJSON(aFile, aElips->middle);
    fprintf(aFile, ", \n\t\"Area\" : %f,", ElipsArea(aElips));
    fprintf(aFile, "\n}");
}





