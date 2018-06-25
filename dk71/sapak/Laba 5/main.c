#include <stdlib.h>
#include "Tree.h"
#include <string.h>






int main()
{ double a = 1.1;
	double b = 2.1;
	double c= 3.1;
	double d = 4.1;
	double e = 5.1;

Node *root = NULL;


    

    insert(&root,a);

    insert(&root, e);

    insert(&root, c);

    insert(&root, d);

    insert(&root, b);
inOrderTravers(root);)

    getch();
}
