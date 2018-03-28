#include "dk_rect.h"

void print_coord_point(ppoint pn_rect, int pn_point) 												//print coordinates of figure in format: (x,y)
{
	printf("(%.2f,%.2f)  \n", pn_rect->points[pn_point]->x, pn_rect->points[pn_point]->y);
}

void enter_coord_point(ppoint en_rect, int en_point) 												//get coordinates of figure in format: x y
{
	scanf("%f %f", &en_rect->points[en_point]->x, &en_rect->points[en_point]->y);
}

float p_lenght(float p_Ax, float p_Ay, float p_Bx, float p_By) 										//return the length of side of figure
{
	return sqrt((p_Bx-p_Ax)*(p_Bx-p_Ax)+(p_By-p_Ay)*(p_By-p_Ay));
};

float ret_point(ppoint r_rect, int rpoint, char rtoc)
{
	if(rtoc == 'x') return r_rect->points[rpoint]->x;
	else return r_rect->points[rpoint]->y;
}

ppoint enter_data() 																				//get coordinates of figures and check it for right
{
	
	ppoint temp_rect = malloc(sizeof(r_point));
	
	for(int i = 0; i < 4;i++) temp_rect->points[i] = malloc(sizeof(pnt));
	
	printf("Enter a coordinates of rectangle: \n");
	
	for(int i = 0; i < 4; i++)
	{
		printf("%dth ", i);
		enter_coord_point(temp_rect, i);
	}
	
																									//checking for a right entering temp_rect->points[0]->x
	while(p_lenght(ret_point(temp_rect,0,'x'), ret_point(temp_rect,0,'y'), ret_point(temp_rect,2,'x'), ret_point(temp_rect,2,'y')) 
				!= p_lenght(ret_point(temp_rect,1,'x'), ret_point(temp_rect,1,'y'), ret_point(temp_rect,3,'x'), ret_point(temp_rect,3,'y')))
	{
		printf("ERR((( ->Invalid coordinates<-\nEnter a coordinates of rectangle: \n");
	
		for(int i = 0; i < 4; i++)
		{
			printf("%dth ", i);
			enter_coord_point(temp_rect, i);
		}	
	}
	
	printf("\nThe rectangle is right))\n\n");
	
	return temp_rect;
};


void print_param(ppoint par_rect)
{
	float AB, BC;
	
	AB = p_lenght(ret_point(par_rect,0,'x'), ret_point(par_rect,0,'y'), ret_point(par_rect,1,'x'), ret_point(par_rect,1,'y'));
	BC = p_lenght(ret_point(par_rect,1,'x'), ret_point(par_rect,1,'y'), ret_point(par_rect,2,'x'), ret_point(par_rect,2,'y'));
	
	printf("Parameters of rectangle:\n");
	
	printf("    ****Coordinates****\n");
	
	for(int i = 0; i < 4; i++) 
	{
		printf("%dth = ", i);
		print_coord_point(par_rect, i);
	}
		
	printf("\n");

	printf("   ****Length of sides****\nAB = CD = %.2f\nBC = AD = %.2f\n\n", AB, BC);
	
	printf("   ****Square****\nS = %.2f sq. un.\n", AB*BC);
	
};


void deleting(ppoint del_rect)
{
	for(int i = 0; i < 4; ++i) free(del_rect->points[i]); 
	
	free(del_rect);
	//printf("\nDeleting is succesfull!))\n");
}




