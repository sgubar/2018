#include <stdio.h>
#include "dk_square.h"
#include "dk_square_array.h"
#include "Math.h"

int main(int argc, const char * argv[])

{
	
	
	int xA, yA, xB, yB, xC, yC, xD, yD;
	printf("enter the coordinates of point A(x,y):");
	scanf("%d,%d",&xA,&yA);
	printf("enter the coordinates of point B(x,y):");
	scanf("%d,%d",&xB,&yB);
	printf("enter the coordinates of point C(x,y):");
	scanf("%d,%d",&xC,&yC);
	while(pow(xA-xB,2)+pow(yA-yB,2)+pow(xC-xB,2)+pow(yC-yB,2)!=pow(xA-xC,2)+pow(yA-yC,2) ||
            pow(xA-xB,2)+pow(yA-yB,2)!=pow(xC-xB,2)+pow(yC-yB,2))
    {
      	printf("incorrectly entered data !! try again ..\n") ; 
		printf("enter the coordinates of point C(x,y):");
		scanf("%d,%d",&xC,&yC);    	
	}
	xD=(xA+xC)-xB;
    yD=(yA+yC)-yB;
    

	SquareArray *theArray = createArray(10);
	
    
	Point A = {xA,yA};
	Point B = {xB,yB};
	Point C = {xC,yC};
	Point D = {xD,yD};
	
	Square *ABCD = createSquare(&A, &B, &C, &D);
	addElement(theArray, &ABCD);
	
	
	FILE *theFile = fopen("Users\valentin\Desktop\test.json", "a+");
	
	writeArrayToJSON(theFile, theArray);
	
	fflush(theFile);
	fclose(theFile);
	
	freeArray(theArray);
	// insert code here...
	printf("code finished work...\n");

	destroySquare(ABCD);
	return 0;
}
