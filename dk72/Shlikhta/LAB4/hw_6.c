#include "hw_6.h"

plist create_list()
{
	plist cl_list = malloc(sizeof(list));
	
	cl_list->size = 0;
	cl_list->head = cl_list->tail = NULL;
	
	return cl_list;
}

void add_el(plist ae_list, float ae_data) 
{
    pnode ae_tmp = malloc(sizeof(node));

    ae_tmp->data = ae_data;
    ae_tmp->next = NULL;
    ae_tmp->prev = ae_list->tail;
    if (ae_list->tail) 
        ae_list->tail->next = ae_tmp;
 
    ae_list->tail = ae_tmp;
 
    if (ae_list->head == NULL)
        ae_list->head = ae_tmp;

    ae_list->size++;
}

void print_list(plist pl_list) 
{
    pnode pl_tmp = pl_list->head;
	
	while(pl_tmp)
	{
        printf("%.1f ", pl_tmp->data);
        pl_tmp = pl_tmp->next;
    }
	
    printf("\n");
}

pnode get_node(plist gn_list, int gn_ind)
{
    pnode gn_tmp = gn_list->head;
    int gn_i = 0;
 
    while (gn_tmp && gn_i < gn_ind - 1) {
        gn_tmp = gn_tmp->next;
        gn_i++;
    }
 
    return gn_tmp;
}

void delete_list(plist dl_list) 
{
    pnode dl_tmp = dl_list->head;
    pnode dl_next = malloc(sizeof(node));
    while (dl_tmp) {
        dl_next = dl_tmp->next;
        free(dl_tmp);
        dl_tmp = dl_next;
    }
    free(dl_list);
    dl_list = NULL;
}

void insert_el(plist ie_list, int ie_ind, float ie_data) 
{
		
	if(ie_ind == 0)
	{			
		add_el_to_beg(ie_list, ie_data);
		return;
	}
		
		
	pnode ie_elm = get_node(ie_list, ie_ind);
    pnode ie_ins = malloc(sizeof(node));

    ie_ins->data = ie_data;
    ie_ins->prev = ie_elm;
    ie_ins->next = ie_elm->next;
	
    if (ie_elm->next)
        ie_elm->next->prev = ie_ins;
	
    ie_elm->next = ie_ins;
 
    if (!ie_elm->prev)
        ie_list->head = ie_elm;

    if (!ie_elm->next)
        ie_list->tail = ie_elm;
 
    ie_list->size++;
}

void add_el_to_beg(plist aetb_list, float aetb_data) 
{
    pnode aetb_tmp = malloc(sizeof(node));
    if (aetb_tmp == NULL) {
        exit(1);
    }
    aetb_tmp->data = aetb_data;
    aetb_tmp->next = aetb_list->head;
    aetb_tmp->prev = NULL;
	
    if (aetb_list->head)
        aetb_list->head->prev = aetb_tmp;

    aetb_list->head = aetb_tmp;
 
    if (aetb_list->tail == NULL)
        aetb_list->tail = aetb_tmp;
	
    aetb_list->size++;
}

