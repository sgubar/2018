#include <stdio.h>
#include "spysok.h"
#include "menu.h"

int main(int argc, const char * argv[])
{

    int check;

    CharList *theList = SLCreateList();

	printf("Start!!!\n");
	do
    {
	    check = choose_check();

	    switch(check)
	    {
            case 1:

            find_Node(theList);
            system ("PAUSE");

            break;

            case 2:

            add_Node(theList);
            system ("PAUSE");

            break;

            case 3:

            delete_Node(theList);
            system ("PAUSE");

            break;

            case 4:

            insert_Node(theList);
            system ("PAUSE");

            break;

            case 5:

            Swap_Place(theList);
            system ("PAUSE");

            break;

            case 6:

            size_List(theList);
            system ("PAUSE");

            break;

            case 7:

            sort_List(theList);
            system ("PAUSE");

            break;

            case 8:

            print_List(theList);
            system ("PAUSE");

            break;

            case 9:

            delete_List(theList);

            break;

	    }
	}while((check) != 9);

	The_End();

	return 0;
}


