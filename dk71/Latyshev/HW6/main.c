#include <stdio.h>

#include <stdlib.h>

#include "tools.h"



int main()

{

	List *thelist = create_list();

	

	int control = 0;

	char value;

	int index = 0;

	printf("\n\tAll operation:");

	printf("\n 1.---size\n 2.---print\n 3.---delete list\n 4.---add element\n 5.---delete element\n 6.---insert element\n 7.---sort element");

	printf("\n 8.---exit");

	

	

	while(1)

    {

	    scanf("%d", &control);

	     switch(control)

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

		printf("\n Enter the valur:");
		scanf("%c", &value);
        add_element(thelist, value);
		  break;

		

	  	 case 5:

		printf("\n Enter the value :");
		scanf("%d", &index);
         delete_element(thelist, index);
	     break;

		 case 6:

		printf("\n Enter the value :");
		scanf("%c", &value);
		printf("\n Enter the index :");
		scanf("%d", &index);			
        insert_element(thelist, index, value);
	    break;

		 case 7:
		
		qsort_list(thelist, 0, thelist->size - 1);
	    break;

		

		 case 8:

		return 0;

		}

		

	}

}
