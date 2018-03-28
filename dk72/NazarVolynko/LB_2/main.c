#include "dk_sort.h"

int main()
{
float TimeStart,TimeStop;
int size=0;
char * c = loadFile("d:\\-=Navchannya=-\\informatuka 2\\LB_2\\lab_2.txt" , &size);

printf("Sortuvanna!!!\n");

TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_bulbashka(c, size);
TimeStop = clock()/(float)CLOCKS_PER_SEC;

printf("\nSortuvanna bulbashkoj: %f \n", TimeStop-TimeStart);

char * a = loadFile("d:\\-=Navchannya=-\\informatuka 2\\LB_2\\lab_2.txt" , &size);

TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_vstavka(a, size);
TimeStop = clock()/(float)CLOCKS_PER_SEC;

printf("\nSortuvanna vstavkoj: %f \n", TimeStop-TimeStart);

char * d = loadFile("d:\\-=Navchannya=-\\informatuka 2\\LB_2\\lab_2.txt" , &size);

TimeStart = clock()/(float)CLOCKS_PER_SEC;
sort_vybora(d, size);
TimeStop = clock()/(float)CLOCKS_PER_SEC;

printf("\nSortuvanna vyborom: %f \n", TimeStop-TimeStart);

zapys_sortirovky_v_fajl(c, size, "b.txt");
zapys_sortirovky_v_fajl(a, size, "s.txt");
zapys_sortirovky_v_fajl(d, size, "d.txt");

free(c);
free(a);
free(d);

return 0;
}
