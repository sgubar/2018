#ifndef DK_TOOLS_H
#define DK_TOOLS_H

#include <stdio.h>
#include <time.h>

	void swap (int *element1Ptr, int *element2Ptr);
	void selectionSort(int values[], long n);
	void bubbleSort(int *,long);
	void swap (int*, int *);
	void insertionSort(int array[], long size);
	void Random(int * ,long );
	void printArrToFile(int array[], long size, char* name);
	long ValueCheck();

#endif
