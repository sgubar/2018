
  #include "dk_tool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h> 


int countElem() {
	int f;
	 	printf("Ââåäèòå êîë-âî ýëåìåíòîâ: ");
    	int result_A;
    		result_A = scanf("%d",&f);

			while(result_A != 1 || (int)f != f  || f < 0)
			{ 	
				printf("\nÂâåäèòå êîë-âî ýëåìåíòîâ çàíîâî: ");
	   			result_A = scanf("%f",&f);
	   			scanf("%*[^\n]");   	
			}
	return f;
}
int* input(int f)
{
	srand(time(NULL));
    int*Arr;


	int p;
    Arr=(int*)malloc(sizeof(int)*f);
    for( p=0; p<f; p++)
    {
        Arr[p]=rand() % 100;
    }

    printf("\n");
   
    return Arr;
}
void print(int* arr, int f) 
{
	int p;

  for( p=0; p<f; p++)
    {
        printf("%d ", arr[p]);
    }
    printf("\n");
}

int* fromFile()
{
		int* A;
		int i,f;
		 printf("\nÔàéë äëÿ ñ÷èòûâàíèÿ äàííûõ: ");
            char *nameIn=(char *)malloc(256);
            scanf("%s",nameIn);
            FILE *fp1=fopen(nameIn,"r");
            while( (fp1=fopen(nameIn,"r")) == 0 )
            {
                printf("\nÔàéë íå íàéäåí!\n");
                printf("\nÔàéë äëÿ ñ÷èòûâàíèÿ äàííûõ: ");
                scanf("%s",nameIn);
            }
           f = countElem();
			  A = (int*)malloc(sizeof(int)*f);
            for (i=0;i<f;i++)
            {
                fscanf (fp1,"%i",&A[i]);
          
            }
           
            fflush(fp1);
            fclose(fp1);
            return A;
}
void inFile(int* A, int f) {
	int i;

			 printf("\nÔàéë äëÿ ñîõðàíåíèÿ äàííûõ: ");
            char *nameOut=(char *)malloc(256);
            scanf("%s",nameOut);
            FILE *fp2=fopen(nameOut,"w");
            for (i = 0; i < f; i++) 
            {
                fprintf(fp2,"%i ",A[i]);     
            }
            fclose(fp2);
            fflush(fp2);
            printf("Äàííûå óñïåøíî ñîõðàíåíû");
}
int* sortBuble(int* A, int f) {
	
	int i,j;
clock_t start = clock();   //ÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀ	
	for(i = 0 ; i < f - 1; i++) { 
       
       for(j = 0 ; j < f - i - 1 ; j++) {  
           if(A[j] > A[j+1]) {           
            
              int tmp = A[j];
              A[j] = A[j+1] ;
              A[j+1] = tmp; 
           }
        }
         clock_t end = clock();   double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
		 printf("Âðåìÿ âûïîëíåíèÿ: %f sec\n", seconds);////////àààààààààààààààà
    }
    return A;
}
    int* sortPush(int* A, int f) {
	
	int pass, j, hold;
clock_t start = clock();//ÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀà
	for (pass = 0; pass < f-1; pass++){
		for (j = pass+1; j < f; j++){
			if (A[pass]>A[j]){
				hold = A[j];
				A[j] = A[pass];
				A[pass] = hold;
			}
		}
		clock_t end = clock();   double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
		 printf("Âðåìÿ âûïîëíåíèÿ: %f sec\n", seconds);////////àààààààààààààààà
	}

    return A;
}
int* sortChoose(int* A, int f) {
	
	int i,j;
	clock_t start = clock();//ÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀà
	for (i = 0; i < f - 1; i++) {
        int min_i = i;

	for (j = i + 1; j < f; j++) {
		if (A[j] < A[min_i]) {
			min_i = j;
		}
	}
	
	int temp = A[i];
	A[i] = A[min_i];
	A[min_i] = temp;
	clock_t end = clock();   double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
		 printf("Âðåìÿ âûïîëíåíèÿ: %f sec\n", seconds);////////àààààààààààààààà
}

    return A;
}
int* sortInterface(int* A, int f) {
	int finish = 0;
	int var;
	while(finish != 1)
	{ 	
		printf("Ñîðòèðîâàòü: ");
		printf("\n1. Ïóçûðüêîì; ");
		printf("\n2. Âûáîðîì; ");
		printf("\n3. Âñòàâêîé; ");;
	   	scanf("%d",&var); 
		switch (var) {
		case 1:
		A = sortBuble(A,f);
			finish = 1;
  		 break; 
  		 case 2:
  		 	A = sortChoose(A,f);
			finish = 1;
  		 break;
		 case 3:
			A = sortPush(A,f);
			finish = 1;
    
  		 break;

		default:
 
  		break;
		} 	
	}
	return A;
	
}
void interface(void) {
	int finish = 0;
	int b_in_file = 0;
	int var = 0;
	int q = 0;
	int* A;
		int i;
	
	int f;
	
	while(finish != 1)
	{ 	
		printf("Ìåíþ: ");
		printf("\n1. Ñîçäàòü/ïåðåçàïèñàòü ìàññèâ ñ äàííûìè; ");
		printf("\n2. Ñîðòèðîâàòü ìàññèâ ñ äàííûìè; ");
		printf("\n3. Çàïèñàòü â ôàéë ìàññèâ ñ äàííûìè; ");
		printf("\n4. Ïîëó÷èòü èç ôàéëà ìàññèâ ñ äàííûìè; ");
		printf("\n5. Âûâåñòè ìàññèâ ñ äàííûìè íà ýêðàí; ");
		printf("\n6. Âûõîä;\n");
	   	scanf("%d",&var); 
		switch (var) {
		case 1:
			
			 
  			f= countElem();
  			A = input(f);
  			q++;
  			system("cls");
  			print(A,f);
  			getch();
  		 break; 
  		 case 2:
  		 A = sortInterface(A, f);
  		 system("cls");
  			print(A,f);
  			getch();
  		 break;
		 case 3:
				if( q == 0 )
            {
                printf("\nÄàííûõ äëÿ çàïèñè íåòó");
                getch();
                continue;
            }
            inFile(A,f);
            getch();
            system("cls");
    
  		 break;
  		 case 4:
  		 	A = fromFile();
  		  system("cls");
           	print(A,f);
            q++;
            getch();
  		 break;
		case 5:
			system("cls");
			print(A,f);
			getch();
  		 break;
		case 6:
			finish = 1;
  		 break;
		default:
 
  		break;
		} 	
	}
	
}
