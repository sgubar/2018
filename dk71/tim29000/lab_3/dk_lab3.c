#include <stdio.h>
#include <stdlib.h>
#include "dk_lab3.h"

void ShellSort(char *mass, int Count)
{
	int theInner = 0;
	int theOuter = 0;
	int chleH = 1;
	while (chleH <= Count/3)
	{
		chleH = chleH*3 + 1;
	}
     while (chleH > 0)
	{
		for (theOuter = chleH; theOuter < Count; theOuter ++)
		{
			int temp = mass[theOuter];
			theInner = theOuter;
			while (theInner > chleH-1 && mass[theInner - chleH] >= temp)
			{
				mass[theInner] = mass[theInner - chleH];
				theInner -= chleH;
			}
			mass[theInner] = temp;
		}
		chleH = (chleH - 1) / 3;
	}
}

void WritetoFile(char *mass, int asize, char *fname)
{
	FILE *file;
	file= fopen(fname, "w");

	int i;
	for(i = 0; i < asize; i++)
	{
	    fprintf(file, "%c", mass[i]);
	}
	fclose(file);
}

int biSearch(char Value, char *mass, int asize)
{
    int left = 0;
    int right = asize-1;
    int central;

    while (left <= right)
    {
        central = (left+right)/2;
        if(Value == mass[central])
        {
            return central;
        }
        else if(Value < mass[central])
        {
            right = central-1;
        }
        else if(Value > mass[central])
        {
            left = central + 1;
        }
    }
    return -1;
}

void randomizer(char *mass, int size)

{
    srand(time(NULL));
    int a, i;

    for(i = 0; i < size; i++)
    {
        a = rand() % 5;
        if(a == 1)
        {
            mass[i] = rand() % 5 + 91;
        }
        else
        {
            mass[i] = rand() % 31 + 33;
        }
    }
}
