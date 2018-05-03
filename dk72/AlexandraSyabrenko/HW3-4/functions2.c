#include "functions2.h"
#include <stdlib.h>


ArrayCircles *createArray(int aNumber)
{
    ArrayCircles *theResult = NULL;
    
    if (aNumber > 0)
    {
        theResult = (ArrayCircles *)malloc(sizeof(ArrayCircles));
        
        if (NULL != theResult)
        {
            theResult->circles = (Circle **)malloc(sizeof(Circle *)*aNumber); 
            
            if (NULL != theResult->circles)
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

void freeArray(ArrayCircles *anArray)
{
    if (NULL != anArray) 
    {
        for (int i = 0; i < anArray->count; i++)
        {
            destroyCircle(anArray->circles[i]);
        }
        
        free(anArray->circles);
        free(anArray);
    }
}

int addElement(ArrayCircles *anArray, Circle *aCircle)
{
    int theResult = -1; 
    
    if (NULL != anArray && NULL != aCircle && anArray->count < anArray->number)
    {
        anArray->circles[anArray->count] = createCircle(aCircle->center, aCircle->radius);
        
        theResult = anArray->count;
        anArray->count++;
    }
    
    return theResult;
}


int addElementByIndex(ArrayCircles *anArray, Circle *aCircle, int index)
{
    int theResult = -1; 
    
    if (NULL != anArray && NULL != aCircle && index < anArray->number)
    {
        if (anArray->circles[index] == NULL)
        {
            anArray->circles[index] = createCircle(aCircle->center, aCircle->radius);
            anArray->count++;
        }
        else
        {
            destroyCircle(anArray->circles[index]);
            anArray->circles[index] = createCircle(aCircle->center, aCircle->radius);
        }
        
        theResult = index;
        
    }
    
    return theResult;
}

void writeArrayToJSON(FILE *aFile, ArrayCircles *anArray)
{
    if (NULL == anArray || NULL == aFile)
    {
        return ;
    }
    
    fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
            anArray->number, anArray->count);
    fprintf(aFile, "\"circles\" : \n[\n");
    
    for (int i = 0; i < anArray->count; i ++)
    {
        writeCircleToJSON(aFile, anArray->circles[i]);
        
        if (i < anArray->count - 1)
        {
            fprintf(aFile, ",");
        }
        fprintf(aFile, "\n");
    }
    
    fprintf(aFile, "],\n}");
}
