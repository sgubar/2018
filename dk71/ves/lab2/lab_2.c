#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab_2.h"


void enter(int *n) //function stvorennia randomnoho masuvy
{  
	FILE *f;
	do{
		printf("Vvedit' DODATNE znachennya masuvy n\n");
		scanf("%d", n);
	} while (*n<=0);
	char *array = (char*)malloc(sizeof(char)*(*n));
	int i;

	srand(time(NULL));
	printf("\n");
	printf("pochatkovuy masuv\n");
	for (i = 0; i < *n; i++)
	{
		if (rand() % 2) {
			array[i] = rand() % 25 + 65;
		}
		else {
			array[i] = rand() % 25 + 97;
		}
		printf("%c ", array[i]);
	}
	printf("\n");
	f = fopen("sort.txt", "w");
	for (i = 0; i < *n; i++) {
		fprintf(f, "%c", array[i]);
	}
	fclose(f);
	free(array);
}



void swap(char *x, char *y) //function obmin zminnuh
{
	char z;
	z = *x;
	*x = *y;
	*y = z;
}



void buble_sort(int n) //function sortyvannia buble
{
	int start_t, end_t;
	char *arr = (char*)malloc(sizeof(char)*n);
	FILE *f, *f2;
	f = fopen("sort.txt", "r");
	if (f == NULL) {
		printf("ERROR\n");
	}
	else {
		for (int i = 0; i < n; i++) {
			fscanf(f, "%c", &arr[i]);
		}
		printf("\n");
		start_t = clock();
		//begin sort
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(&arr[j], &arr[j + 1]);
				}
			}
		}
		//end sort
		end_t = clock();
		printf("time buble_sort: %d\n", end_t - start_t);		/**/
	}
	fclose(f);
	f2 = fopen("sort.txt", "a");
	if (f2 == NULL)
	{
		printf("ERROR buble_sort\n");
	}
	else {
		fprintf(f2, "\nsort_buble:\n\t");
		printf("sortuvannia buble:\n");
		//vvuvodut' na ekran
		for (int i = 0; i < n; i++) {
			fprintf(f2, "%c", arr[i]);
			printf("%c", arr[i]);
		}
		printf("\n");
	}
	fclose(f2);
	free(arr);
}

void insertion_sort(int n) //function sortyvannia vstavkoiy
{
	int start_t, end_t;
	char *arr = (char*)malloc(sizeof(char)*n);
	FILE *f, *f3;
	f = fopen("sort.txt", "r");
	if (f == NULL) {
		printf("ERROR\n");
	}
	else {
		for (int i = 0; i < n; i++) {
			fscanf(f, "%c", &arr[i]);
		}
		printf("\n");
		start_t = clock();
		//begin sort
		for(int i =1; i<n; i++)
		{
			int j = i;
			while (arr[j] < arr[j - 1])
			{
				swap(&arr[j], &arr[j - 1]);
				j--;
			}
		}
		//end sort
		end_t = clock();
		printf("time insertion_sort: %d\n", end_t - start_t);	
	}
	fclose(f);
	f3 = fopen("sort.txt", "a");
	if (f3 == NULL)
	{
		printf("ERROR insertion_sort\n");
	}
	else {
		fprintf(f3, "\nsort_vstavkoiu:\n\t");
		printf("sortuvannia insertion:\n");
		//vvuvodut' na ekran
		for (int i = 0; i < n; i++) {
			fprintf(f3, "%c", arr[i]);
			printf("%c", arr[i]);
		}
		printf("\n");
	}
	fclose(f3);
	free(arr);
}

void sort_chose(int n) //function sortyvannia vuborom
{
	int start_t, end_t;
	char *arr = (char*)malloc(sizeof(char)*n);
	FILE *f, *f4;
	f = fopen("sort.txt", "r");
	if (f == NULL) {
		printf("ERROR\n");
	}
	else {
		for (int i = 0; i < n; i++) {
			fscanf(f, "%c", &arr[i]);
		}
		printf("\n");
		start_t = clock();
		////begin sort
		for (int i = 0; i < n; i++) {
			int temp = arr[0];
			for (int j = i + 1; j < n; j++) {
				if (arr[i] > arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
		//end sort
		end_t = clock();
		printf("time sort_chose: %d\n", end_t - start_t);		
	}
	fclose(f);
	f4 = fopen("sort.txt", "a");
	if (f4 == NULL)
	{
		printf("ERROR insertion_sort\n");
	}
	else {
		fprintf(f4, "\nsort_vuborom:\n\t");
		printf("sortuvannia chose:\n");
		//vvuvodut' na ekran
		for (int i = 0; i < n; i++) {
			fprintf(f4, "%c", arr[i]);
			printf("%c", arr[i]);
		}
		printf("\n\n");
	}
	fclose(f4);
	free(arr);
}