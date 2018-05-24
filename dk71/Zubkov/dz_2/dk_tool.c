#include "dk_tool.h"
#include <math.h>
Elips *createElips(Dot *A, Dot *B, Dot *C, Dot *D, Dot *middle) 
{
    Elips *theResult = NULL; 

    if(A != NULL && B != NULL && C != NULL && D != NULL && middle != NULL) 
    {
       if(abs(A->x) == abs(C->x) && abs(B->y) == abs(D->y))   
       {
            theResult = ( Elips* )malloc(sizeof(Elips));
            if(theResult != NULL)
            {
                theResult->A = A;
                theResult->B = B;
                theResult->C = C;
                theResult->D = D;
                theResult->middle = middle;
            }
        }

    }

    return theResult;
}

void destroyElips(Elips *aElips)
{
    if(aElips != NULL)
    {
        free(aElips->A);
        free(aElips->B);
        free(aElips->C);
        free(aElips->D);
        free(aElips->middle);
        free(aElips);
    }
}

int ElipsSquare(Elips *aElips)
{
    int theResult = 0;

    if(aElips != NULL)
    {
        int aSide = (int)sqrt(pow(aElips->C->x - aElips->middle->x, 2)+pow(aElips->C->y - aElips->middle->y ,2));
        int bSide = (int)sqrt(pow(aElips->B->x - aElips->middle->x, 2)+pow(aElips->B->y - aElips->middle->y ,2));
        theResult = 3.14*aSide * bSide;
    }

    return theResult;
}
Dot innerPointer () {
     int f,f2;
      int result_A,result_B;
    		result_A = scanf("%d",&f);

			while(result_A != 1 || (int)f != f)
			{ 	
				printf("\nВведите заново: ");
	   			result_A = scanf("%f",&f);
	   			scanf("%*[^\n]");   	
			}
			result_B = scanf("%d",&f2);

			while(result_B != 1 || (int)f2 != f2)
			{ 	
				printf("\nВведите заново: ");
	   			result_B = scanf("%f",&f2);
	   			scanf("%*[^\n]");   	
			}
		
    Dot temp = {f, f2};
    return temp;
}
void print(Dot *A, Dot *B, Dot *C, Dot *D, Dot *middle, int square) {
    printf("A.x = %d\n", A->x);
    printf("A.y = %d\n", A->y);
    printf("B.x = %d\n", B->x);
    printf("B.y = %d\n", B->y);
    printf("C.x = %d\n", C->x);
    printf("C.y = %d\n", C->y);
    printf("D.x = %d\n", D->x);
    printf("D.y = %d\n", D->y);

        printf("Площадь элипса = %d\n", square);
   
}
void interface(void) {
	int finish = 0;
	int b_in_file = 0;
	int var = 0;
	int q = 0;

		int i;
	int param;
	int f;
	int result_B;
	Elips *elips_new;
	Dot A,B,C,D,middle;
	while(finish != 1)
	{ 	
		printf("Меню: ");
		printf("\n1. Создать элипс; ");
		printf("\n2. Вывести параметры элипса; ");
		printf("\n3. Удалить фигуру; ");
		printf("\n4. Выход;\n");
	   	scanf("%d",&var); 
		switch (var) {
		case 1:
		
			printf("Использовать стандартные параметры(1/2)?: ");
		scanf("%d",&param);
		result_B = scanf("%d",&param);

			while(result_B != 1 || (int)param != param || (param != 1 && param != 2))
			{ 	
				printf("\nВведите заново: ");
	   			result_B = scanf("%f",&param);
	   			scanf("%*[^\n]");   	
			}
		if(param == 1) {
			A.x = -2;
			A.y = 0;
			B.x = 0;
			B.y = 1;
			C.x = 2;
			C.y = 0;
			D.x = 0;
			D.y = -1;
			middle.x = 0;
			middle.y = 0;
      elips_new = createElips(&A, &B, &C, &D,&middle);

    if(elips_new == NULL)
    {
        printf("Ошибка создания\n");
    }
   
		}
	if(param == 2) {

	    	printf("Введите координаты точки A: ");
  			A = innerPointer();
  			printf("Введите координаты точки B: ");
   B = innerPointer();
    printf("Введите координаты точки C: ");
     C = innerPointer();
    printf("Введите координаты точки D: ");
    D = innerPointer();
    printf("Введите координаты центральной точки: ");
    middle = innerPointer();
	      elips_new = createElips(&A, &B, &C, &D,&middle);

    if(elips_new == NULL)
    {
        printf("Ошибка создания\n");
    }
   
	}
	  

  

    
  			system("cls");
  		printf("Готово\n");
  			getch();
  		 break; 
  		 case 2:
  		 	system("cls");
  		
  			
  	print(&A, &B, &C, &D,&middle,ElipsSquare(elips_new));
  	getch();
  		 break;
		 case 3:
		destroyElips(elips_new);
		system("cls");
  		 break;
  	
		case 4:
			finish = 1;
  		 break;
		default:
 
  		break;
		} 	
	}
	
}
