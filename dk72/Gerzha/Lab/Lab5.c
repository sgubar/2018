#include <stdio.h>
#include <stdlib.h>

struct node 
{
    float data;
    struct node *left;
    struct node *right;
};
 

struct node *newNode(float item)
{
	  //allocate memory for new element
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}




void insertNode(struct node** p, float data){
	//add new node
	if(*p == NULL) *(p) = newNode(data);
	else 
	{
		if(data < (*p)->data)  insertNode((&(*p)->left), data);
		else insertNode(&((*p)->right), data);
	}

}



void PreOrderTravers(struct node* root)
{
    //node-left-right
    if(root != NULL){
      printf("%.6g ", root->data);
      PreOrderTravers(root->left);
      PreOrderTravers(root->right);    
    }
}

struct node* findLargestNode(struct node* root){
  if(root == NULL || root->right == NULL) return root;
  else return findLargestNode(root->right);
}

void deleteNode(struct node** root, float val)
{

    if(*root == NULL) printf("Val was not found\n");
    else if((*root)->data > val) deleteNode(&(*root)->left, val); //search element in left sub-tree
    else if((*root)->data < val) deleteNode(&(*root)->right, val); //search element in right sub-tree
    else if((*root)->left && (*root)->right){
              struct node* temp = findLargestNode((*root)->left);
              (*root)->data = temp->data;
              deleteNode(&(*root)->left, temp->data);
            }
    
    else    {
              struct node* temp = *root;
              if((*root)->left == NULL && (*root)->right == NULL){
                (*root) = NULL;
              }else if((*root)->left != NULL) *root = (*root)->left;
               else *root = (*root)->right;
               free(temp);
    }

    
}


struct node* searchElement(struct node* root, float val)
{
    if(root == NULL || root->data == val){
        return root;
    }else{
        if(val < root->data) return searchElement(root->left, val);
        else return searchElement(root->right, val);
    }
}

void deleteTree(struct node* root)
{
    if(root != NULL){
      deleteTree(root->left);
      deleteTree(root->right);
      free(root);
    }
}


int main()
{  

  struct node *root = NULL;
  

  insertNode(&root, 3.1);
  insertNode(&root, 2.2);
  insertNode(&root, 10.5);
  insertNode(&root, 40.1);
  insertNode(&root, 5.23);
  insertNode(&root, 15);
  deleteNode(&root, 15);

  PreOrderTravers(root);
  deleteTree(root);
  printf("\n");
   
   
  return 0;
}