#include "dk_tool.h"
#include <stdio.h>

Point* new_Point(int x, int y) {
	Point* point = malloc(sizeof(*point));
	point->x = x;
	point->y = y;
	return point;
}

Trapeze* new_TrapezePointArray(Point* points[4]) {
	int i;
	for (i = 0; i < 4; i++) {
		if (points[i] == NULL) {
			printf("Point %d wasn't initialized\n Returning NULL", i);
			return NULL;
		}
	}
	Trapeze* trapeze = malloc(sizeof(*trapeze));
	trapeze->points[0] = points[0];
	trapeze->points[1] = points[1];
	trapeze->points[2] = points[2];
	trapeze->points[3] = points[3];
	return trapeze;
}

Trapeze* new_TrapezePointEnum(Point* first, Point* second, Point* third, Point* fourth) {
	Trapeze* trapeze = malloc(sizeof(*trapeze));
	if (first == NULL || second == NULL || third == NULL || fourth == NULL) {
		printf("One of the points is not defined");
		return NULL;
	}
	trapeze->points[0] = first;
	trapeze->points[1] = second;
	trapeze->points[2] = third;
	trapeze->points[3] = fourth;
	return trapeze;
}

Trapeze* new_TrapezePointCoord(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	Trapeze* trapeze = malloc(sizeof(*trapeze));
	trapeze->points[0] = new_Point(x1, y1);
	trapeze->points[1] = new_Point(x2, y2);
	trapeze->points[2] = new_Point(x3, y3);
	trapeze->points[3] = new_Point(x4, y4);
	return trapeze;
}

void del_Trapeze(Trapeze* trapeze) {
	int i;
	for (i = 0; i < 4; i++) {
		free(trapeze->points[i]);
	}
	free(trapeze);
}

void print_Trapeze(Trapeze* trapeze) {
	printf("First point: %d %d\n", trapeze->points[0]->x, trapeze->points[0]->y);
	printf("Second point: %d %d\n", trapeze->points[1]->x, trapeze->points[1]->y);
	printf("Third point: %d %d\n", trapeze->points[2]->x, trapeze->points[2]->y);
	printf("Fourth point: %d %d\n", trapeze->points[3]->x, trapeze->points[3]->y);
}

TrapezeArray* new_Array(int capacity) {
	TrapezeArray* TrapezeArray = malloc(sizeof(*TrapezeArray));
	TrapezeArray->capacity = capacity;
	TrapezeArray->array = malloc(sizeof(Trapeze*) * capacity);
	int i;
	for (i = 0; i < capacity; i++) {
		TrapezeArray->array[i] = malloc(sizeof(Trapeze*));
	}
	return TrapezeArray;
}
int AddElem(TrapezeArray* trapezeArray, Trapeze* trapeze) {
	int i;
	for (i = 0; i < trapezeArray->capacity; i++) {
		if (trapezeArray->array[i] == NULL) {
			trapezeArray->array[i] = trapeze;
			return i;
		}
	}
	return -1;
}

int InsertElem(TrapezeArray* trapezeArray, Trapeze* trapeze, int index) {
	if (index < trapezeArray->capacity) {
		del_Trapeze(trapezeArray->array[index]);
		trapezeArray->array[index] = trapeze;
		return index;
	}
	return -1;
}

void del_Array(TrapezeArray* trapezeArray) {
	int i;
	for (i = 0; i < trapezeArray->capacity; i++) {
		del_Trapeze(trapezeArray->array[i]);
	}
	free(trapezeArray);
}

void WriteTrapezeToFile(FILE** file, Trapeze* trapeze) {
  fprintf(file, "{\n");
  int j;
  for (j = 0; j < 4; j++) {
    fprintf(file, "\"point%d\":{\n", j+1);
    fprintf(file, "\"x\": \"%d\",\n", trapeze->points[j]->x);
    if (j == 3) {
      fprintf(file, "\"y\": \"%d\"\n}\n", trapeze->points[j]->y);
    }
    else {
      fprintf(file, "\"y\": \"%d\"\n},\n", trapeze->points[j]->y);
    }
  }
  fprintf(file, "}");
}

void WriteArrayToFile(FILE** file, TrapezeArray* trapezeArray) {
  fprintf(*file, "{\n \"trapezeArray\": [\n");
  int last_not_null;
  int i;
  for (i = 0; i < trapezeArray->capacity; i++) {
    if (trapezeArray->array[i] != NULL) {
      last_not_null = i;
    }
  }
  for (i = 0; i <= last_not_null; i++) {
    if (trapezeArray->array[i] != NULL) {
      WriteTrapezeToFile(*file, trapezeArray->array[i]);
      if (i != last_not_null) {
        fprintf(*file, ",\n");
      }
      else {
        fprintf(*file, "\n");
      }
    }
  }
  fprintf(*file, "]\n}");
}
