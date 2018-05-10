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
	    
	     switch(check)
		{
		 case 1:
			size_list(thelist);
			     break;
	    
		 case 2:
		
			 print_list(thelist);
			     break;
		
		 case 3: 
		
			delete_list(thelist);
			printf("\n List was deleted");
			     break;
		
		 case 4:
		
			printf("\n Enter the letter:");
			scanf("%c", &letter);
            add_element(thelist, letter);
			     break;
		
	  	 case 5:
		
			printf("\n Enter the letter :");
			scanf("%d", &index);
            delete_element(thelist, index);
			     break;
		
		
		 case 6:
		
			printf("\n Enter the letter :");
			scanf("%c", &letter);
			printf("\n Enter the index :");
			scanf("%d", &index);			
            insert_element(thelist, index, letter);
			     break;
		
		 case 7:
		
			qsort_list(thelist, 0, thelist->size - 1);
			     break;
		
		 case 8:
		
			return 0;
		}
		
	}
}


