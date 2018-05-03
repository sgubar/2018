#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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




void bubbleSort(char str[], int count) {
	int i;
    for(i = 0 ; i < count - 1; i++) {
		int j;
    	for(j = 0 ; j < count - i - 1 ; j++) {
        	if((int)str[j] > (int)str[j+1]) {
            	char tmp = str[j];
            	str[j] = str[j+1] ;
            	str[j+1] = tmp;
           }
        }
    }
}




void selectionSort( char str[],int count) {
	int i;
	for (i = 0; i < count ; i++) {
    	int min = i;
        int j;
        for (j = i + 1; j < count ; j++)
			if ((int)str[min] > (int)str[j])
                min = j;
        char tmp = str[min];
        str[min] = str[i];
        str[i] = tmp;
    }
}





void insertionSort( char str[],int count) {
	int i;
    for (i = 1; i < count; i++) {
        int newEl, loc;
        newEl = (int)str[i];
        loc = i - 1;
        while(loc >= 0 && str[loc] > newEl) {
        	str[loc + 1] = str[loc];
            loc = loc - 1;
        }
        str[loc + 1] = newEl;
    }
}
