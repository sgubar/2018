#include <stdio.h>
#include <stdlib.h>


static int partition(char a[], int left, int right)
{
    int pivot, i, j, t;
    pivot = a[left];
    i = left; j = right + 1;

    while (1)
    {
        do i++; while (a[i] <= pivot && i <= right);
        do j--; while (a[j] > pivot);
        if (i >= j) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[left]; a[left] = a[j]; a[j] = t;
    return j;
}

extern void quickSortChar(char a[], int left, int right)
{
    int j;
    if (left < right)
    {
        j = partition(a, left, right);
        quickSortChar(a, left, j - 1);
        quickSortChar(a, j + 1, right);
    }
}



void main()
{
  int ii, nastya, nastya1, iii;
  char key;
  FILE * ptrFile = fopen( "array.txt" , "rb" );

  if (ptrFile == NULL)
  {
      fputs("error", stderr);
      exit(1);
  }


  fseek(ptrFile , 0 , SEEK_END);
  long lSize = ftell(ptrFile);
  rewind (ptrFile);

  char * buffer = (char*) malloc(sizeof(char) * lSize);
  if (buffer == NULL)
  {
      fputs("error mem", stderr);
      exit(2);
  }

  size_t result = fread(buffer, 1, lSize, ptrFile);
  if (result != lSize)
  {
      fputs("err read", stderr);
      exit (3);
  }


  fclose (ptrFile);




    printf("\n  Data from input file: \n");
    puts(buffer);
    quickSortChar(buffer, 0, strlen(buffer) - 1);
    printf("\n  Data to output file: \n");
    puts(buffer);
    nastya=strlen(buffer) - 1;
    nastya1=nastya - 1;
    FILE * File1 = fopen( "array_out.txt" , "w" );

    for (ii = 0; ii <nastya ; ii++)
	fprintf(File1, "%c ", buffer[ii]);
	fclose (File1);



	printf("\n Element to find: ");
	scanf("%c", &key);

	for (ii = 0; ii <nastya ; ii++)
	{
	if(key==buffer[ii])
	{
		iii=ii+1;
		printf("\n Number of element is : ");
			printf("%d",iii);
		break;
		}
	if(ii==nastya1)
		printf("\n Misha vse dich davay po novoy ");
	}

	printf("\n End \n\n");
    system("pause");

}
