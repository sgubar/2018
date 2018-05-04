#define _CRT_SECURE_NO_WARNINGS
#include "laba.h"

void swap(int *x, int *y) {
	int z;
	z = *x;
	*x = *y;
	*y = z;
}

int size_f()//function enter size array
{
	int size;
	do {
		printf("Enter a size of array(size ! =0, >0 & < 1000000): ");
		scanf("%d", &size);
	} while (size <= 0 || size > 1000000);
	return size;
}

void enter_array(int *en_array, int en_size) {
	srand(time(NULL));
	for (int i = 0; i < en_size; i++) {
		if (rand() % 2) {
			en_array[i] = rand() % 25 + 65;
		}
		else {
			en_array[i] = rand() % 25 + 97;
		}
		printf("%c ", en_array[i]);
	}
	printf("\n\n");
}


void write_to_file(int *wtf_arr, int wtf_size, char *name_tfile) {

	char *name_file = malloc(strlen(name_tfile) + 5);
	sprintf(name_file, "%s.txt", name_tfile);
	FILE *f = fopen(name_file, "w");
	for (int i = 0; i < wtf_size; i++) {
		fprintf(f, "%c", wtf_arr[i]);
	}
	fclose(f);
}


void read_file(char *rf_tname) {
	char *name_file = malloc(strlen(rf_tname) + 5);
	sprintf(name_file, "%s.txt", rf_tname);
	FILE *f = fopen(name_file, "r");
	char *n;
	while (!feof(f))
	{
		int res = fscanf(f, "%c", &n);
		if (res == EOF) break;
		printf("%c", n);
	}
	fclose(f);
}
void buble_sort(int *bub_arr, int bub_size) //function sortyvannia buble
{
	for (int i = 0; i < bub_size - 1; i++) {
		for (int j = 0; j < bub_size - 1; j++) {
			if (bub_arr[j] > bub_arr[j + 1]) {
				swap(&bub_arr[j], &bub_arr[j + 1]);
				//j++;
			}
		}
	}
}

void insertion_sort(int* is_arr, int is_size) //function sortyvannia vstavkoiy
{
	
		for (int i = 1; i < is_size; i++)
		{
			int j = i;
			while (j > 0 && is_arr[j - 1] > is_arr[j])
			{
				swap(&is_arr[j - 1], &is_arr[j]);
				j--;
			}

		}
		
}

void sort_chose(int* sc_arr, int sc_size) //function sortyvannia vuborom
{
		for (int i = 0; i < sc_size; i++) {
			int temp = sc_arr[0];
			for (int j = i + 1; j < sc_size; j++) {
				if (sc_arr[i] > sc_arr[j]) {
					temp = sc_arr[i];
					sc_arr[i] = sc_arr[j];
					sc_arr[j] = temp;
				}
			}
		}
}

/*void QuickSort(int *QS_arr, int first, int second) {
	int z, left, right;

	left = first;
	right = second;

	z = QS_arr[(left + right) / 2];
	while (left <= right) {
		while (QS_arr[left] < z)left++;
		while (QS_arr[right] > z)right--;

		if (left <= right)
		{
			swap(&QS_arr[left], &QS_arr[right]);
			left++;
			right--;
		}
	}
	if (first < right) QuickSort(QS_arr, first, right);
	if (left < second)QuickSort(QS_arr, left, second);
}*/
