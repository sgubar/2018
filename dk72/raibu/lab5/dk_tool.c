#include "dk_tool.h"
 

pbt_node new_bt_node(char x){
	pbt_node ret = malloc(sizeof(bt_node));
	CHNULL(ret);
	ret->a = x;
	ret->ch[0] = NULL;
	ret->ch[1] = NULL;
	return ret;
}

bintree* new_bintree(){
	bintree* ret = malloc(sizeof(bintree));
	CHNULL(ret);
	ret->len=0;
	ret->head = NULL;
	return ret;
}

pbt_node bin_search(bintree* bt, char d){
  	pbt_node tmp = bt->head;
    while(1){
        if(tmp == NULL) return NULL;
        else if(d == tmp->a) return tmp;
        else tmp = tmp->ch[(d > tmp->a)?1:0];  
    }
}

void add_node(bintree* bt, char d)
{
    pbt_node tmp, *new;
 	new = &bt->head;
    tmp = bt->head;
 
    while(1){
        if(tmp == NULL)
        {
            tmp = *new = new_bt_node(d);return;
        }
        else if(d == tmp->a) return;
		else{
			new = &tmp->ch[(d > tmp->a)];
            tmp = tmp->ch[(d > tmp->a)];
        }
    }
}


pbt_node pop_node(bintree* bt, char d){
    pbt_node* q, z;
    q=&bt->head;
    z=bt->head;
  
    while(1){
        if(z == NULL) return NULL;
        else if(d == z->a) break;
        else{
            q = &z->ch[(d > z->a)];
            z = z->ch[(d > z->a)];
        }
    } 
    if(z->ch[1] == NULL){
    	*q = z->ch[0];
	}else{
        pbt_node y = z->ch[1];
        if(y->ch[0] == NULL){
            y->ch[0] = z->ch[0];
            *q=y;
        }else{
            pbt_node x=y->ch[0];
            while(x->ch[0] != NULL){
                y = x;
                x = y->ch[0];
            }
            y->ch[0] = x->ch[1];
            x->ch[0] = z->ch[0];
            x->ch[1] = z->ch[1];
            *q=x;
        }
    }
 	bt->len--;
    return z;
}





void node_print(pbt_node in){
	if(in == NULL)return;
    printf("%u\n", in->a);
	node_print(in->ch[0]);
    node_print(in->ch[1]);
}

void bt_print(bintree* in){
	node_print(in->head);
}

void node_free(pbt_node in){
	if(in == NULL)return;
	node_free(in->ch[0]);
	node_free(in->ch[1]);
	free(in);
}

void bt_free(bintree* in){
	node_free(in->head);
	free(in);
}




















