#include "dk_sort.h"

int main()
{
float TimeStart,TimeStop;
int size=0;
char * bulbashka = loadFile("d:\\-=Navchannya=-\\informatuka 2\\LB_2\\lab_2.txt" , &size);

printf("Sortuvanna!!!\n");

TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_bulbashka(bulbashka, size);
TimeStop = clock()/(float)CLOCKS_PER_SEC;

printf("\nSortuvanna bulbashkoj: %f \n", TimeStop-TimeStart);

char * vstavka = loadFile("d:\\-=Navchannya=-\\informatuka 2\\LB_2\\lab_2.txt" , &size);

TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_vstavka(vstavka, size);
TimeStop = clock()/(float)CLOCKS_PER_SEC;

printf("\nSortuvanna vstavkoj: %f \n", TimeStop-TimeStart);

char * vybor = loadFile("d:\\-=Navchannya=-\\informatuka 2\\LB_2\\lab_2.txt" , &size);

TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_vybora(vybor, size);
TimeStop = clock()/(float)CLOCKS_PER_SEC;

printf("\nSortuvanna vyborom: %f \n", TimeStop-TimeStart);

zapys_sortirovky_v_fajl(bulbashka, size, "bulbashka.txt");
zapys_sortirovky_v_fajl(vstavka, size, "vstavka.txt");
zapys_sortirovky_v_fajl(vybor, size, "vybor.txt");

free(bulbashka);
free(vstavka);
free(vybor);

return 0;
}
