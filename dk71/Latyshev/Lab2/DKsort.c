#include <stdlib.h>

#include "DKsort.h"



void swap (int *ELx, int *ELy)

{

    int temp = *ELx;

    *ELx = *ELy;

    *ELy = temp;

}

void Rec_To_File(int *array, int size, char* name) {

    int i;

    FILE *file = fopen(name, "w");

    for ( i = 0; i < size; i++)

    {

        fprintf(file, "%c ", array[i]);

    }

    fclose(file);



}


void S_Sort(int *array, int size)

{

 int i;

    for ( i = 0; i < size; i++) {

        int trp = i;
         int j;
        for ( j = i+1; j < size; j++)

        {

            if (array[j] < array[trp])

                trp = j;

        }

        swap(&array[trp], &array[i]);

    }


}




void three_type_sort( int *array, int size, int selection)
{

  scanf("%d", &selection);

 while(selection != 1 && selection != 2 && selection != 3)

    {
	

        printf("Invalid value. Enter again: ");

        scanf("%d", &selection);
        
    }
      switch(selection)
    {

        case 1:

            B_Sort(array, size);

            Rec_To_File(array, size, "sorted.txt");

            break;

        case 2:

            S_Sort(array, size);

            Rec_To_File(array, size, "sorted.txt");

            break;

        case 3:

            I_Sort(array, size);

            Rec_To_File(array, size, "sorted.txt");

            break;



    }

}







void B_Sort(int *array, int size)

{



    int i, j;



    for (i = 1; i <= size - 1; i++)

    {

        for (j = 0; j <= size - 2; j++) {

            if (array[j] > array[j + 1])

            {

                swap(&array[j], &array[j + 1]);

            }

        }

    }



}



void I_Sort(int *array, int size)

{


    int i;

    for ( i = 1; i <= size - 1; i++)

    {

        int x = array[i];

        int j = i;
 
        while (j > 0 && array[j - 1] > x)

        {

            array[j] = array[j - 1];

            j--;

        }

        array[j] = x;

    }


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
