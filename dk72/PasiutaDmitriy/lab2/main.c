#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"dk_tool.h"


int main()

{
    char *path="f.txt";

    create(path);


    float TimeStart,TimeStop;
    int sizeOfArr=0;

    sizeOfArr= amOfCInF(sizeOfArr);
    FILE *f=fopen("f.txt", "r" );

    char *arr = malloc(sizeof(char)*sizeOfArr) ;
    fgets(arr,sizeOfArr,f);
    fclose(f);
    printf("\n\n");

    /*for(int i=0;i<sizeOfArr;i++)
{
    printf("%c",arr[i]);
}*/
    TimeStart = clock()/(float)CLOCKS_PER_SEC;
    bubleSort(arr,sizeOfArr);
    TimeStop = clock()/(float)CLOCKS_PER_SEC;
    printf("\n\n");

    /*for(int i=0;i<sizeOfArr;i++)
  {
      printf("%c",arr[i]);

  }*/

    FILE *bu = fopen("bublesort.txt","w");
    for(int i=0;i<sizeOfArr;i++)
    {
        fprintf(bu,"%c",arr[i]);

    }
    fclose(bu);
    printf("\nbublesort: %f \n", TimeStop-TimeStart);

    free(arr);

    f=fopen("f.txt", "r" );
    *arr = malloc(sizeof(char)*sizeOfArr);//
    fgets(arr,sizeOfArr,f);
    fclose(f);

    arr[sizeOfArr-1]='\0';
    printf("\n\n");
    /*for(int i=0;i<sizeOfArr;i++)
  {
      printf("%c",arr[i]);

  }*/
    TimeStart = clock()/(float)CLOCKS_PER_SEC;
    selectionSort(arr, sizeOfArr-1);
    TimeStop = clock()/(float)CLOCKS_PER_SEC;
    printf("\n\n");
    /*for(int i=0;i<sizeOfArr;i++)
   {
       printf("%c",arr[i]);

   }*/
    FILE *se = fopen("selectionSort.txt","w");
    for(int i=0;i<sizeOfArr;i++)
    {
        fprintf(se,"%c",arr[i]);

    }
    fclose(se);
    printf("\nselectionSort: %f \n", TimeStop-TimeStart);
    free(arr);
    f=fopen("f.txt", "r" );
    *arr = malloc(sizeof(char)*sizeOfArr);
    fgets(arr,sizeOfArr,f);

    fclose(f);
    arr[sizeOfArr-1]='\0';
    printf("\n\n");
    /*for(int i=0;i<sizeOfArr;i++)
  {
      printf("%c",arr[i]);

  }*/
    TimeStart = clock()/(float)CLOCKS_PER_SEC;
    insertionSort(arr, sizeOfArr);
    TimeStop = clock()/(float)CLOCKS_PER_SEC;
    printf("\n\n");
    /*for(int i=0;i<sizeOfArr;i++)
   {
       printf("%c",arr[i]);
   }*/
    FILE *in = fopen("insertionSort.txt","w");
    for(int i=0;i<sizeOfArr;i++)
    {
        fprintf(in,"%c",arr[i]);

    }
    fclose(in);
    printf("\ninsertionSort : %f\n", TimeStop-TimeStart);
    free(arr);


}
