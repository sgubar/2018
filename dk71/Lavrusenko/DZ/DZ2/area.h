#ifndef area.h
#define area.h



typedef struct point {
	int x;
	int y;
	
}Point;


typedef struct side {
Point points[1];


}Side;
void check_enter (struct point *arry);
double  length_sqere (struct Side);
 void free_all(struct point *arry);

#endif
