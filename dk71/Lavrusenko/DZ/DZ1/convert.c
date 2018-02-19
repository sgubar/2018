#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "convert.h"


int convertation(char *h){
	int c=0; //counter
	int n[3]; // numbers in (10)
	int buffer[2];   // value need for canculate result
	while(c<4){
		
		int i;
		for(i=48;i<58;i++){   
			if (h[c]==i){
				n[c]=i-48;
			}
		}
		int j;
	for(j=65;j<71;j++){
			if (h[c]==j){
				n[c]=j-55;	
	}
	    }
	    c++;}
	   
	    buffer[0] = (n[0]*16)+n[1]; // this awful block need for convertation 
	    buffer[1]= (buffer[0]*16)+n[2];
	    buffer[2] =(buffer[1]*16)+n[3];
	    return buffer[2];}
