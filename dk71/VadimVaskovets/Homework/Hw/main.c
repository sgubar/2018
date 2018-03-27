//
//  main.c
//  dz2
//
//  Created by Vadym Vaskovets on 3/27/18.
//  Copyright © 2018 Vadym Vaskovets. All rights reserved.
//
#include <stdio.h>
#include "dk_tool.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	int x1, x2, x3, y1, y2, y3;
		printf("Введите значение координаты Х для точки А = ");
			scanf("%d",&x1);
		printf("Введите значение координаты У для точки А = ");
			scanf("%d",&y1);
		printf("Введите значение координаты Х для точки В = ");
			scanf("%d",&x2);
		printf("Введите значение координаты У для точки В = ");
			scanf("%d",&y2);
		printf("Введите значение координаты Х для точки С = ");
			scanf("%d",&x3);
		printf("Введите значение координаты У для точки С = ");
			scanf("%d",&y3);
	Point A = {x1,y1};
	Point B = {x2,y2};
	Point C = {x3,y3};
	
	triangle *ABC = create_triangle(&A, &B, &C);

	print_triangle(ABC);

	printf("Площадь треугольника ABC = %f\n", flat_triangle(ABC));
	
	destroy_triangle(ABC);
		return 0;
}
