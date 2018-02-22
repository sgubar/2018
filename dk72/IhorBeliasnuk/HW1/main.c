#include <stdio.h>

#include "dk_tool.h"

int main()
{
int i = 0, j = 0;
    int SIZE = 0;

    int matrix1[SIZE][SIZE];
    int matrix2[SIZE][SIZE];
    int resultingMatrix[SIZE][SIZE];


    printf("Enter size of your matrix:\n");
    scanf("%i", &SIZE);
    while(SIZE <= 1)
    {
        printf("The size can not be less than or equal to one. Enter correct value:\n");
        scanf("%i", &SIZE);
    }
    
    printf("\nEnter first matrix:\n\n");

    for(i = 0; i < SIZE; i++) //using "for" loop for assign values to cells of matrix
    {
        for(j = 0; j < SIZE; j++)
        {
            printf("Enter [%i][%i] element of matrix: ", i, j);
            scanf("%i", &matrix1[i][j]);
        }
    }

    printf("\nEnter second matrix:\n\n");

    for(i = 0; i < SIZE; i++) //same as with the first matrix
    {
        for(j = 0; j < SIZE; j++)
        {
            printf("Enter [%i][%i] element of matrix: ", i, j);
            scanf("%i", &matrix2[i][j]); // NOLINT
        }
    }

    squareMatrixProduct(SIZE, resultingMatrix, matrix1, matrix2); /*using function "squareMatrixProduct" for multiply 
    matrix1 and matrix 2. Result of multiplication saved in "resultingMatrix" */

    printf("Product:\n\n");

    for(i = 0; i < SIZE; i++) //displaying the result on the screen
    {
        for(j = 0; j < SIZE; j++)
        {
            printf("%i ", resultingMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
