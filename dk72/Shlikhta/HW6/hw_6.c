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
        printf("%.2f ", pl_tmp->data);
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

float get_el_data(plist ged_list, int ged_ind) 
{
    pnode ged_tmp = get_node(ged_list, ged_ind + 1);
	return ged_tmp->data;
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

void delete_el(plist de_list, int de_ind) 
{
    pnode de_elm = get_node(de_list, de_ind + 1);

    if (de_elm->prev) {
        de_elm->prev->next = de_elm->next;
    }
    if (de_elm->next) {
        de_elm->next->prev = de_elm->prev;
    }
 
    if (!de_elm->prev) {
        de_list->head = de_elm->next;
    }
    if (!de_elm->next) {
        de_list->tail = de_elm->prev;
    }
 
    free(de_elm);
 
    de_list->size--;
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




void swap(plist s_list, int s_ind1, int s_ind2)
{
	if(s_ind1 == s_ind2) return;
	
	if(s_ind1 > s_ind2)
	{
		int ss_tmp;
		ss_tmp = s_ind1;
		s_ind1 = s_ind2;
		s_ind2 = ss_tmp;
	}
	
	pnode s_tmp1 = get_node(s_list, s_ind1);
	pnode s_tmp2 = get_node(s_list, s_ind2);
	
	if((s_ind2 - s_ind1) == 1)
	{
		pnode s_tmp_p = get_node(s_list, s_ind1 - 1);
		pnode s_tmp_n = get_node(s_list, s_ind2 + 1);
		
		
		if(s_ind1 != 0) 
		{
			
			s_tmp2->prev = s_tmp_p;
			s_tmp_p->next = s_tmp2;
		}
			else
			{
				s_tmp2->prev = NULL;
				s_list->head = s_tmp2;
			}
		
		if(s_ind2 != (s_list->size - 1))
		{
			
			s_tmp1->next = s_tmp_n;
			s_tmp_n->prev = s_tmp1;
		}
			else
			{
				s_tmp1->next = NULL;
				s_list->tail = s_tmp1;
			}
		
		s_tmp2->next = s_tmp1;
		s_tmp1->prev = s_tmp2;
	}	
	
		else
		{
			pnode s_tmp1_p = get_node(s_list, s_ind1 - 1);
			pnode s_tmp1_n = get_node(s_list, s_ind1 + 1);
			
			pnode s_tmp2_p = get_node(s_list, s_ind2 - 1);
			pnode s_tmp2_n = get_node(s_list, s_ind2 + 1);
			
		
			if(s_ind1 != 0)
			{
				s_tmp1_p->next = s_tmp2;
				s_tmp2->prev = s_tmp1_p;
			}
				else
				{
					s_tmp2->prev = NULL;
					s_list->head = s_tmp2;
				}
			
			if(s_ind2 != (s_list->size - 1))
			{			
				s_tmp1->next = s_tmp2_n;
				s_tmp2_n->prev = s_tmp1;
			}
				else
				{
					s_tmp1->next = NULL;
					s_list->tail = s_tmp1;
				}
		
			s_tmp2_p->next = s_tmp1;
			s_tmp1->prev = s_tmp2_p;	
						
			s_tmp2->next = s_tmp1_n;
			s_tmp1_n->prev = s_tmp2;
		}
}

void shell_sort(plist ss_list)
{	
	int ss_i, ss_j, ss_k;
	
	for(ss_i = (ss_list->size)/2; ss_i >= 1; ss_i /=2)
	{
		for(ss_j = 0; ss_j + ss_i < (ss_list->size); ss_j++)
		{
			if(get_el_data(ss_list, ss_j) > get_el_data(ss_list, ss_j + ss_i))	
				swap(ss_list, ss_j, ss_j + ss_i);
			
			for(ss_k = ss_j; ss_k >= ss_i; ss_k-=ss_i)
			{
				if(get_el_data(ss_list, ss_k) < get_el_data(ss_list, ss_k - ss_i)) 
					swap(ss_list, ss_k, ss_k - ss_i);
				else 
					break;
			}
		}
	}
}
