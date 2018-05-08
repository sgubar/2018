#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000



int main(int argc, char *argv[])
{	int choser  = 0, menu;
	int ArraySize = N;
	int i = 0;
	int startTime, stopTime;
	int key;
	char *Array = malloc(sizeof(int)*ArraySize);
	random(Array);
	writeRandom(Array);
	do
		{
			printf("\n\tChoose ur action:  \n 1) Make a Quick Sort\n 2) Line Search\n 3) Exit \n");
			scanf("%d", &menu);
			switch(menu)
				{
					case 1:
						startTime = clock();
						quickSort(Array, 0,  N - 1 );
						stopTime = clock();
						printf("\n Time for sort: %d ms\n", stopTime - startTime);
						writeQuickSort(Array);
						break;
					
					
					case 2:
							printf("Give me key: ");
							scanf("%d", &key);
							startTime = clock();
							if (line_find(Array, key) == 1)
								{
									printf("Found\n\n\n");
								}
							else printf("Not Found\n\n\n");
							stopTime = clock();
							printf("\n Time for search: %d ms\n", stopTime - startTime);
							break;
					
					
					case 3:
						break;
					
					default:
						printf("\n No no no \n");
						break;
						
				}
		}while(menu != 3);
	return 0;
}
