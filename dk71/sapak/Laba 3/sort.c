#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "sort.h"



char *scan_file(FILE *input,  char **p){
	int i;
	char **words;
	char buffer[32];
 words = (char**) malloc(5000*sizeof(char*));
 for (i=0;i<5000;i++){
	words[i] = (char*) malloc(32);
}

	int count = 1;
   
   
    if((input = fopen ("input.txt", "r")) == NULL){
        printf("ERROR");
           }
  
    while (feof(input) == 0 )
    {
        fscanf (input, "%s", buffer);
        
        strcpy(words[count++], buffer);
        
            }
            itoa(count,words[0],10);
           
            for (i=0;i<count;i++){
			memcpy(p[i],words[i],sizeof(words[i]));
}
     
          
    fclose(input);
  
       return p; }
  


		 


void binary_find(char **n,char serch[32],FILE *output)  
{
	
    int count = atoi(n[0]);
	int i, left, right, result;
left = 0; right = count-1;

while (1)
 {
    if (left > right) { break;   }
    i = left + (right - left) / 2;
    if (strcmp(n[i],serch) <0) {left = i + 1;  }
    if (strcmp(n[i],serch) > 0) {right = i - 1;} 
    if (strcmp(n[i],serch) == 0) {
    
	result=i;
	break;
 }}
 
  if((output = fopen ("mass.txt", "a")) != NULL){
		
        for(i=2;i<count;i++){
            	if(i==result){
        	        fprintf(output," ______\"%s\" ____  \n", n[i] );}
        	        else {fprintf(output,"%s\n", n[i] );
        }
    }}
        else { printf("ERROR");
		}
             
        fclose(output); 
 
 
}


//  считать буфер отправить на сортировку 



char *quick_sort(char **array,  char **n )
{
int mid, left, right,first,last,count,i; char buffer[32];
count = atoi(array[0]);
	clock_t time;
	time = clock();
	first = 0;
  left = first;
  last = atoi(array[0])-1;
  right = last;
  
  mid = array[(left + right) / 2];
  while (left <= right)
  {
    while (array[left] < mid) left++;
      
    while (array[right] > mid) right--;
      
    if (left <= right)
	{ strcpy(buffer,array[left]);
		strcpy(array[left],array[right]);
		strcpy(array[right],buffer);
	
      
        left++;
        right--;
	}
  }
  if (first < right){
  quick_sort(array,n);}
    
  if (left < last) {
  quick_sort(array,n);}
   time = clock() - time;
            printf("%f \n", (double)time/CLOCKS_PER_SEC);    
			 FILE *output;
            if((output = fopen ("qsort.txt", "a")) != NULL){
		
        for(i=0;i<count;i++){
            	
        	        fprintf(output,"%s \n", array[i] );
        	
    }}
        else { printf("ERROR");
		}
             
        fclose(output);  
        
        for (i=0;i<count;i++){
			memcpy(n[i],array[i],sizeof(array[i]));}
      		
    return n ;      
            
}






