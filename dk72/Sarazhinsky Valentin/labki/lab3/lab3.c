#include "lab3.h"

void shellSort(char *anArray, int aCount)
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; 

	while (theH <= aCount/3)
	{
		theH = theH*3 + 1; // 1, 4, 13, 40, 121, ....
	}


	while (theH > 0)
	{
		for (theOuter = theH; theOuter < aCount; theOuter ++)
		{
			int theTmp = anArray[theOuter];
			theInner = theOuter;

			while (theInner > theH-1 && anArray[theInner - theH] <= theTmp)
			{
				anArray[theInner] = anArray[theInner - theH];
				theInner -= theH;
			}

			anArray[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; 
	}
}



int binary_search(char *array, char search_value, int size)
{
	int first_index = 0, last_index = size, average_index;
	
	if(last_index%2 == 0) average_index = last_index/2;
		else average_index = last_index/2 + 1;
	

	if(array[last_index] == search_value || array[first_index] == search_value || array[average_index] == search_value) return 1;
	
	while(last_index - first_index != 1)
	{
		
		if(array[last_index] == search_value || array[first_index] == search_value || array[average_index] == search_value) return 1;
		
		if(array[average_index] >= search_value) last_index = average_index; 
		if(array[average_index] < search_value) first_index = average_index; 
		
		if((last_index+first_index)%2 == 0) average_index = (last_index+first_index)/2 ;
		else average_index = (last_index+first_index)/2 +1;
		
		if(array[average_index] == search_value) return average_index;
	}
	
	if(array[average_index] == search_value) 
		return average_index;
	else
		return 0;
}


