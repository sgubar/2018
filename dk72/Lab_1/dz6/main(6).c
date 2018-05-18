#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
	List *thelist = create_list();
	int choise = 0;
	char value;
	int index = 0;
	//printf("\n 1.size\n 2.print\n 3.delete list\n 4.add element\n 5.delete element\n 6.insert element\n 7.sort element\n");
	size_list(thelist);
	//Add element to list
	printf("\n Enter the valuå:");
	scanf("%c", &value);
    add_element(thelist, value);
    printf("Element was added:");
	//Insert
	printf("\n\nInsertion: ");
	printf("\n value : \n");
	scanf("%c", &value);
	printf("\n index :");
	scanf("%d", &index);			
    insert_element(thelist, index, value);
    //Sorting
    qsort_list(thelist, 0, thelist->size - 1);
    //Delete list
	delete_list(thelist);
	printf("\n List was deleted");
    
	




	/*
	while(1)
    {
	    scanf("%d", &choise);
	    switch(choise)
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
			printf("\n Enter the valuå:");
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
		}
	}
	*/
	
	return 0;
}
