#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{
	List *thelist = create_list();
	int choise = 0;
	char value;
	int index = 0;
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
	
	return 0;
}
