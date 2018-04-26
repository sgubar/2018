#include <stdlib.h>

#include "DKsort.h"




void swap (int *ELx, int *ELy)

{
    int temp = *ELx;
    
    *ELx = *ELy;
    
    *ELy = temp;
}



void Rec_To_File(int *array, int size, char* name)
 {

    int i;

    FILE *file = fopen(name, "w");

    for ( i = 0; i < size; i++)

    {

        fprintf(file, "%c ", array[i]);

    }

    fclose(file);

}




void quick_sort(int *array, int first, int last)

{

	int middle, left, right;

	

  left = first;

  right = last;

  

  middle = array[(left + right) / 2];

  while (left <= right)

  {

    while (array[left] < middle) left++;

      

    while (array[right] > middle) right--;

      

    if (left <= right)

	{

        swap(&array[left], &array[right]);

        left++;

        right--;

	}

  }

  if (first < right) quick_sort(array, first, right);

  if (left < last) quick_sort(array, left, last);

}




int binary_search(int *array, int size, int el)

{

	int min = 0, max = size, aver;

	

	if(max%2 == 0) aver = max/2;

		else aver = max/2 + 1;

	



	if(array[max] == el || array[min] == el || array[aver] == el) return 1;

	

	while(max - min != 1)

	{

		

		if(array[max] == el || array[min] == el || array[aver] == el) return 1;

		

		if(array[aver] >= el) max = aver; 

		if(array[aver] < el) min = aver; 

		

		if((max+min)%2 == 0) aver = (max+min)/2 ;

		else aver = (max+min)/2 +1;

		

		if(array[aver] == el) return 1;

	}

	

	if(array[aver] == el) 

		return 1;

	else

		return 0;

}




void random_letter(int *array, int size)


{

    srand(time(NULL));

    int isLower;

    int i;

    for( i = 0; i < size; i++)

    {

        isLower = rand() % 2;

        if(isLower == 1)

        {

            array[i] = rand() % 25 + 65;

        }

        else

        {

            array[i] = rand() % 25 + 97;

        }


    }


}
