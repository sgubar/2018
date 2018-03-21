#include <stdio.h>
#include <stdlib.h>
#include "dk_matrix_minus.h"


int **yourmatr1(int **a, int m, int n)

{
    int i, j;
    a = (int **)malloc(m*n * sizeof(int *));

    if (a != NULL)
  {
        for (i = 0; i<n; i++)

                {
                    for (j = 0; j<m; j++)

                        {
                              printf("a[%d][%d] = ", i, j);
                              scanf("%d", (a + i*m + j));
                        }
                }

                printf("\n");

        for (i = 0; i<n; i++)
                {

                    for (j = 0; j<m; j++)

                        {
                                printf("%5d ", *(a + i*m + j));

                        }
                                printf("\n");

                }

                        free(a);
                        getchar();


  }
  else
    a = NULL;

    return a;




}

int **yourmatr2(int **b, int l, int o)

{
    int k, y;
    b = (int **)malloc(l*o * sizeof(int *));

    if (b != NULL)
  {
        for (k = 0; k<o; k++)

                {
                    for (y = 0; y<l; y++)

                        {
                              printf("b[%d][%d] = ", k, y);
                              scanf("%d", (b + k*l + y));
                        }
                }

                printf("\n");

        for (k = 0; k<o; k++)
                {

                    for (y = 0; y<l; y++)

                        {
                                printf("%5d ", *(b + k*l + y));

                        }
                                printf("\n");

                }

                        free(b);
                        getchar();


  }
  else
    b = NULL;

    return b;





}

int **yourmatr3(int **c, int h, int t)

{
    int u, p;
    c = (int **)malloc(h*t * sizeof(int *));

    if (c != NULL)
{


    for (u=0; u<t; h++)
        {

            for(p=0; p<h; p++)
            {
                yourmatr3[u][p] = yourmatr1[i][j] - yourmatr2[k][y];
            }

        }
    for (u=0; u<t; u++)
        {
                    printf("\n");

                    for (p=0; p<h; p++)

                        {
                            printf("  ");
                            printf("%d", *(yourmatr3[u][p]);
                        }

                printf("\n");

        }




}
else
    c = NULL;

    return c;

}
