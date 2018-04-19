#ifndef area_h
#define area_h




typedef struct point {
	int x;
	int y;
	
}Point;


typedef struct sqere {
Point *A;
Point *B;
Point *C;
Point *D;

}Sqere;

int area (Sqere *Sqere);

void free_all(Sqere *Sqere);


#endif

