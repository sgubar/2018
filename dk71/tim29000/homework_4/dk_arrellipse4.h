#ifndef DK_ARRELLIPSE4_H_INCLUDED
#define DK_ARRELLIPSE4_H_INCLUDED


typedef struct tagArrayofEllipses
{
    int number;
    int Count;
    float Area;
    Ellipse **Ellipses;
}EllipseArr;

EllipseArr *createArr(int Val);

void Arr_writer(FILE *eFile, EllipseArr *aArr);

void Point_writer(FILE *eFile, Point *ePoint);

void Select_Sort(EllipseArr *aArr);

int Eladder(EllipseArr *aArr, Ellipse *eEllipse);

void freeArr(EllipseArr *aArr);


#endif // DK_ARRELLIPSE3_H_INCLUDED
