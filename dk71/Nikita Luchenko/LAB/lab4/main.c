#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

int main()
{
	List *thelist = create_list();

	int check = 0;
	char letter;
	int i = 0;
	printf("\n\n\tAdd elements:\n\n");
			while(i < 8)
		 	{
			   printf("Add - ");
			   scanf("%s", &letter);
    		   add_element(thelist, letter);
		 	   i++;
			}
		print_list(thelist);	
	
		printf("\n MIN = %d\n\n", findMIN(thelist));
		printf("\n\n MAX = %d\n\n", findMAX(thelist));
			if(findMAX(thelist) < findMIN(thelist))
			 {
				quickSort(thelist, findMAX(thelist), findMIN(thelist)-1);
			 }
			else
		  	 {
				quickSort(thelist, findMIN(thelist), findMAX(thelist)-1);
			 }
				
		print_list(thelist);
		delete_list(thelist);
		return 0;
}
