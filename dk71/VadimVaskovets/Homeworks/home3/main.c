//
//  main.c
//  dz3
//
//  Created by Vadym Vaskovets on 3/29/18.
//  Copyright © 2018 Vadym Vaskovets. All rights reserved.
//
#include <stdio.h>
#include "dk_tool.h"
#include "dk_triangle_array.h"
#include <locale.h>

int main(int argc, const char * argv[])
{
	setlocale(LC_ALL, "RUS");
	int A_x, A_y, B_x, B_y, C_x, C_y, i, k;
	triangleArray *theArray = createArray(5);
	printf("Ââåäèòå êîëè÷åñòâî òðåóãîëüíèêîâ: ");
	scanf("%d", &k);
	for(i=1; i<=k; i++)
	 {
	 	printf("\n\tÂÂåäèòå êîîðäèíàòû %d òðèóãîëüíèêà\n", i);
	 	
	    enter(&A_x,&A_y);
	 	enter(&B_x,&B_y);
	 	enter(&C_x,&C_y);
	 	   
		Point A = {A_x,A_y};
		Point B = {B_x,B_y};
		Point C = {C_x,C_y};
	 	
		triangle ABC = {&A, &B, &C};
	
		addElement(theArray, &ABC);
	 }
	 
	 
	FILE *theFile = fopen("D:/test.json", "a+");
	
	writeArrayToJSON(theFile, theArray);
	
	fflush(theFile);
	fclose(theFile);
	freeArray(theArray);
	
	return 0;
}
