#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "convert.h"


int convertation(char *h){
	int counter=0;
	int c=strlen(h); //counter
	int n[c];
	int j,i,k;
	int result=0;  
	while(counter<c){
		
		
		for(i='0';i<='9';i++){   
			if (h[counter]==i){
				n[counter]=i-'0';
			}
		}
		
	for(j='A';j<'G';j++){
			if (h[counter]==j){
				n[counter]=j-55;	
	}
	    }
	    counter++;
		
		
		}
		
	   for(k=0;k<=c-1;k++){
			result += n[k]*(pow(16,(c-1)-k));
		}
		
	  
	    return result;
		}
