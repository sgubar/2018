#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

int main()
{
	List *thelist = create_list();
	
	int check = 0;
	char letter;
	int index = 0;
	printf("\n\tAll operation:");
	printf("\n 1.---size");
	printf("\n 2.---print");
	printf("\n 3.---delete list");
	printf("\n 4.---add element");
	printf("\n 5.---delete element");
	printf("\n 6.---insert element");
	printf("\n 7.---sort element");
	printf("\n 8.---exit");
	
	
	while(1)
    {
    	
	    scanf("%d", &check);
	    
	     if(check == 1)
		{
			size_list(thelist);
		}
	    
		 if(check == 2)
		{
			 print_list(thelist);
		}
		
		 if(check == 3)
		{
			delete_list(thelist);
			printf("\n List was deleted");
		}
		
		 if(check == 4)
		{
			printf("\n Enter the letter:");
			scanf("%c", &letter);
            add_element(thelist, letter); 
		}
		
	  	 if(check == 5)
		{
			printf("\n Enter the letter :");
			scanf("%d", &index);
            delete_element(thelist, index); 
			
		}
		
		 if(check == 6)
		{
			printf("\n Enter the letter :");
			scanf("%c", &letter);
			printf("\n Enter the index :");
			scanf("%d", &index);			
            insert_element(thelist, index, letter);	
		}
		
		 if(check == 7)
		{
			qsort_list(thelist, 0, thelist->size - 1);
		}
		
		 if(check == 8)
		{
			return 0;
		}
		
	}
}


