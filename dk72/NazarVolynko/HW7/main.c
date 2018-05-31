#include <stdio.h>
#include "tree.h"
#include "menu.h"

int main()
{
    int check = 0;
    IntTree *aTree = create_IntTree();

    printf("START!!!");

    do
    {
    check = menu1 ();

    switch (check)
	{
	case 1 :
	    insert_Node(aTree);
    break;

	case 2 :
	    find_Node(aTree);
    break;

	case 3 :
	    delete_Node(aTree);
    break;

    case 4 :
	    print_Tree_(aTree);
    break;

    case 5 :
	    print_TreeGraphic(aTree);
    break;

    case 6 :
	    size_Tree(aTree);
    break;

    case 7 :
	    delete_Tree(aTree);
    break;
	}

    }while(check !=7);

	The_End();

    return 0;
}
