#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "lab3.h"

void scanFile(FILE *input)
{
	int n = 20000;
	char words[n][32];
	char tmp[32];
	int size = 0;
    
    if((input = fopen ("www.txt", "r")) == NULL)
	{
        printf("ERROR");
    }
   
    while (feof(input) == 0  )
    {
        fscanf (input, "%s", tmp);
        strcpy(words[size++], tmp);
    }
    fclose(input);
    FILE *output;
    shellSort(words,size,output);
}

void shellSort(char strings[][32] ,int size, FILE *output )
{
	int i;
	int in = 0;
	int out = 0;
	int h = 1; // start h = 1
	char tmp[32];
	
	//1. Calculate start value of h
	while (h <= size/3)
	{
		h = h*3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (h > 0)
	{
		for (out = h; out < size; out ++)
		{
			strcpy(tmp, strings[out] );
			in = out;
		
			// the first sub-array {0, 4, 8}
			while (in > h-1 && strcmp(strings[in - h], tmp) < 0)
			{
				strcpy(strings[in], strings[in - h]);
				in -= h;
			}
		
			strcpy(strings[in], tmp);
		}
	
		h = (h - 1) / 3; //decrease h
	}

	
	
	if((output = fopen ("shell1.txt", "w")) != NULL)
	{
		for(i = 0; i < size; i++)
		{
    	    fprintf(output,"%s \n", strings[i] );
        }
	}else { printf("ERROR");}
             
    fclose(output);  
}
