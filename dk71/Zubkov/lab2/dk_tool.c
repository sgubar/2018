
  #include "dk_tool.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h> 


int countElem() {
	int f;
	 	printf("������� ���-�� ���������: ");
    	int result_A;
    		result_A = scanf("%d",&f);

			while(result_A != 1 || (int)f != f  || f < 0)
			{ 	
				printf("\n������� ���-�� ��������� ������: ");
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
		 printf("\n���� ��� ���������� ������: ");
            char *nameIn=(char *)malloc(256);
            scanf("%s",nameIn);
            FILE *fp1=fopen(nameIn,"r");
            while( (fp1=fopen(nameIn,"r")) == 0 )
            {
                printf("\n���� �� ������!\n");
                printf("\n���� ��� ���������� ������: ");
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

			 printf("\n���� ��� ���������� ������: ");
            char *nameOut=(char *)malloc(256);
            scanf("%s",nameOut);
            FILE *fp2=fopen(nameOut,"w");
            for (i = 0; i < f; i++) 
            {
                fprintf(fp2,"%i ",A[i]);     
            }
            fclose(fp2);
            fflush(fp2);
            printf("������ ������� ���������");
}
int* sortBuble(int* A, int f) {
	
	int i,j;
clock_t start = clock();   //����������������������������	
	for(i = 0 ; i < f - 1; i++) { 
       // ���������� ��� �������� ��������.
       for(j = 0 ; j < f - i - 1 ; j++) {  
           if(A[j] > A[j+1]) {           
              // ���� ��� ���� � ������������ �������, ��  
              //  ������ �� �������. 
              int tmp = A[j];
              A[j] = A[j+1] ;
              A[j+1] = tmp; 
           }
        }
         clock_t end = clock();   double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
		 printf("����� ����������: %f sec\n", seconds);////////����������������
    }
    return A;
}
    int* sortPush(int* A, int f) {
	
	int pass, j, hold;
clock_t start = clock();//���������������������������������������
	for (pass = 0; pass < f-1; pass++){
		for (j = pass+1; j < f; j++){
			if (A[pass]>A[j]){
				hold = A[j];
				A[j] = A[pass];
				A[pass] = hold;
			}
		}
		clock_t end = clock();   double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
		 printf("����� ����������: %f sec\n", seconds);////////����������������
	}

    return A;
}
int* sortChoose(int* A, int f) {
	
	int i,j;
	clock_t start = clock();//���������������������������������������
	for (i = 0; i < f - 1; i++) {
/* ������������� ��������� �������� ������������ ������� */
        int min_i = i;
	/* ������� ������ ������������ �������� */
	for (j = i + 1; j < f; j++) {
		if (A[j] < A[min_i]) {
			min_i = j;
		}
	}
	/* ������ �������� ������� */
	int temp = A[i];
	A[i] = A[min_i];
	A[min_i] = temp;
	clock_t end = clock();   double seconds = (double)(end - start) / CLOCKS_PER_SEC; 
		 printf("����� ����������: %f sec\n", seconds);////////����������������
}

    return A;
}
int* sortInterface(int* A, int f) {
	int finish = 0;
	int var;
	while(finish != 1)
	{ 	
		printf("�����������: ");
		printf("\n1. ���������; ");
		printf("\n2. �������; ");
		printf("\n3. ��������; ");;
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
	
	while(finish != 1) //�������� �� ������������ �����
	{ 	
		printf("����: ");
		printf("\n1. �������/������������ ������ � �������; ");
		printf("\n2. ����������� ������ � �������; ");
		printf("\n3. �������� � ���� ������ � �������; ");
		printf("\n4. �������� �� ����� ������ � �������; ");
		printf("\n5. ������� ������ � ������� �� �����; ");
		printf("\n6. �����;\n");
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
                printf("\n������ ��� ������ ����");
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
