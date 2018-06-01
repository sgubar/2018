#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tool.h"

int main()
{

    Tree *aTree = createTree();
    if(!aTree)
        exit(11);

    while(true) 
    {

        printf("\n \n"
                       "select an action for this, enter its number and press Enter.\n\n");
        printf("1)add element\n");
        printf("2) delete element.\n");
        printf("3) find element \n");
        printf("4) print.\n");
        printf("5) finish work.\n");
        printf("input: ");
        int X = checkInput();//create int and check for right input

        switch(X)
        {
            case 1:
            {
                addElement(aTree);
                break;
            }
            case 2:
            {
                if(aTree->root)//check ne raven li root NULL
                    deleteElementInTreeByValue(aTree);
                else
                    printf("\\n"
                                   "there are not enough elements for the operation\n");
                break;
            }
            case 3:
            {
                if(aTree->root)
                {
                    printf("enter the value of the item to search for: ");
                    int aValue = checkInput();
                    if(searchByValue(aTree->root, aValue))//if pointer ne raven NULL, element found
                        printf("element find.");
                    else
                        printf("element not found.");
                }
                else
                    printf("\nthere are not enough elements for the operation\n");
                break;
            }
            case 4:// print all that starts from nod atree root
                if(aTree->root)
                {
                    postorderPrint(aTree->root);
                    printf("\n");
                }
                else
                    printf("\nthere are not enough elements for the operation\n");
                break;
            }
            case 5:
            {
                goto pointer;
                break;
            }
            default:
            {
                printf("\nchoose one of variant.\n");
                break;
            }
        }
    }

    pointer:
    printf("\ndelete tree\n");
    printf("amount of elements\n\n");

    destroyTree(aTree);
    system("pause");
    return 0;
}
