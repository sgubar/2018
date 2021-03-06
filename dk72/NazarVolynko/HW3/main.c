#include "dk_kvadrat.h"
#include "dk_kvadrat_array.h"


int main(int argc, const char * argv[])
{

    KvadratArray *theArray = createArray(5);

 int A_x, A_y, B_x, B_y, C_x, C_y;
 int Perevirka=1, K=1;

do
 {
    printf("KVADRAT\n\n");
    printf("Vedit koordunaty tochky A:\n");
    VvidKoordynat (&A_x,&A_y);
    printf("Vedit koordunaty tochky B:\n");
    VvidKoordynat (&B_x,&B_y);
	printf("Vedit koordunaty tochky C:\n");
	VvidKoordynaty_C (&C_x,&C_y, A_x, A_y, B_x, B_y);

	Point A = {A_x,A_y};
	Point B = {B_x,B_y};
	Point C = {C_x,C_y};
	Point D = {(A_x+C_x)-B_x,(A_y+C_y)-B_y};

	Kvadrat ABCD={&A, &B, &C, &D};

	addElement(theArray, &ABCD);
	printf("Prodovgyty - 1; Vyjty -0?\n");
	scanf("%d",&Perevirka);
	K++;
 }while(Perevirka==1 && K<=5);

	FILE *theFile = fopen("D:/test.json", "a+");

	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);

	freeArray(theArray);

	printf("\nKinets! Perevirte stvorenyj fajl!\n");

	return 0;
}
