#include "dk_kvadrat.h"
#include "dk_kvadrat_array.h"


int main(int argc, const char * argv[])
{

    KvadratArray *theArray = createArray(5);

 int A_x, A_y, B_x, B_y, C_x, C_y;
 int Perevirka=1, K=1, nomer;
 float shukanaPloscha;

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

	printf("Ploscha ABCD = %f\n\n", ploschaKvadrat(&ABCD));

	addElement(theArray, &ABCD, ploschaKvadrat(&ABCD));

	printf("Prodovgyty - 1; Vyjty -0?\n");
	scanf("%d",&Perevirka);
	K++;

 }while(Perevirka==1 && K<=5);

    printf("\nVedit ploschu kvadrata dla poshuku: ");
	scanf("%f",&shukanaPloscha);

	nomer = linijnyj_poshuk(theArray, shukanaPloscha);

	if(nomer==-1)
{
    printf("\nMasyv ne mistyt shykanoj ploschi!\n");
}
else
{
    printf("\nShukana ploscha  v masyvi je pid nomerom: %d \n", nomer);
}

	FILE *theFile = fopen("D:/test.json", "a+");

	writeArrayToJSON(theFile, theArray);

	fflush(theFile);
	fclose(theFile);

	quickSort( theArray, 0, theArray->count-1);

	FILE *theFile2 = fopen("D:/test_vidsortovanyj.json", "a+");

	writeArrayToJSON(theFile2, theArray);

	fflush(theFile2);
	fclose(theFile2);

	freeArray(theArray);

	printf("\nKinets! Perevirte stvorenyj fajl!\n");

	return 0;
}



