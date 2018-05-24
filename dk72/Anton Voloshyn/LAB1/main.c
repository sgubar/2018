#include "dk_sort.h"

int main(int argc, const char * argv[])
{
	float TimeStart,TimeStop;
	int size=0,number=0;
	char symvol;
	char * sorting_shell = loadFile("lab3.txt" , &size);
	
	
	
	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	shellSort(sorting_shell, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;
	printf("\nTime of Quick sorting: %.10f sec!\n", TimeStop-TimeStart);
	printf("\nEnter searching symbol: ");
	scanf("%c",&symvol);
	
	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	number = binary_find(sorting_shell, symvol, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;
	
	if(number==-1)
		{
		    printf("\nCan't find it!\n");
		}
	else
		{
		    printf("\nFounded at number: %d \n", number);
		}
	
	printf("\nTime of Binary find: %.10f sec!\n", TimeStop-TimeStart);
	inFile(sorting_shell, size, "shell.txt");
	printf("\nCheck lab3.txt:)\n");
	
	free(sorting_shell);
	
	return 0;
}
