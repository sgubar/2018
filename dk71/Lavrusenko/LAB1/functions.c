#include <math.h>
#include <stdio.h>
#include <stdlib.h> 
#include "functions.h"




double plus(int a,int b,int c){
	int sumdiskriminant;
	
	sumdiskriminant = a*((sqrt(b+c))/b);
	return sumdiskriminant;
	
	
}

int sum(int a,int c){
	int d=0;
	int sum;
	int sumrow=0;

	while(d<=c){
		
		sum= a+d;
	
	sumrow = sumrow + factarial(sum);

	d++;
}
		
return sumrow;
	
}

int factarial(int sum){
	int factarial=1;
int i;
	for (i=1;i<=sum;i++){
		factarial = factarial*i;
	}	
	return factarial;
}


int convert(char *string){
	int value;
value = atoi(string);
	
	return value;	

}

