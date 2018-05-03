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

void QuickSort(int *QS_arr, int first, int second) {
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
	if (first < right) QuickSort (QS_arr, first, right);
	if (left < second)QuickSort(QS_arr, left, second);
}

int bin_search(int *bn_arr, int bn_size, int bn_el)
{
	int bn_min = 0, bn_max = bn_size, bn_ser;

	if (bn_max % 2 == 0) bn_ser = bn_max / 2;
	else bn_ser = bn_max / 2 + 1;


	if (bn_arr[bn_max] == bn_el || bn_arr[bn_min] == bn_el || bn_arr[bn_ser] == bn_el) return 1;

	while (bn_max - bn_min != 1)
	{

		if (bn_arr[bn_max] == bn_el || bn_arr[bn_min] == bn_el || bn_arr[bn_ser] == bn_el) return 1;

		if (bn_arr[bn_ser] >= bn_el) bn_max = bn_ser;
		if (bn_arr[bn_ser] < bn_el) bn_min = bn_ser;

		if ((bn_max + bn_min) % 2 == 0) bn_ser = (bn_max + bn_min) / 2;
		else bn_ser = (bn_max + bn_min) / 2 + 1;

		if (bn_arr[bn_ser] == bn_el) return 1;
	}

	if (bn_arr[bn_ser] == bn_el)
		return 1;
	else
		return 0;
}