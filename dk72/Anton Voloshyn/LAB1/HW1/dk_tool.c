#include "dk_tool.h"

void RezultMatrix(int size, int matrixC[size][size], int matrixA[size][size], int matrixB[size][size])
{
    int i = 0, j = 0;

    for(i = 0; i < size; i++)                                                                  
    {
        for(j = 0; j < size; j++)                                                         
        {
            matrixC[i][j] = 0;
                matrixC[i][j] = matrixA[i][j] - matrixB[i][j];                               //vidnimannya matric
        }
    }
}
