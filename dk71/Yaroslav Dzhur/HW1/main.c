#include <stdio.h>

#include "dk_tool.h"                                                   //pidklyuchennya biblioteky

int main()
{
    int i = 0, j = 0;
    int n = 0;

    printf("Enter size of your matrix:\n");                            //zapyt rozmirnosti matric
    scanf("%i", &n);

    int matrixA[n][n];        
    int matrixB[n][n];                                                 //oholoshennya matric
    int matrixC[n][n];		  

    printf("\nEnter first matrix:\n\n");

    for(i = 0; i < n; i++)                                             //cykl for dlya vvedennya pershoyi matrici
    {
        for(j = 0; j < n; j++)
        {
            printf("Vvedit [%i][%i] znachennya matryci: ", i, j);
            scanf("%i", &matrixA[i][j]);
        }
    }

    printf("\n\nEnter second matrix:\n\n");

    for(i = 0; i < n; i++)                                             //cykl for dlya vvedennya drugoyi matrici
    {
        for(j = 0; j < n; j++)
        {
            printf("Vvedit [%i][%i] znachennya matryci: ", i, j);
            scanf("%i", &matrixB[i][j]); // NOLINT
        }
    }

    subtractedmatrix(n, matrixC, matrixA, matrixB);                   //funkciya dlya vidimannya matric

    printf("Product:\n\n");


    for(i = 0; i < n; i++)                                            //cykl for dlya vyvedennya pershoyi matrici
    {
        for(j = 0; j < n; j++)
        {
            printf("%i	", matrixA[i][j]);
        }
        printf("\n");
    }
        printf("\n");
        
    for(i = 0; i < n; i++)                                           //cykl for dlya vyvedennya drugoyi matrici
    {
        for(j = 0; j < n; j++)
        {
            printf("%i	", matrixB[i][j]);
        }
        printf("\n");
    }
        printf("\n");
        
    for(i = 0; i < n; i++)                                           //cykl for dlya vyvedennya resultuyuchoyi matrici
    {
        for(j = 0; j < n; j++)
        {
            printf("%i	", matrixC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
