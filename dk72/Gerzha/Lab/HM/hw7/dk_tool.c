#include "dk_tool.h"
 

pnode new_bt_node(int x){
	pnode ret = malloc(sizeof(node));
	if(ret==NULL){printf("INVALID MALLOC\n");return NULL;}
	ret->a = x;
	ret->ch[0] = NULL;
	ret->ch[1] = NULL;
	return ret;
}

bintree* new_bintree(){
	bintree* ret = malloc(sizeof(bintree));
	if(ret==NULL){printf("INVALID MALLOC\n");return NULL;}
	ret->length=0;
	ret->head = NULL;
	return ret;
}

pnode bin_search(bintree* bt, int d){
  	pnode tmp = bt->head;
    while(1){
        if(tmp == NULL) return NULL;
        else if(d == tmp->a) return tmp;
        else tmp = tmp->ch[(d > tmp->a)?1:0];  
    }
}

void add_node(bintree* bt, int d)
{
    pnode tmp, *new;
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


pnode pop_node(bintree* bt, int d){
    pnode* q, z;
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
        pnode y = z->ch[1];
        if(y->ch[0] == NULL){
            y->ch[0] = z->ch[0];
            *q=y;
        }else{
            pnode x=y->ch[0];
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
 	bt->length--;
    return z;
}





void node_print(pnode in){
	if(in == NULL)return;
	node_print(in->ch[0]);
	printf("%d\n", in->a);
	node_print(in->ch[1]);
}

void bt_print(bintree* in){
	node_print(in->head);
}

void node_free(pnode in){
	if(in == NULL)return;
	node_free(in->ch[0]);
	node_free(in->ch[1]);
	free(in);
}

void bt_free(bintree* in){
	node_free(in->head);
	free(in);
}

int get_int(void){ //from MIT's cs50 library i dont understand how it works
	regex_t pattern;
	char* str = malloc(64);
	scanf("%s", str);
	regcomp(&pattern, "[+-]?[0-9]+", REG_EXTENDED | REG_NOSUB);
	while(regexec(&pattern, str, 0, NULL, 0)){
		printf("Retry: ");
		scanf("%s", str);
	}
	int d = atoi(str);
	free(str);
	regfree(&pattern); 
	return d;
}


















