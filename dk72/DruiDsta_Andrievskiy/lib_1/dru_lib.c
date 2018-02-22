#include <stdio.h>
#include "dru_lib.h"

double algeb_summ_fac(double up, double down)
{
	double result=0, fac;
	if(up<down) 
	{
		printf("Ïîìèëêà\n");
	}
	else
	{
		for(down; down!=up+1; down++) 
		{
			result=result+factorial(down);
		}
	
	}
	
	return result;
}

double factorial(double fac)
{
	int i;
	double result=1;
	if(fac==0) return 0;
	else
	{
		for(i=1; i!=fac+1; i++)
		{
			result=result*i;
		}
	return result;
	}

}


double drib(double a, double b, double c)
{
	double temp_chis, temp_c_kv, temp_znam, result, form, algSumm, fac;
	temp_chis=a+b;
	temp_znam=b+c*c;
	if(temp_znam==0)
	{
		printf("Ïîìèëêà\n");
	}
	else
	{
	result=temp_chis/temp_znam;
	}
	return result;
}

double formula(double a, double b, double c, double d)
{
	double form=0, temp_drib, algSumm;
	temp_drib=drib(a, b, c);
	algSumm=algeb_summ_fac(b, d);
	
	if(temp_drib==0||algSumm==0)
	{
		printf("Ïîìèëêà\n");
	}
	else
	{
	form=temp_drib+algSumm;
	
	}
	return form;
}
