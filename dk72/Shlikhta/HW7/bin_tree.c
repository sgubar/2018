#include "libs.h"

pbin_tree create_tree()
{
	pbin_tree ct_tree = malloc(sizeof(bin_tree));
	ct_tree->root = NULL;
	ct_tree->size = 0;
}

void add_el(pbin_tree ae_tree, float ae_data)
{
	pnode ae_temp = malloc(sizeof(node));
	
	ae_temp->data = ae_data;
	ae_temp->left = ae_temp->right = NULL;

	pnode ae_root = ae_tree->root;
	
	if(ae_tree->root == NULL)
	{
		ae_tree->root = ae_temp;
	}
		else
		{
			if(find_el(ae_tree, ae_data) == 1) return;
			
			while(ae_root)
			{
				if(ae_root->data < ae_data)
					if(ae_root->right == NULL)
					{
						ae_root->right = ae_temp; 
						break;
					}
						else
						{
							ae_root = ae_root->right;
							continue;
						}
				
					
				if(ae_root->data > ae_data)
					if(ae_root->left == NULL)
					{
						ae_root->left = ae_temp; 
						break;
					}
						else
						{
							ae_root = ae_root->left;
							continue;
						}		
			}
		}
	ae_tree->size++;
}

int find_el(pbin_tree se_tree, float se_data)
{
	pnode se_temp = se_tree->root;
	
	while(se_temp)
	{
		if(se_temp->data < se_data) 
			se_temp = se_temp->right;
			else 
				if(se_temp->data > se_data) 
					se_temp = se_temp->left;
					else 
						return 1;
	}
	
	return 0;
}

void delete_child(pnode dc_temp)
{
    if(dc_temp == NULL) return;
    delete_child(dc_temp->left);
    delete_child(dc_temp->right);
    free(dc_temp);
} 
 
void delete_tree(pbin_tree dt_tree)
{
    delete_child(dt_tree->root);
    free(dt_tree);
}


void print_tree(pnode pt_temp)
{
	if(pt_temp == NULL) return;
	print_tree(pt_temp->left);
	printf(" %.1f ", pt_temp->data);
	print_tree(pt_temp->right);
	printf("\n");
}


int remove_node(pbin_tree dnbi_tree, float dnbi_data)
{
    pnode * pdnbi_temp,dnbi_temp;
     
	if(find_el(dnbi_tree, dnbi_data) == 0) return 0;
	 
    pdnbi_temp=&dnbi_tree->root;
    dnbi_temp=dnbi_tree->root;
    
    while(dnbi_temp)
    {
		if(dnbi_data > dnbi_temp->data)
		{
			pdnbi_temp = &dnbi_temp->right;
			dnbi_temp = dnbi_temp->right;
		}
			else 
				if(dnbi_data < dnbi_temp->data)
				{
					pdnbi_temp = &dnbi_temp->left;
					dnbi_temp = dnbi_temp->left;
				}
					else
						break;
    }       
     
    if(dnbi_temp->right == NULL) 
		*pdnbi_temp = dnbi_temp->left;
			else
			{
				pnode dnbi_right = dnbi_temp->right;
				if(dnbi_right->left == NULL)
				{
					dnbi_right->left = dnbi_temp->left;
					*pdnbi_temp=dnbi_right;
				}
					else
					{
						pnode dnbi_left = dnbi_right->left;
						while(dnbi_left->left != NULL)
						{
							dnbi_right = dnbi_left;
							dnbi_left = dnbi_right->left;
						}
						
						dnbi_right->left = dnbi_left->right;
						dnbi_left->left = dnbi_temp->left;
						dnbi_left->right = dnbi_temp->right;
						*pdnbi_temp=dnbi_left;
					}
			}
 
    dnbi_tree->size--;
    free(dnbi_temp);
	return 1;
}