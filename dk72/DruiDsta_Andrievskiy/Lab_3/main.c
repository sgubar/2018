#include <stdio.h>
#include <stdlib.h>
#include "dru_lib_lab.h"

int main(void) 
{
	int size;
	printf("Enter the quantity of numbers in the array:");
	scanf("%d",&size);
	if(size<0) size=-size;
	int mass[size];
	
	//ShellSort
	EnterMass(mass, size);
	PrintMass(mass, size);
	float TimeShellSort=ClockShellSort(mass, size);
	PrintMass(mass, size);
	WriteTXT(TimeShellSort, "ShellSort.txt", "Time:");
	
	//QuickSort
	EnterMass(mass, size);
	PrintMass(mass, size);
	float TimeQuickSort=ClockQuickSort(mass, size);
	PrintMass(mass, size);
	WriteTXT(TimeQuickSort, "QuickSort.txt", "Time:");
	
	//Search
	float result=linearSearch(mass, size);
	free(mass);
	
	return 0;
}
