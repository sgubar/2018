#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "DZ_3.h"

struct tag_circle *createCircle(void)
{
	struct tag_circle *Circle = (struct tag_circle *) malloc(sizeof(struct tag_circle));
	Circle->radius = createLine();
	Circle->center = Circle->radius->point_A;
	if(Circle != NULL && Circle->radius != NULL)
    {
    	Circle->Area = 0;
        return Circle;
    }else
    {
    	printf("\n\n\n\t- Error -\n\n\t- No memory for circle.");
    	exit(EXIT_FAILURE);
    }
}

struct tag_line *createLine(void)
{
	struct tag_line *Line = (struct tag_line *)malloc(sizeof(struct tag_line));
	Line->point_A = createPoint();
	Line->point_B = createPoint();
	if(Line != NULL && Line->point_A != NULL && Line->point_B != NULL)
    {
        return Line;
    }else
    {
    	printf("\n\n\n\t- Error -\n\n\t- No memory for line.");
    	exit(EXIT_FAILURE);
    }
}

struct tag_point *createPoint(void)
{
	struct tag_point *Point = (struct tag_point *)malloc(sizeof(struct tag_point));
	Point->dot_x = (int *)malloc(sizeof(int));
	Point->dot_y = (int *)malloc(sizeof(int));
	if(Point != NULL && Point->dot_x != NULL && Point->dot_y != NULL)
    {
      	return Point;
    }else
    {
    	printf("\n\n\n\t- Error -\n\n\t- No memory for point.");
    	exit(EXIT_FAILURE);
    }
}

void destroyCircle(struct tag_circle *Circle)
{
	destroyLine(Circle->radius);
    free(Circle);
}

void destroyLine(struct tag_line *Line)
{
	destroyPoint(Line->point_A);
	destroyPoint(Line->point_B);
	free(Line);
}

void destroyPoint(struct tag_point *Point)
{
	free(Point->dot_x);
	free(Point->dot_y);
	free(Point);
}

int checkValidity(void)
{
	int value = 0;
	int result = scanf("%i", &value);
	while(result != 1)
	{
		fflush(stdin);
		printf("\n\t- Incorrect value ...\n\t- Value: ");
		result = scanf("%i", &value);
	}
	return value;
}

void printCircle(struct tag_circle *Circle)
{
	printf("\n\n\n\t- Center point: X - [%i]; Y - [%i]\n\n\t- Point on circle: X - [%i]; Y - [%i]\n\n\t- Area of circle: %f", *(Circle->center->dot_x), *(Circle->center->dot_y), *(Circle->radius->point_B->dot_x), *(Circle->radius->point_B->dot_y), Circle->Area);
}

void calculateArea(struct tag_circle *Circle)
{
	float pi = 3.14;
	float radius = pow((*(Circle->radius->point_B->dot_x) - *(Circle->radius->point_A->dot_x)), 2) + pow((*(Circle->radius->point_B->dot_y) - *(Circle->radius->point_A->dot_y)), 2);
	Circle->Area = pi * radius;
}


//--------end DZ 2----------------


struct tag_array *createArray(int length){
	//защита от дурака
	if(length<=0){
		exit(EXIT_FAILURE);
	}
	struct tag_array *array = malloc(sizeof(struct tag_array));
	if(array == NULL){
		exit(EXIT_FAILURE);
	}
	array->body = malloc(sizeof(struct tag_circle*)*(length));
	if(array->body == NULL){
		exit(EXIT_FAILURE);
	}
	//преинициализация
	array->length = length;
	array->current = 0;
	return array;
}


void deleteArray(struct tag_array *input){
	for (int i = input->current-1; i > 0; --i)//обходим в цикле массив с конца и удаляем круги
	{
		destroyCircle(input->body[i]);
	}
	free(input->body); //удаляем укакзатель на указатель
	free(input); //удаляем саму структуру
}

int add_to(struct tag_array *input, struct tag_circle *circle){
	//защита от дурака
	if((input->current >= input->length) || (input==NULL) || (circle==NULL)){
		exit(EXIT_FAILURE);
	}
	//выделение памяти под круг
	input->body[input->current] = malloc(sizeof(struct tag_circle));
	//копирование из структуры в массив
	memcpy(input->body[input->current], circle, sizeof(struct tag_circle));
	//увеличение счетчика массива
	++(input->current);
	return input->current;
}

