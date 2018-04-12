#include "right_triangle.h"
#include "dk_tool.h"
 
rtriangle_array* new_rtriangle_array(int number){
	if(number <= 0) return NULL;
	rtriangle_array* result = malloc(sizeof(rtriangle_array));
	if(!result)return NULL;
	result->array = malloc(sizeof(rtriangle2d)*number);
	if(!(result->array)){
		free(result);
		return NULL;
	} 
	result->len = number;
	result->cur = 0;
	return result;
}

int free_rtriangle_array(rtriangle_array* tarray){
	if(!tarray) return -1;
	for (int i = 0; i < tarray->cur; ++i)
	{
		triangle_free(&tarray->array[i]);
	}
	// free(tarray->array);
	free(tarray);
	return 0;
}

int addto_rtriangle_array(rtriangle_array* tarray, prtriangle2d tri){ 
	if(!tarray || !tri)return -1;
	if(tarray->cur+1 > tarray->len){
		printf("loh\n");
		return -2;}
	//free(&tarray->array[tarray->cur++]);
	memcpy(&tarray->array[tarray->cur++], tri, sizeof(rtriangle2d));
	//triangle_free(tri);
	return tarray->cur;
}


void isort(rtriangle_array* in){
	for(int i=1;i< (in->cur) ;i++){    
		for(int j=i;j>0 && area(&in->array[j-1])>area(&in->array[j]);j--){
			prtriangle2d tmp = malloc(sizeof(rtriangle2d)); //in->array[j];
			memcpy(tmp, &in->array[j], sizeof(rtriangle2d));
			memcpy(&in->array[j], &in->array[j-1], sizeof(rtriangle2d));
			memcpy(&in->array[j-1], tmp, sizeof(rtriangle2d));
		}
	}
}


// void quick_sort(prtriangle2d qs_arr, int first, int last)
// {
// 	int mid, left, right;
	
//   left = first;
//   right = last;
  
//   mid = area(&qs_arr[(left + right) / 2]);
//   while (left <= right)
//   {
//     while (area(&qs_arr[left]) < mid) left++;
//     while (area(&qs_arr[right]) > mid) right--;
//     if (left <= right)
// 	{	
// 		prtriangle2d temp = &qs_arr[left];
//         qs_arr[left] = qs_arr[right];
//         qs_arr[right] = temp; 
//         left++;
//         right--;
// 	}
//   }
//   if (first < right) quick_sort(qs_arr, first, right);
    
//   if (left < last) quick_sort(qs_arr, left, last);
    
// }


void quick_sort(prtriangle2d qs_arr, int first, int last)
{
	if(first == last)return;
	int left, right; int mid;
	
  left = first;
  right = last;
  
  mid = (int)area(&qs_arr[(left + right) / 2]);
  printf("%d mid area \n", mid);

  while (left <= right)
  {
  	//_startwhile:
    while ((int)area(&qs_arr[left]) < mid){
    	printf("left++\n");
     left++;//goto _startwhile;
 }
    while ((int)area(&qs_arr[right]) > mid){
    	printf("right++\n");
     right--;//goto _startwhile;
 }
    if (left <= right)
	{	
		printf("swapping\n");
		prtriangle2d temp = malloc(sizeof(rtriangle2d));
		memmove(temp, &qs_arr[left],sizeof(rtriangle2d));
        memmove(&qs_arr[left], &qs_arr[right],sizeof(rtriangle2d));
        memmove(&qs_arr[right], temp,sizeof(rtriangle2d)); 
        free(temp);
        left++;
        right--;
	}
  }
  printf("?recursive fr %d to %d\n", first,right);
  if (first < right) quick_sort(qs_arr, first, right);
  printf("?recursive fr %d to %d\n", left,last);  
  if (left < last) quick_sort(qs_arr, left, last);
    
}

/*

point

{
	"x":int,
	"y": int
}



1+1+1+3+1+11+1+1+1+4+11+1+1+1



tri
{
	"points":
	[

	]
}
1+1+1+9+1+1+1+1+1+1
*/



char* point_to_json(ppoint2d point){
	if(!point){
		printf("your point is UGLY\n");
		return NULL;
	}
	char* buffer = malloc(50);
	if(!buffer){
		printf("your point buffer is UGLY\n");
		return NULL;
	}
	sprintf(buffer, "\n{\n\t\"x\":%3e,\n\t\"y\":%3e\n}",point->x, point->y);
	return buffer;
}

char* rtri_to_json(prtriangle2d tri){
	if(!tri){
		printf("your tri is UGLY\n");
		return NULL;
	}
	char* buffer = malloc(150);
	if(!buffer){
		printf("your tri buffer is UGLY\n");
		return NULL;
	}
	char *a = point_to_json(tri->points[0]), *b = point_to_json(tri->points[1]), *c = point_to_json(tri->points[2]);
	sprintf(buffer, "{\n\t\"points\":\n\t[%s,%s,%s\n\t]\n}\n",a,b,c);
	free(a);
	free(b);
	free(c);
	return buffer;
}


char* tarray_to_json(rtriangle_array* in){
	if(!in){
		printf("your array is UGLY\n");
		return NULL;
	}
	char* buffer = malloc(in->cur * 150 + 50);
	if(!buffer){
		printf("your array buffer is UGLY\n");
		return NULL;
	}
	sprintf(buffer, "{\n\t\"len\":%d,\n\t\"cur\":%d,\n\t\"array\":\n\t[", in->len, in->cur);
	for (int i = 0; i < in->cur; ++i)
	{	char* a = rtri_to_json(&in->array[i]);
		strcat(buffer, a);
		if(i+1 != in->cur){
			strcat(buffer, ",");
		}
		free(a);
	}
	strcat(buffer, "\n\t]\n}\n");
	return buffer;
}













