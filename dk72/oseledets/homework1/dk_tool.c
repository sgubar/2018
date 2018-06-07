#include "dk_tool.h"

void squareMatrixProduct(int SIZE, int resultingMatrix[SIZE][SIZE], int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE])
{
    int i = 0, j = 0, k = 0;

    for(i = 0; i < SIZE; i++)    //using "for" loops to access to rows
    {
        for(j = 0; j < SIZE; j++)//and columns of resulting matrix
        {
            resultingMatrix[i][j] = 0;

            for(k = 0; k < SIZE; k++)
            {
                resultingMatrix[i][j] += matrix1[i][k] * matrix2[k][j]; /*each number in the resulting matrix is the sum of the products of
elements with the same indices of the row of the first matrix and column of the second */
            }
        }
    }
}