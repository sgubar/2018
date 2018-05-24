#include "dru_dz.h"

Fig *createFig(Point *A, Point *B, Point *C)
{
	Fig *result=NULL;
	if(NULL!=A && NULL!=B && NULL!=C)
	{
		result=(Fig *)malloc(sizeof(Fig));
		if(NULL!=result)
		{
			result->A=A;
			result->B=B;
			result->C=C;
		}
	}
	return result;
}

void destroyFig(Fig *aFig)
{
	if (NULL != aFig)
	{
		free(aFig->A);
		free(aFig->B);
		free(aFig->C);
		
		free(aFig);
	}
}

Param *enterParam(Fig *aFig)
{
	Param *result=NULL;
	if(NULL!=aFig->A && NULL!=aFig->B && NULL!=aFig->C)
	{
		result=(Param *)malloc(sizeof(Param));
		
		float temp_aX=aFig->C->x - aFig->A->x, 
		temp_aY=aFig->C->y - aFig->A->y, 
		temp_bX=aFig->B->x - aFig->C->x, 
		temp_bY=aFig->B->y - aFig->C->y, 
		temp_cX=aFig->A->x - aFig->B->x,  
		temp_cY=aFig->A->y - aFig->B->y;
		
		float temp_a=sqrt(temp_aX*temp_aX+temp_aY*temp_aY), 
		temp_b=sqrt(temp_bX*temp_bX+temp_bY*temp_bY), 
		temp_c=sqrt(temp_cX*temp_cX+temp_cY*temp_cY);
		
		if(temp_a<0) temp_a*=-1;
		if(temp_b<0) temp_b*=-1;
		if(temp_c<0) temp_c*=-1;
		
		if(temp_a==0 || temp_b==0 || temp_c==0) 
		{
			printf("Error. The two points coincide\n");
			result=NULL;
		}
		else
		{
			if(temp_b+temp_c<=temp_a || temp_a+temp_c<=temp_b || temp_b+temp_a<=temp_c)
			{
				printf("Error. All points lie on one straight line\n");
				result=NULL;
			}
			else 
			{
				float P=temp_a+temp_b+temp_c;
				float p=P/2;
				result->S=sqrt(p*(p-temp_a)*(p-temp_b)*(p-temp_c));
				
				result->a=temp_a;
				result->b=temp_b;
				result->c=temp_c;
				
			}
		}
		
	}
	return result;
}

void printFig(Fig *aFig)
{
	if(NULL!=aFig->A && NULL!=aFig->B && NULL!=aFig->C)
	{
		printf("[Fig]:\nA(%d,%d)\nB(%d,%d)\nC(%d,%d)\n\n\n", aFig->A->x, aFig->A->y, aFig->B->x, aFig->B->y, aFig->C->x, aFig->C->y);
	}
}

void printParam(Param *aParam)
{
	if(NULL!=aParam)
	{
		printf("[Param]:\na=%f;\nb=%f;\nc=%f;\nS=%f;\n\n\n", aParam->a, aParam->b, aParam->c, aParam->S);
	}
}

void writePointToJSON(FILE *aFile, Point *aPoint)
{
	if (NULL == aPoint || NULL == aFile)
	{
		return ;
	}
	fprintf(aFile, "{%d, %d}", aPoint->x, aPoint->y);
}

void writeFigToJSON(FILE *aFile, Fig *aFig)
{
	if (NULL == aFig || NULL == aFile)
	{
		return ;
	}

	fprintf(aFile, "{\n\"A\" : ");
	writePointToJSON(aFile, aFig->A);
	fprintf(aFile, ", \n\"B\" : ");
	writePointToJSON(aFile, aFig->B);
	fprintf(aFile, ", \n\"C\" : ");
	writePointToJSON(aFile, aFig->C);
	fprintf(aFile, "}\n");
}
