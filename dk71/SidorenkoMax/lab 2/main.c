#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
#define N 10000

int main(int argc, char *argv[]) {
	int mass[N];
	int sortresult[N];
	int choose, a, start_t, end_t;
	memcpy(mass, random(), sizeof(mass));
/*	for(a=0;a<N;a++)
		{
			printf("%d ", mass[a]);
		} 			*/
	printf("\n\n");
	do
		{
			printf("Choose Sorting Algorithm:\n 1) Bubble Sort\n 2) Insertion Sort\n 3) Selection Sort\n");
			scanf("%d", &choose);
			start_t = clock();
			if(choose == 1)
				{
					memcpy(sortresult, bubblesort(mass), sizeof(sortresult));
					for(a=0;a<N;a++)
						{
							printf("%d  ", sortresult[a]);
							if(a%10 == 0)
								{
									printf("\n");
								}
						}
				}
			if(choose == 2)
				{
					memcpy(sortresult, insertionsSort(mass), sizeof(sortresult));
					for(a=0;a<N;a++)
					{
						printf("%d  ", sortresult[a]);
						if(a%10 == 0)
							{
								printf("\n");
							}
					}
					
				}
			if(choose == 3)
				{
					memcpy(sortresult, selecrionsort(mass), sizeof(sortresult));
					for(a=0;a<N;a++)
						{
							printf("%d  ", sortresult[a]);
							if(a%10 == 0)
								{
									printf("\n");
								}
						}
				}
		}while(choose<1 || choose>3);
	printf("\n");
	end_t = clock();
	printf("Sort time: %d\n", end_t - start_t);
	return 0;
}
