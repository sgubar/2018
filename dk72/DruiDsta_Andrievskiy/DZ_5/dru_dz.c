#include "dru_dz.h"

Point *copyPointWithPoint(Point *aPoint);

triangle *create_triangle(Point *A, Point *B, Point *C)
{
	triangle *theResult = NULL;

	if (NULL != A && NULL != B && NULL != C)
	{
		theResult = (triangle *)malloc(sizeof(triangle));
		if (NULL != theResult)
		{
			theResult->A = copyPointWithPoint(A);
			theResult->B = copyPointWithPoint(B);
			theResult->C = copyPointWithPoint(C);
		}
	}
	theResult->S=S_triangle(A, B, C);
	return theResult;
}

float S_triangle(Point *A, Point *B, Point *C)
{
	float result = 0;
		
		float temp_aX=C->x - B->x, 
		temp_aY=C->y - B->y, 
		temp_bX=A->x - C->x, 
		temp_bY=A->y - C->y, 
		temp_cX=A->x - B->x,  
		temp_cY=A->y - B->y;
		
		float temp_a=sqrt(temp_aX*temp_aX+temp_aY*temp_aY), 
		temp_b=sqrt(temp_bX*temp_bX+temp_bY*temp_bY), 
		temp_c=sqrt(temp_cX*temp_cX+temp_cY*temp_cY);
		
		if(temp_a<0) temp_a*=-1;
		if(temp_b<0) temp_b*=-1;
		if(temp_c<0) temp_c*=-1;
		
		if(temp_a == 0 || temp_b == 0 || temp_c == 0) 
		{
			printf("Error. The two points coincide\n");
			return result;
		}
		else
		{
			if(temp_b + temp_c == temp_a || temp_a + temp_c == temp_b || temp_b + temp_a == temp_c)
			{
				printf("Error. All points lie on one straight line\n");
				return result;
			}
			else 
			{
				float P=temp_a+temp_b+temp_c;
				float p=P/2;
				result=sqrt(p*(p-temp_a)*(p-temp_b)*(p-temp_c));
			}
		}
		
	return result;

}

void print_triangle(triangle *atriangle)
{
	if (NULL != atriangle)
	{
		printf ("\tÊîîðäèíàòû òî÷åê :\n\n \t\tA(%d,%d)\n  \t\tB(%d,%d)\n  \t\tC(%d,%d)\n\n",
					atriangle->A->x, atriangle->A->y,
					atriangle->B->x, atriangle->B->y,
					atriangle->C->x, atriangle->C->y);
	}
}

Point *copyPointWithPoint(Point *aPoint)
{
	Point *theResult = (Point *)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}

	return theResult;
}

void destroy_triangle(triangle *atriangle)
{
	if (NULL != atriangle)
	{
		free(atriangle->A);
		free(atriangle->B);
		free(atriangle->C);
		free(atriangle);
	}
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void writetriangleToJSON(FILE *aFile, triangle *atriangle)
{
	if (NULL == atriangle || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, atriangle->A);
	fprintf(aFile, ",\n\"B\" : ");
	writePointToJSON(aFile, atriangle->B);
	fprintf(aFile, ",\n\"C\" : ");
	writePointToJSON(aFile, atriangle->C);
	fprintf(aFile, "\n\"S\" : %f\n}", atriangle->S);
}


 void enter(int *X, int *Y)
{
    printf("x=");
    scanf("%d",X);
    printf("y=");
    scanf("%d",Y);
}
