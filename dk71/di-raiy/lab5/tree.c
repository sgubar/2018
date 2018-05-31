#include "tree.h"

Node* createTree (double ins)
{
   Node* tmp = (Node*) malloc(sizeof(Node));
   tmp->left = tmp->right = NULL;
   tmp->data = ins;
   tmp->parent = NULL;
   return tmp;
}

void insElem (Node *first, double IE)
{
    if(first->left!= NULL && first->right != NULL)
    {
       int a = steps(first->left, 0);
       int b = steps(first->right, 0);
       if(a<=b)
        insElem(first->left, IE);
       else
        insElem(first->right, IE);
    }
     else if(first->left == NULL)
    {
        Node* tmp = createNode(IE);
        tmp->parent = first;
        first->left = tmp;
    }


    else if(first->left!= NULL && first->right == NULL)
        {
        Node* tmp = createNode(IE);
        tmp->parent = first;
        first->right = tmp;
        }

}

Node* createNode (double ins)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
   tmp->left = tmp->right = NULL;
   tmp->data = ins;
   tmp->parent = NULL;
   return tmp;
}

void printTree (Node *first)
{
    printf("%f\n", first->data);
    if(first->left!= NULL)
    {

        printTree(first->left);
    }
    if(first->right!= NULL)
    {
        printTree(first->right);
    }

}

int steps (Node *first, int count)
{
   if(first->left!= NULL && first->right!= NULL)
   {
       int a = steps(first->left, count+1);
       int b = steps(first->right, count +1);
      if(a < b)
         return a;
      else
         return b;

   }
   else
    return count;
}

void deleteTree (Node *first)
{


    if(first->right!=NULL)
    {
        deleteTree(first->right);
    }
    if(first->left!= NULL)
    {
         deleteTree(first->left);
    }


first->data =0;
    free(first);

}

Node* findElem (Node *first, double FE)
{
    if(FE == first->data)
       {
           return first;
       }

    if(first->right!= NULL)
    {
        return findElem(first->right, FE);
    }
    if(first->left!= NULL)
    {
       return findElem(first->left,FE);
    }


    return NULL;
}

void delElem (Node *first, double DE)
{

    Node* tmp = findElem(first, DE);
    if(tmp!= NULL)
    deleteTree(tmp);

}
