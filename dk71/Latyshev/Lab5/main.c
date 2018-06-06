#include <stdio.h>

#include <conio.h>

#include "bin_tree.h"



int main() 

{	

    Tree *theTree = createTree();

    insertValueToTree(theTree,65);

    insertValueToTree(theTree,66);

    insertValueToTree(theTree,67);

    insertValueToTree(theTree,68);

    insertValueToTree(theTree,69);

    insertValueToTree(theTree,70);



    printf("Binary tree\n");

    printTree(theTree); 

    printf("\n");

    Node *SeachNode = findNodeWithValue(theTree,(char)66); 

    printf("\n");

    printf("Searched value =  %c \n", SeachNode ->value );

    printf("\n");

    deleteNodeWithElement(theTree, theTree -> root,(char)66);

    printf("Binary tree after deleted element");

    printf("\n");

    printTree(theTree);

    deleteTree(theTree);

    

    getch();

    return 0;

}
