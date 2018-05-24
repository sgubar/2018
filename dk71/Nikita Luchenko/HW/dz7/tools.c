#include "tools.h"
 
Tree* create_tree()
{
	Tree *thetree = malloc(sizeof(Tree));
	if(thetree != NULL)
  {
	thetree->size = 0;
	thetree->root = NULL;
  }
  return thetree;
}

Node *create_node(double val)
{
	Node *thetree = malloc(sizeof(Node));
	if(thetree != NULL)
  {
	thetree->value = val;
	thetree->left = NULL;
	thetree->right = NULL;
  }
	return thetree;
}

Node *search(Tree *thetree, double val)
{
  	Node *tmp = thetree->root;
    while(1)
	{
        if(tmp == NULL) return 0;
        else if(val == tmp->value)
		{
		printf("YEH!");
		return tmp;
		}
        else if(val > tmp->value) tmp = tmp->right;
        else tmp = tmp->left;  
    }
}


void add_node(Tree *thetree, double val)
{
    Node *tmp, **new;
 	new = &thetree->root;
    tmp = thetree->root;
 
    while(1)
	{
        if(tmp == NULL)
        {
            tmp = create_node(val);
			return;
        }
        else if(val == tmp->value) return;
		else if(val > tmp->value)
		{
			new = &tmp->right;
            tmp = tmp->right;
        }
        else
        {
        	new = &tmp->left;
            tmp = tmp->left;
		}
 thetree->size++;
    }
}


Node *delete_node(Tree *thetree, double val)
{
    Node **q, *z;
    q = &thetree->root;
    z = thetree->root;
  
    while(1)
	{
        if(z == NULL) return 0;
        else if(val == z->value) break;
        else if(val > z->value)
		{
            q = &z->right;
            z = z->right;
        }
        else
        {
        	q = &z->left;
            z = z->left;
		}
    } 
    if(z->right == NULL)
	{
    	*q = z->left;
	}
	else
	{
        Node *y = z->right;
        if(y->left == NULL)
		{
            y->left = z->left;
            *q=y;
        }
		else
		{
            Node *x = y->left;
            while(x->left != NULL)
			{
                y = x;
                x = y->left;
            }
            y->left = x->right;
            x->left = z->left;
            x->right = z->right;
            *q=x;
        }
    }
 	thetree->size--;
    return z;
}

void node_free(Node *thetree)
{
	if(thetree == NULL)return;
	tree_free(thetree->left);
	tree_free(thetree->right);
	free(thetree);
}
 
 void tree_free(Tree *thetree)
{
	node_free(thetree->root);
}

void node_print(Node *thetree)
{
	if(thetree == NULL) return;
	node_print(thetree->left);
	node_print(thetree->right);
	printf("%f\n", thetree->value);
}

void tree_print(Tree *thetree)
{
	node_print(thetree->root);
}




