#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "sort.h"



void scan_file(FILE *input){
	int i;
	 char words[4020][32]; char buffer[32];
	int count = 0;
    
    if((input = fopen ("input.txt", "r")) == NULL){
        printf("ERROR");
           }
   
    while (feof(input) == 0 )
    {
        fscanf (input, "%s", buffer);
        strcpy(words[count++], buffer);
            }
    fclose(input);
    FILE *output;
	sort_bubble(words,count,output);
       sort_choice(words,count,output); 
		sort_pass(words,count,output);
}
//  считать буфер отправить на сортировку 

void sort_bubble(char strings[][32] ,int count, FILE *output ){
	int i,j; char buffer[32]; char theResult[32];
	clock_t time;
	time = clock();
	 for(i = 1; i < count; i++){
        for(j = 0; j < count - i; j++){
            if(strcmp(strings[j], strings[j+1]) < 0){
                strcpy(buffer, strings[j]);
                strcpy(strings[j], strings[j+1]);
                strcpy(strings[j+1], buffer);
            }}} 
			
			time = clock() - time;
            printf("%f \n", (double)time/CLOCKS_PER_SEC);       
                  if((output = fopen ("bubble.txt", "a")) != NULL){
		
        for(i=0;i<count;i++){
            	
        	        fprintf(output,"%s \n", strings[i] );
        	
    }}
        else { printf("ERROR");
		}
             
        fclose(output);  
       		
}



void sort_choice (char strings[][32] ,int count, FILE *output ){
	
int i;
int j;	
int min_i;	
char buffer[32];
	clock_t time;
	time = clock();	
	for (i = 0; i < count - 1; i++) {
         min_i = i;
	for (j = i + 1; j < count; j++) {
		if ( strcmp(strings[j],strings[min_i])>0 ){
			min_i = j;
		}
	}

strcpy(buffer,strings[i]);
strcpy(strings[i],strings[min_i]);
	strcpy(strings[min_i], buffer);
}
	time = clock() - time;
            printf("%f \n", (double)time/CLOCKS_PER_SEC); 	
	
	if((output = fopen ("choice.txt", "a")) != NULL){
		
        for(i=0;i<count;i++){
            	
        	        fprintf(output,"%s \n", strings[i] );
        	
    }}
        else { printf("ERROR");
		}
             
        fclose(output);  
	
	
	
}


void sort_pass(char strings[][32] ,int count, FILE *output ){
	
	int pass, j,i ;
    char buffer[32];
    clock_t time;
	time = clock();	
	for (pass = 0; pass < count-1; pass++){
		for (j = pass+1; j < count; j++){
			if (strcmp(strings[pass],strings[j])>0){
				strcpy(buffer,strings[j]);
				strcpy(strings[j],strings[pass]);
				strcpy(strings[pass],buffer);
			
			}
		}
	}
	time = clock() - time;
            printf("%f \n", (double)time/CLOCKS_PER_SEC); 

	if((output = fopen ("pass.txt", "a")) != NULL){
		
        for(i=0;i<count;i++){
            	
        	        fprintf(output,"%s \n", strings[i] );
        	
    }}
        else { printf("ERROR");
		}
             
        fclose(output); 
		 }
