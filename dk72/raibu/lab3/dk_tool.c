#include "dk_tool.h"


void print_arr(int* x, int len){
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
}




void bsort(int* x, int len){
	for (int i = len - 1; i >= 0; i--)
 	{
	    for (int j = 0; j < i; j++)
 		{
			if (x[j] > x[j + 1])
			{
				int tmp = x[j];
				x[j] = x[j + 1]; 
				x[j + 1] = tmp;
			}
		}
	}
  
}



void isort(int* x, int len){
	for(int i=1;i<len;i++){    
		for(int j=i;j>0 && x[j-1]>x[j];j--){
			int tmp = x[j];
			x[j] = x[j - 1];
			x[j - 1] = tmp;
		}
	}
}



void csort(int* x, int len){
	for (int i = 0; i < len-1; ++i)
	{
		int min=i;
		for (int j = 0; j < len; ++j)
		{
			min = (x[min] < x[j])?min:j;
		}
		int tmp = x[i];
		x[i] = x[min];
		x[min] = tmp;
	}
}



void msort(int* x, int len){
	if(len==1){
		return;
	}else{
		msort(x,len/2);
		msort(x+len/2,len-len/2);
		int* w = merge(x,x+len/2, len/2, len-len/2);
		memcpy(x, w ,len*sizeof(int));
		free(w);
	}
}
 

int* merge(int* x, int* y, int len1, int len2){
	int* m = malloc((len1+len2)*sizeof(int));
	int i=0,j=0, k=0;
	while(i<len1 && j<len2){
		m[k] = (x[i]>y[j])? y[j++]:x[i++];
		k++;

	}
	while(i<len1){
		m[k] = x[i++];
		k++;
	}
	while(j<len2){
		m[k] = y[j++];
		k++;
	}
	return m;
}
 


void quick_sort(int *qs_arr, int first, int last)
{
	int mid, left, right;
	
  left = first;
  right = last;
  
  mid = qs_arr[(left + right) / 2];
  while (left <= right)
  {
    while (qs_arr[left] < mid) left++;
    while (qs_arr[right] > mid) right--;
    if (left <= right)
	{	
		int temp = qs_arr[left];
        qs_arr[left] = qs_arr[right];
        qs_arr[right] = temp; 
        left++;
        right--;
	}
  }
  if (first < right) quick_sort(qs_arr, first, right);
    
  if (left < last) quick_sort(qs_arr, left, last);
    
}



int lin_search(int* arr, int len, int val){
	for (int i = 0; i < len; ++i)
	{
		if(arr[i] == val)return 0xff;
	}
	return 0;
}





int* gen_rand(int len){
	int* m = malloc(sizeof(int)*len);
	if(m==NULL)return NULL;
	srand(time(NULL));
	for (int i = 0; i < len; ++i)
	{
		m[i] = rand()%1000;
	}
	return m;
}

 











