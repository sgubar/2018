#ifndef DK_ARRELLIPSE5_H_INCLUDED
#define DK_ARRELLIPSE5_H_INCLUDED

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

int Eladder(EllipseArr *aArr, Ellipse *eEllipse);

void freeArr(EllipseArr *aArr);

void ShellSort(EllipseArr *mass);

void LineSearch(EllipseArr *mass, float Lineup);

#endif // DK_ARRELLIPSE5_H_INCLUDED