char* point_to_json(struct tag_point* point){ //сериализация точки в джейсон
	//от дурака
	if(point==NULL){
		exit(EXIT_FAILURE);
	}
	char* buffer = malloc(50);
	if(buffer==NULL){
		exit(EXIT_FAILURE);
	}
	//{x:число, y: число}
	//sprintf - то же что printf, только в буфер а не на экран
	sprintf(buffer, "\n\t{\n\t\"x\":%d,\n\t\"y\":%d\n\t}", *(point->dot_x), *(point->dot_y));
	return buffer;
}


char *line_to_json(struct tag_line* line){
	char* buffA = point_to_json(line->point_A);
	char* buffB = point_to_json(line->point_B);
	char* buffLine = malloc(120);
	if((buffA == NULL) || (buffB==NULL) || (buffLine == NULL)){
		exit(EXIT_FAILURE);
	}
	sprintf(buffLine, "\n\t{\n\t\"points\":\n\t[%s,%s\n\t]\n\t}", buffA, buffB);
	free(buffA);
	free(buffB);
	return buffLine;
}

char* circle_to_json(struct tag_circle *circle){
	char* buffRad = line_to_json(circle->radius);
	char* buffCenter = point_to_json(circle->center);
	char* buffCircle = malloc(120+50+20);
	if((buffRad == NULL) || (buffCenter==NULL) || (buffCircle == NULL)){
		exit(EXIT_FAILURE);
	}
	sprintf(buffCircle, "\n\t{\n\t\"radius\":%s,\n\t\"center\":%s\n\t}\n\t", buffRad, buffCenter);
	free(buffRad);
	free(buffCenter);
	return buffCircle;
}

char* array_to_json(struct tag_array *array){
	char* buffArray = malloc(190*array->current + 50);
	if((array == NULL) || (buffArray==NULL)){
		exit(EXIT_FAILURE);
	}
	sprintf(buffArray, "\n\t{\n\t\"length\":%d,\n\t\"current\":%d,\n\t\"body\":\n\t[", array->length, array->current);
	for (int i = 0; i < array->current; ++i)
	{
		char* buffCircle = circle_to_json(array->body[i]);
		strcat(buffArray, buffCircle);
		if(i+1 != array->current){
			strcat(buffArray, ",");
		}
		free(buffCircle);
	}
	strcat(buffArray, "\n\t]\n\t}\n\t");
	return buffArray;
}

//----end dz 3


void sort_array(struct tag_array *array){
	for(int i=1;i<array->current;i++){    
		for(int j=i;j>0 && array->body[j-1]->Area > array->body[j]->Area;j--){
			struct tag_circle tmp;
			memcpy(&tmp, array->body[j], sizeof(struct tag_circle));
			memcpy(array->body[j], array->body[j-1], sizeof(struct tag_circle));
			memcpy(array->body[j-1], &tmp, sizeof(struct tag_circle));
		}
	}
}

//end dz 4

struct tag_circle **merge(struct tag_circle **x, struct tag_circle **y, int len1, int len2){
	struct tag_circle **m = malloc((len1+len2)*sizeof(struct tag_circle *));
	int i=0,j=0, k=0;
	while(i<len1 && j<len2){
		m[k] = (x[i]->Area>y[j]->Area)? y[j++]:x[i++];
		k++;
		printf("k1=%d\n", k);
	}
	while(i<len1){
		m[k] = x[i++];
		k++;
		printf("k2=%d\n", k);
	}
	while(j<len2){
		m[k] = y[j++];
		k++;
		printf("k3=%d\n", k);
	}
	return m;
}


void msort(struct tag_circle **body, int len){
	if(len==1){
		return;
	}else{
		msort(body,len/2);
		msort(&body[len/2],len-len/2);
		struct tag_circle **w = merge(body,&body[len/2], len/2, len-len/2);
		memcpy(body, w ,len*sizeof(struct tag_circle *));
		free(w);
	}
}
 

void merge_sort_array(struct tag_array *array){
	msort(array->body, array->current);
}
