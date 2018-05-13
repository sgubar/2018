#include <stdio.h>
#include <stdlib.h>
#include "dru_lib_sort.h"

int main(void)
{
	int size;
	printf("Enter the quantity of numbers in the array:");
	scanf("%d",&size);
	if(size<0) size=-size;
	int mass[size];
	
	//BubbleSort
	EnterMass(mass, size);
	PrintMass(mass, size);
	float TimeBubbleSort;
	TimeBubbleSort=ClockBubbleSort(mass, size);
	PrintMass(mass, size);
	printf("TimeBubbleSort=%.15f\n", TimeBubbleSort);
	WriteMass(mass, size, TimeBubbleSort, "Bubble_Sort.txt", "Bubble Sort");
	system("pause");
	
	//SelectionSort
	EnterMass(mass, size);
	PrintMass(mass, size);
	float TimeSelectionSort;
	TimeSelectionSort=ClockSelectionSort(&mass, size);
	PrintMass(mass, size);
	printf("TimeSelectionSort=%.15f\n", TimeSelectionSort);
	WriteMass(mass, size, TimeSelectionSort, "Selection_Sort.txt", "Selection Sort");
	system("pause");
	
	//InsertionSort
	EnterMass(mass, size);
	PrintMass(mass, size);
	float TimeInsertionSort;
	TimeInsertionSort=ClockInsertionSort(&mass, size);
	PrintMass(mass, size);
	printf("TimeInsertionSort=%.15f\n", TimeInsertionSort);
	WriteMass(mass, size, TimeInsertionSort, "Insertion_Sort.txt", "Insertion Sort");
	system("pause");
	
	return 0;
}
