#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include "dk_tool.h"

int read(char mainfile[], char str []) {
	FILE *file = fopen("read.txt", "r+");
	if(file == NULL) {
    	printf("Not found\n");
    }

	int count = 0;
	while (!feof(file)) {
		char temp = fgetc(file);
	    if(((int)temp >= 65 && (int)temp <= 90) || ((int)temp>=97 && (int)temp <= 122)) {
	    	str[count] = temp;
	        count++;
	    }
	}
	fclose(file);
	return count;
}



void quickSort(char *str, int left, int right){
	
	int i,j;
	char x, y;
	
	i = left;
	j = right;
	x = str[(left + right)/2];
	
	do{
		while((str[i] < x) && (i < right))
		i++;
		while((str[j] > x) && (j > left))
		j--;
		if(i <= j) {
			y = str[i];
			str[i] = str[j];
			str[j] = y;
			i++;
			j--;
		}
	} while(i <= j);
	if(left < j)
	quickSort(str, left, j);
	if(i < right)
	quickSort(str, i, right);
}








int binarySearch(int a, int *str, int n) {
    int mid;
	int low = 0;
    int high = n - 1;
    
	while (low <= high) {
        mid = (low + high) / 2;
        if (a < str[mid])
            high = mid - 1;
        else if (a > str[mid])
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}
