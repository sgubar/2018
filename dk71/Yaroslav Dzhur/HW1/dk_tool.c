#include "dk_tool.h"

void subtractedmatrix(int n, int matrixC[n][n], int matrixA[n][n], int matrixB[n][n])
{
    int i = 0, j = 0;

    for(i = 0; i < n; i++)                                                                  
    {
        for(j = 0; j < n; j++)                                                         
        {
            matrixC[i][j] = 0;
                matrixC[i][j] = matrixA[i][j] - matrixB[i][j];                               //vidnimannya matric
        }
    }
}
