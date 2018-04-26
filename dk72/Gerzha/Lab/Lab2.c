#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void swap(char *symbArray, int first, int second)
{
	char buff;

	buff = symbArray[first];
	symbArray[first] = symbArray[second];
	symbArray[second] = buff;
}

void bubbleSort(char *symbArray, int size){
    int currPass = 1;
    int switch_flag;
    int pos;

    while (currPass < size){
		switch_flag = 0;
		pos = 0;        
		while (pos < size - currPass){
			if (symbArray[pos] > symbArray[pos + 1]){
				swap(symbArray, pos, pos + 1);
				switch_flag = 1;
			}
			pos++;
		}
		if (!switch_flag)
			break;
		currPass++;
	}
}

void insertionSort(char *symbArray, int size){
	int sortedPos = 0;
    int holePos;
    int holeValue;
    while(sortedPos < size - 1){
		holePos = sortedPos + 1;
		holeValue = symbArray[holePos];
		while (holePos > 0 && symbArray[holePos - 1] > holeValue)
		{
			symbArray[holePos] = symbArray[holePos -1];
			holePos--;
		}
		symbArray[holePos] = holeValue;
		sortedPos++;
	}
}

void selectionSort(char *symbArray, int size){
    int curPos = 0;
    int minPos = 0;
    int i;

    while (curPos < size)
	{
		i = curPos + 1;
		while (i < size)
		{
			if (symbArray[i] < symbArray[minPos])
				minPos = i;
			i++;
		}
		swap(symbArray, curPos, minPos);
		curPos++;
		minPos = curPos;
    }
}


void checkTime(char *symbArray, int size){
    clock_t begin;
    clock_t end;
    double time_spent;
    char *copy;

    copy = (char*)malloc(size);

    strncpy(copy, symbArray, size);    
    begin =  clock();
    bubbleSort(copy, size);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent for bubble sort = %lf\n", time_spent);

    strncpy(copy, symbArray, size);
    begin = clock();
    selectionSort(copy, size);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent for selection sort = %lf\n", time_spent);
    
    strncpy(copy, symbArray, size);
    begin = clock();
    insertionSort(copy, size);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent for insertion sort = %lf\n", time_spent);
    free(copy);
}

int readFile(FILE * inputFile, char ** symbArray){
    char buff[32];
    int arraySize = 32;
    int symbRead = 0;
    int allSymb = 0;;

    *symbArray = (char *)malloc(32);
    while((symbRead = fread(buff, sizeof(char), 32, inputFile))){
        if (allSymb + symbRead > arraySize){
            *symbArray = realloc(*symbArray, arraySize *2);
            arraySize = arraySize *2;
        }
        strncpy(*symbArray + allSymb, buff, 32);
        allSymb = allSymb + symbRead;
    }
    return(allSymb);
}

int main(void){
    char filename[256];
    FILE * inputFile = NULL;
    char * symbArray;
    int nbrOfSymb;

    printf("Enter full filename\n");
    scanf("%s", filename);
    inputFile = fopen(filename, "r");
    if (!inputFile){
        printf("Can't open file!\n");
        return(0);
    
    }
    nbrOfSymb = readFile(inputFile, &symbArray);
    checkTime(symbArray, nbrOfSymb);

    free(symbArray);
    fclose(inputFile);
    return(0);
}