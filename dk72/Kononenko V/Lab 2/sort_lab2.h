#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void EnterMass(int *mass, int size);
void PrintMass(int *mass, int size);
void TMP(int *A1, int *A2);
void bubbleSort(int *anArray, int aSize);
void selectionSort(int *anArray, int aSize);
void insertionSort(int *anArray, int aSize);
float ClockBubbleSort(int *anArray, int aSize);
float ClockSelectionSort(int *anArray, int aSize);
float ClockInsertionSort(int *anArray, int aSize);
void WriteMass(int *mass, int size, float time, char *name, char *sort);
