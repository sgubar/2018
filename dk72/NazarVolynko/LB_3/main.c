#include "dk_sort.h"

int main(int argc, const char * argv[])
{
float TimeStart,TimeStop;
int size=0,nomer=0;
char symvol;
char * sortuvanna_shell = loadFile("d:\\-=Navchannya=-\\informatuka 2\\LB_3\\lab_3.txt" , &size);

printf("Sortuvanna!!!\n");

TimeStart = clock()/(float)CLOCKS_PER_SEC;
shellSort(sortuvanna_shell, size);
TimeStop = clock()/(float)CLOCKS_PER_SEC;
printf("\nSortuvanna shellom: %f secund!\n", TimeStop-TimeStart);
printf("\nSortuvanna zakincheno!\n");
printf("\nVvedit sumvol dla poshuku: ");
scanf("%c",&symvol);

TimeStart = clock()/(float)CLOCKS_PER_SEC;
nomer = linijnyj_poshuk(sortuvanna_shell, symvol, size);
TimeStop = clock()/(float)CLOCKS_PER_SEC;

if(nomer==-1)
{
    printf("\nMasyv ne mistyt shykanogo symvola!\n");
}
else
{
    printf("\nShukanyj symvol v masyvi je pid nomerom: %d \n", nomer);
}

printf("\nLinijnyj poshuk: %f secund!\n", TimeStop-TimeStart);
zapys_sortirovky_v_fajl(sortuvanna_shell, size, "shell.txt");
printf("\nPereglante stvorenyj fajl!!!:)\n");

free(sortuvanna_shell);

return 0;
}
