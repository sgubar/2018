#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) 
{
	int h,a,b,c,r1,r2,ad,ed,summ,f;
	float r;	
	h=0;
do	
	{
	
		printf("\nEnter integer A - ");    
		scanf("%d",&a);
		printf("Enter integer B<0 - ");                                                                       //interview
		scanf("%d",&b);
		do
			{
				if (b<=0)
				{
					printf("ERROR! B must be higher then 0 - ");      //protection from a numbnuts
					scanf("%d",&b);	
				}
				
			}
		while (b<=0);
		printf("Enter integer C - ");
		scanf("%d",&c);	

	
	
	
		r=(a*b);
		r1=(c*c+b);                    //left side of example
		r=r/r1;

	
	

		summ=0;
	
		for (ad=0; ad<=b; ad++)        //summation of a series of numbers
		{
			f=1;
			for (ed=1;ed<ad;ed++)      //factorial
			{
				f=f*(ed+1);		
			}                                                      //right side of example
			
		
			
			summ=(summ+f);		
		}
		
	
		printf("\nResult = %.2f",summ+r);                //answer with summamtion of left and right side 
	
	
	

	}
while (h!=1);	                                 //to continue the program forever


	return 0;
}
