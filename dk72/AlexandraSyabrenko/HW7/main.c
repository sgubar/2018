#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

int main()
{
    Tree *test = createTree();
    
    insertFloatValueToTree(test, 56.34);
    insertFloatValueToTree(test, 673.4);
    insertFloatValueToTree(test, 5.09);
    insertFloatValueToTree(test, 342.7);
    insertFloatValueToTree(test, 4.895);
    insertFloatValueToTree(test, 25.89);
    insertFloatValueToTree(test, 165.9);
    insertFloatValueToTree(test, 11.67);
    
    printTree(test->root);
    printf("\n");
    
    printf("Searched node : %.3f\n", searchNodeWithValue(test, 342.7)->value);
    
    deleteValueFromTree(test, 4.895);
    deleteValueFromTree(test, 5.09);
    deleteValueFromTree(test, 673.4);
    
    printTree(test->root);
    printf("\n");
    
    deleteTree(test);
    return 0;
}
