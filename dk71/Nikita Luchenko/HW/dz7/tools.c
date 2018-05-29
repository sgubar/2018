#include "tools.h"
#include <stdlib.h>
#include <stdio.h>

Node *create_node(Node *root, double val)
{
	Node *thetree = malloc(sizeof(Node));
	if(thetree != NULL)
  	{
		thetree->value = val;
		thetree->left = NULL;
		thetree->right = NULL;
		thetree->root = root;
  	}
  	return thetree;
}
 
void add_node(Node *thetree, double val)
{
	Node *tmp = thetree;
	if(thetree == NULL)
	{
  	  thetree = create_node(NULL, val);
  	  return;
	}

		while(tmp)
		{
			if(val > tmp->value)
			{
				if(tmp->right)
				{
					tmp = tmp->right;
					continue;
				}else
				{
					tmp->right = create_node(tmp, val);
					return;
				}
			}else if(val < tmp->value)
			{
				if(tmp->left)
				{
					tmp = tmp->left;
					continue;
				}else
				{
					tmp->left = create_node(tmp, val);
					return;
				}
			}else
			{
				return;
			}
		}
}


void delete_target(Node *target)
 {
    if (target->left && target->right)
	{
        Node *max = find_max_min(target->left, 1);
        target->value = max->value;
        delete_target(max);
        return;
    } else if(target->left)
	{
        if(target == target->root->left)
		{
            target->root->left = target->left;
        } else
		{
            target->root->right = target->left;
        }
    } else if(target->right)
	{
        if (target == target->root->right)
		{
            target->root->right = target->right;
        } else
		{
            target->root->left = target->right;
        }
    } else
	{
        if(target == target->root->left)
		{
            target->root->left = NULL;
        } else {
            target->root->right = NULL;
        }
    }
    free(target);
}

Node *get_node_by_value(Node *root, double val)
{
    while (root) 
	{
        if (root->value > val)
		{
            root = root->left;
            continue;
        } else if(root->value < val)
		{
            root = root->right;
            continue;
        } else 
		{
            return root;
        }
    }
    return NULL;
}


void delete_node(Node *root, double val)
{
    Node *target = get_node_by_value(root, val);
    delete_target(target);
}

Node *search(Node *thetree, double val)
{
  	Node *tmp = thetree->root;
    while(tmp)
	{
        if(tmp->value < val)
			tmp = tmp->right;
        else if(tmp->value > val)
	 		tmp = tmp->left;
	 	else if(val == tmp->value)
    	return 1;
	}
	return 0;
}

Node *find_max_min(Node *root, int val)
{
	if(root != NULL)
	{
		Node *thenode = root;
		if(val == 0)
	 	{
		while(thenode->left)
			thenode = thenode->left;
		return thenode;
	 	}else if(val == 1)
	 	{
		while(thenode->right)
			thenode = thenode->right;
		return thenode;
 		}
	}
}

int size(Node* root) 
{
    if (root == NULL) 
        return 0;
    else 
    {
        return(size(root->left) + 1 + size(root->right));
    }
}

int height(Node* root)
{
   if (root == NULL)
       return 0;
   else
   {
     int lheight = height(root->left);
     int rheight = height(root->right);
 
     if (lheight > rheight) 
	  return(lheight+1);
     else
	  return(rheight+1);
   }
}

//void printGivenLevel(Node* root, int level)
//{
//  if(root == NULL)
//    return;
//  if(level == 1)
//    printf("%f ", root->value);
//  else if (level > 1)
//  {
//    if(root)
//    {
//      printGivenLevel(root->left, level-1);
//      printGivenLevel(root->right, level-1);
//    }
//    else
//    {
//      printGivenLevel(root->right, level-1);
//      printGivenLevel(root->left, level-1);
//    }
//  }
//}
 
void node_free(Node *thetree)
{
	if(thetree == NULL)return;
	tree_free(thetree->left);
	tree_free(thetree->right);
	free(thetree);
}

 void tree_free(Node *thetree)
{
	node_free(thetree->root);
}

void node_print(Node *thetree)
{
	if(thetree)
	{
		node_print(thetree->left);
		node_print(thetree->right);
		printf("%f.3\n", thetree->value);
	}
}

void tree_print(Node *thetree)
{
	if(thetree != NULL)
		node_print(thetree->root);
	else
    {
        printf("\n\nYou have not created binary tree ...");
        return;
    }
}


