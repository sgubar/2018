int main ()
{
        int *a;
        int i, j, n, m;


        printf("Enter arrows: \n");
        scanf("%d", &n);
        printf("Enter columns: \n");
        scanf("%d", &m);


        yourmatr1(a);

        /*a = (int **)malloc(m*n * sizeof(int *));

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
*/
}
