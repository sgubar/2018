#include "dk_tool.h"
 

pchar_node new_char_node(char in){
	pchar_node ret = malloc(sizeof(char_node));
	ret->a = in;
	ret->next = NULL;
	return ret;
}


single_linked_list* sll_new(){
	single_linked_list* ret = malloc(sizeof(single_linked_list));
	ret->len=0;
	ret->head = NULL;
	return ret;
}

int sll_append(single_linked_list* list, pchar_node in){
	pchar_node iter;
	for(iter = list->head; (iter != NULL); iter = iter->next){
		if(iter->next == NULL){
			iter->next = in;
			in->next = NULL;
			list->len++;
			return list->len;
		}
	}
	if(list->head == NULL){
		list->head = in;
		list->head->next = NULL;
		list->len++;
		return list->len;
	}
	return 0;
}


pchar_node sll_remove(single_linked_list* list, int index){
	if ((list->head == NULL) || (index >= list->len))return -1; //return -EFAULT;
	pchar_node iter = list->head, temp;
	if(index == 0){
		list->head = list->head->next;
		temp = iter;
	}else{
		for (int i = 0; i < index-1; ++i)
		{
			iter = iter->next;
		}
		temp = iter->next;
		iter->next = iter->next->next;
		
	}
	list->len--;
	return temp;
}




int sll_insert(single_linked_list* list, pchar_node in, int index){
	if ((list->head == NULL) || (index > list->len) || (in == NULL))return -1; //return -EFAULT;
	pchar_node iter = list->head;
	if(index == 0){
		list->head = in;
		in->next = iter;
	}else{
		for (int i = 0; i < index-1; ++i)
		{
			iter = iter->next;
		}
		in->next = iter->next;
		iter->next = in;
	}
	list->len++;
	return list->len;

}


int sll_free(single_linked_list* list){
	while(1){
		if (list->head == NULL){free(list); return 0;}
		pchar_node temp;
		temp = list->head;
		list->head = temp->next;
		free(temp);
	}
	return -1;
}

int sll_len(single_linked_list* in){
	return in->len;
}


void sll_print(single_linked_list* in){
		if (in->head == NULL){printf("empty list\n"); return 0;}
		pchar_node temp, iter;
		iter = in->head;
		int i = 0;;
		while(iter != NULL){
		i++;
		printf("%dth node: value %c\n", i, iter->a);
		iter = iter->next;
	}
}




void sll_sort(single_linked_list* list, int first, int last)
{
	if(first == last)return;
	int left, right; char mid;
	
  left = first;
  right = last;
  
  mid = sll_get_index(list, (left + right)/2)->a;
  //printf("%d mid area \n", mid);

  while (left <= right)
  {
  	//_startwhile:
    while (sll_get_index(list, left)->a < mid){
    	//printf("left++\n");
     left++;//goto _startwhile;
 }
    while (sll_get_index(list, right)->a > mid){
    	//printf("right++\n");
     right--;//goto _startwhile;
 }
    if (left <= right)
	{	
		//printf("swapping\n");
		sll_swap(list, left, right);
        left++;
        right--;
	}
  }
  //printf("?recursive fr %d to %d\n", first,right);
  if (first < right) sll_sort(list, first, right);
  //printf("?recursive fr %d to %d\n", left,last);  
  if (left < last) sll_sort(list, left, last);
    
}




pchar_node sll_get_index(single_linked_list* list, int n){
	pchar_node t = list->head;
	for (int i = 0; i < n; ++i)
	{
		t = t->next;
	}
	return t;
}



void sll_swap(single_linked_list* list, int a, int b){
	pchar_node ta, tb;
	if(a==b)return;
	if(a>b){
		a^=b;
		b^=a;
		a^=b;
	}
	tb = sll_remove(list, b);
	ta = sll_remove(list, a);
	sll_insert(list, tb, a);
	sll_insert(list, ta, b);

}





















void start__(){
	printf("\n\n\n\n\nЗАПУСКАЕМ\n" 
"░ГУСЯ░▄▀▀▀▄░РАБОТЯГИ░░\n" 
"▄███▀░◐░░░▌░░░░░░░\n" 
"░░░░▌░░░░░▐░░░░░░░\n" 
"░░░░▐░░░░░▐░░░░░░░\n" 
"░░░░▌░░░░░▐▄▄░░░░░\n"
"░░░░▌░░░░▄▀▒▒▀▀▀▀▄\n"
"░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄\n" 
"░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄\n" 
"░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄\n" 
"░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄\n" 
"░░░░░░░░░░░▌▌░▌▌░░░░░\n" 
"░░░░░░░░░░░▌▌░▌▌░░░░░\n"
"░░░░░░░░░▄▄▌▌▄▌▌░░░░░\n\n\n");
}