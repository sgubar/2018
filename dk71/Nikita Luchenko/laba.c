#include "laba.h"

int sum(int B)
{
	int sum;
	int D=0;
	int fullsum=0;
      for(D;D<=B;D++)
	  {
	  	sum=0+D;
	
		fullsum = fullsum + factorial(sum);
	  }
		
return fullsum;
	
}

int factorial(int sum)
{
		int factorial=1;
		int i;
			for (i=1;i<=sum;i++)
			{
				factorial = factorial*i;
			}	
	return factorial;
}


int power(int n)
{
    return n*n;
}

