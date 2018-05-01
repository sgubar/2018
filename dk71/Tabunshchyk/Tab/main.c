#include <stdio.h>
#include <stdlib.h>
#define n 10000



int main() 
{
	int mass[n];
	int a,i;
	char symbol[n];
	

for (a = 0; a < n; a++)
{
		
	i = rand() % 2 + 1;
	if (i == 1)
	{
			mass[a] = rand() % 26 + 65; 
		}
	
		if (i == 2)
		{
			mass[a] = rand() % 26 + 97; 
		}
	} 			

		for (a = 0; a < n; a++)   
	{

	symbol[a] = mass[a];
	printf ("%d = %c   ", mass[a], symbol[a]);	
	
	}   
		
		
		
	
		

	return 0;
}
