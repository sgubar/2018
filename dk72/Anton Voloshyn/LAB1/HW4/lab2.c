

#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"



ArrayOfTriangle *createArray(int aNumber)
{
    ArrayOfTriangle *theResult = NULL;
    
    if (aNumber > 0)
    {
        theResult = (ArrayOfTriangle *)malloc(sizeof(ArrayOfTriangle));
        
        if (NULL != theResult)
        {
            theResult->Triangles = (Triangle **)malloc(sizeof(Triangle *)*aNumber);
            
            if (NULL != theResult->Triangles)
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

void freeArray(ArrayOfTriangle *anArray)
{
    if (NULL != anArray)
    {
        for (int i = 0; i < anArray->count; i ++)
        {
            destroyTriangle(anArray->Triangles[i]);
        }
        
        free(anArray->Triangles);
        free(anArray);
    }
}

int addTriangle(ArrayOfTriangle *anArray, Triangle *aTriangle)
{
    int theResult = -1;
    
    if (NULL != anArray && NULL != aTriangle &&
        anArray->count < anArray->number)
    {
        anArray->Triangles[anArray->count] =
        createTriangle(aTriangle ->A , aTriangle ->B, aTriangle ->C);
        theResult = anArray->count;
        anArray->count ++;
    }
    
    return theResult;
}

void writeArrayToJSON(FILE *aFile, ArrayOfTriangle *anArray)
{
    if (NULL == anArray || NULL == aFile)
    {
        return ;
    }
    
    fprintf(aFile, "{\n\"number\" : %d,\n\"count\" : %d,\n",
            anArray->number, anArray->count);
    fprintf(aFile, "\"Triangles\" : \n[\n");
    
    for (int i = 0; i < anArray->count; i ++)
    {
        writeFileToJSON(aFile, anArray->Triangles[i]);
        
        if (i < anArray->count - 1)
        {
            fprintf(aFile, ",");
        }
        fprintf(aFile, "\n");
    }
    
    fprintf(aFile, "],\n}");
}
