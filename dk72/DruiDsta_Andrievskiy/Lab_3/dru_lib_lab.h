#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void EnterMass(int *mass, int size);
void PrintMass(int *mass, int size);
int linearSearch(int *mass, int size);
void TMP(int *A1, int *A2);
void shellSort(int *anArray, int aCount);
float ClockShellSort(int *anArray, int aSize);
int partitionIt(int *anArray, int aLeftIndex, int aRightIndex, int aPivot);
void quickSort(int *anArray, int aLeftIndex, int aRightIndex);
float ClockQuickSort(int *anArray, int aSize);
void WriteTXT(float DR, char *name, char *text);
