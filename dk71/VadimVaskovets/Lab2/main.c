#include <stdio.h>
#include "dk_tool.h"
#include <time.h>
#include <locale.h>

int main()
	{
		setlocale(LC_ALL, "RUS");
    	long SIZE;
    	int Choose;
    		printf("Ïðîãðàììà ðàáîòàåò òîëüêî ñ öåëûìè ÷èñëàìè"
            	       "Ââåäèòå ðàçìåð ìàññèâà - ");

    	SIZE = ValueCheck();
    	int i, a[SIZE];
   		Random(a, SIZE);
    	printArrToFile(a, SIZE, "unsortedARR.txt");

    	printf("Âûáåðèòå âàðèàíò ñîðòèðîâàíèÿ:\n"
        	           "Ââåäèòå '1' Äëÿ ñîðòóâàííÿ áóëüáàøêîþ.\n"
            	       "Ââåäèòå '2' Äëÿ ñîðòóâàííÿ âêëþ÷åííÿì.\n"
                	   "Ââåäèòå '3' Äëÿ ñîðòóâàííÿ âèáîðîì. \n"
                	   "Âàø âûáîð :  ");
    	Choose = ValueCheck();
   		while(Choose != 1 && Choose !=2 && Choose !=3)
    {
        printf("Ââåäèòå çíà÷åíèå çàíîâî!\n");
        Choose = ValueCheck();
    }

    switch(Choose)
    	{
        	case 1:
            	printf("Âû âûáðàëè ñîðòèðîâêó 1\n");
            	bubbleSort(a, SIZE);
            	break;
        	case 2:
            	printf("Âû âûáðàëè ñîðòèðîâêó 2\n");
            	insertionSort(a, SIZE);
            	break;
        	case 3:
            	printf("Âû âûáðàëè ñîðòèðîâêó 3\n");
        		selectionSort(a, SIZE);
            	break;

    	}
    		printArrToFile(a, SIZE, "sortedARR.txt");
    		return 0;
	}
