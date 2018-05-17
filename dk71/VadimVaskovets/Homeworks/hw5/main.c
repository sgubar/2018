#include <stdio.h>
#include <locale.h>
#include "dk_triangle.h"
#include "dk_triangle_array.h"

int main(int argc, const char * argv[])
{
	setlocale(LC_ALL, "RUS");
	int k, i;
	int A_x, A_y, B_x, B_y, C_x, C_y;
	float search;
	int position;
	triangleArray *theArray = createArray(5);
	printf("Введите количество триугольников\t");
	scanf("%d", &k);
	for(i=1; i<=k; i++)
	 {
	 	printf("\n\tВведите координаты %d триугольника\n", i);
	 	
	    enter(&A_x,&A_y);
	 	enter(&B_x,&B_y);
	 	enter(&C_x,&C_y);
	 	   
		Point A = {A_x,A_y};
		Point B = {B_x,B_y};
		Point C = {C_x,C_y};
	 	
		triangle ABC = {&A, &B, &C};
	
		addElement(theArray, &ABC, flat_triangle(&ABC));
	 }
	 
	 
	FILE *theFile = fopen("D:/test.json", "a");
	
	writeArrayToJSON(theFile, theArray);
	
	fflush(theFile);
	fclose(theFile);
	

	for(i=0; i<theArray->count; i++)
	{
		printf("%f\n", theArray->flat[i]);
	}
	
	quick_sort(theArray, 0, theArray->count-1);


	FILE *theFile2 = fopen("D:/test2.json", "a");

	writeArrayToJSON(theFile2, theArray);

	fflush(theFile2);
	fclose(theFile2);
	
	while(1)
		{
		printf("\tВведите площадь треугольника:"); 
		scanf("\n%f", &search);
		position = line_search(theArray, search);
		printf("\nПозиция треугольника = %d\n\n", position);
		}
	
	freeArray(theArray);
	
	return 0;
}
