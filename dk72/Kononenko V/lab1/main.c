#include <stdio.h>
#include <stdlib.h>
#include "sort_lab2.h"

int main(void)
{
	int size;
	printf("Vedite dannye v massive:");
	scanf("%d",&size);
	if(size<0) size=-size;
	int mass[size];
	
	//Бульбашка
	EnterMass(mass, size);
	PrintMass(mass, size);
	float TimeBubbleSort;
	TimeBubbleSort=ClockBubbleSort(mass, size);
	PrintMass(mass, size);
	printf("TimeBubbleSort=%.15f\n", TimeBubbleSort);
	WriteMass(mass, size, TimeBubbleSort, "Bubble_Sort.txt", "Bubble Sort");
	system("pause");
	
	//Выборка
	EnterMass(mass, size);
	PrintMass(mass, size);
	float TimeSelectionSort;
	TimeSelectionSort=ClockSelectionSort(&mass, size);
	PrintMass(mass, size);
	printf("TimeSelectionSort=%.15f\n", TimeSelectionSort);
	WriteMass(mass, size, TimeSelectionSort, "Selection_Sort.txt", "Selection Sort");
	system("pause");
	
	//Вставка
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
