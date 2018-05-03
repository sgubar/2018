#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

int main(int argc, char *argv[]) {
	
	float TimeStart,TimeStop;
	int size=0;
	size = enter_size_array();
	char *array = malloc (sizeof (char) * (size+1));
	enter_data_to_array(array, size);
	write_array_in_fail(array, size, "lab2.txt");

	char * bulbashka = loadFile("lab2.txt" , size);

	printf("sorting......\n");

	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	sort_bulbashka(bulbashka, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;

	printf("\n sorting bulbashkoj: %f \n", TimeStop-TimeStart);

	char * vstavka = loadFile("lab2.txt" , size);

	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	sort_vstavka(vstavka, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;

	printf("\n sorting vstavkoj: %f \n", TimeStop-TimeStart);

	char * vybor = loadFile("lab2.txt" , size);

	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	sort_vybora(vybor, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;

	printf("\n sorting vyborom: %f \n", TimeStop-TimeStart);
	
	write_array_in_fail(bulbashka, size, "bulbashka.txt");
	write_array_in_fail(vstavka, size, "vstavka.txt");
	write_array_in_fail(vybor, size, "vybor.txt");


	free(bulbashka);
	free(vstavka);
	free(vybor);
	free(array);

	return 0;
}
