#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "lab2.h"


void scanFile(FILE *input)
{
	char words[20000][32];
	char tmp[32];
	int size = 0;
    
    if((input = fopen ("www.txt", "r")) == NULL)
	{
        printf("ERROR");
    }
   
    while (feof(input) == 0 )
    {
        fscanf (input, "%s", tmp);
        strcpy(words[size++], tmp);
    }
    fclose(input);
    FILE *output;
	bubble(words,size,output);
    selection(words,size,output); 
	insertion(words,size,output);
}


void bubble(char strings[][32] ,int size, FILE *output ){
	int i,j; char tmp[32]; char theResult[32];
	clock_t time;
	time = clock();
	for(i = 1; i < size; i++)
	{
        for(j = 0; j < size - i; j++)
		{
            if(strcmp(strings[j], strings[j + 1]) < 0)
			{
                strcpy(tmp, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], tmp);
            }
		}
	} 
			
	time = clock() - time;
	printf("bubble = %f \n", (double)time/CLOCKS_PER_SEC);    
	if((output = fopen ("bubble.txt", "w")) != NULL)
	{
		for(i = 0; i < size; i++)
		{
    	    fprintf(output,"%s \n", strings[i] );
        }
	}else { printf("ERROR");}
             
    fclose(output);  
       		
}



void selection(char strings[][32] ,int size, FILE *output ){
	
int out;
int in, i;	
int min_i;	
char tmp[32];
	clock_t time;
	time = clock();	
	for (out = 0; out < size - 1; out++) 
	{
    	min_i = out;
		for (in = out + 1; in < size; in++) {
			if ( strcmp(strings[in],strings[min_i])>0 )
			{
				min_i = in;
			}
		}
		strcpy(tmp,strings[out]);
		strcpy(strings[out],strings[min_i]);
		strcpy(strings[min_i], tmp);
	}
	time = clock() - time;
    printf("selection = %f \n", (double)time/CLOCKS_PER_SEC); 	
	
	if((output = fopen ("selection.txt", "w")) != NULL)
	{	
        for(i = 0; i < size; i++)
		{          	
   	    	fprintf(output,"%s \n", strings[i] );
       	}
	}else { printf("ERROR");}
             
    fclose(output);  
}



void insertion(char strings[][32] ,int size, FILE *output ){
	
	int out, j,i,in ;
    char tmp[32];
    clock_t time;
	time = clock();	
	for (out = 0; out < size; out++)
	{
		strcpy(tmp,strings[out]);
		in = out;
		while(in > 0 && strings[in-1] >= tmp)
		{
			strcpy(strings[in],strings[in-1]);
			--in;
		}
		strcpy(strings[in],tmp);
	}
	time = clock() - time;
    printf("insertion = %f \n", (double)time/CLOCKS_PER_SEC); 

	if((output = fopen ("insertion.txt", "w")) != NULL)
	{
		
        for(i = 0; i < size; i++)
		{    	
        	fprintf(output,"%s \n", strings[i] );
    	}
	}else { printf("ERROR");}
             
    fclose(output); 
}


