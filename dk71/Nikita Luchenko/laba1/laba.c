#include "laba.h"

int sum(int B)
{
  int d=0;
  int sumrow=0;
  int factorial=1;
  		while(d<=B)
		  {
   		   factorial=1;
 		   int i;
 			for (i = 1;i <= B;B--)
  		 	  	 {
				     factorial = factorial * B;
 				 }
 			 sumrow = sumrow+factorial;
 			 d++;
	       }
    
return sumrow;

}

int power(int n)
{
    return n*n;
}

