
#include "dk_rect.h"


float p_lenght(float p_Ax, float p_Ay, float p_Bx, float p_By)
{
	return sqrt((p_Bx-p_Ax)*(p_Bx-p_Ax)+(p_By-p_Ay)*(p_By-p_Ay));
};

ppoint enter_data()
{
	
	ppoint temp_rect = malloc(sizeof(r_point));
	
	temp_rect->points[0] = malloc(sizeof(pnt));
	temp_rect->points[1] = malloc(sizeof(pnt));
	temp_rect->points[2] = malloc(sizeof(pnt));
	temp_rect->points[3] = malloc(sizeof(pnt));
	
	printf("Enter a coordinates of rectangle: \n");
	
	printf("A ");
	scanf("%f %f", &temp_rect->points[0]->x, &temp_rect->points[0]->y);
	printf("B ");
	scanf("%f %f", &temp_rect->points[1]->x, &temp_rect->points[1]->y);
	printf("C ");
	scanf("%f %f", &temp_rect->points[2]->x, &temp_rect->points[2]->y);
	printf("D ");
	scanf("%f %f", &temp_rect->points[3]->x, &temp_rect->points[3]->y);
	
	while(p_lenght(temp_rect->points[0]->x, temp_rect->points[0]->y, temp_rect->points[2]->x, temp_rect->points[2]->y) 
				!= p_lenght(temp_rect->points[1]->x, temp_rect->points[1]->y, temp_rect->points[3]->x, temp_rect->points[3]->y))
	{
		printf("");
		printf("ERR((( ->Invalid coordinates<-\nEnter a coordinates of rectangle: \n");
	
	printf("A ");
	scanf("%f %f", &temp_rect->points[0]->x, &temp_rect->points[0]->y);
	printf("B ");
	scanf("%f %f", &temp_rect->points[1]->x, &temp_rect->points[1]->y);
	printf("C ");
	scanf("%f %f", &temp_rect->points[2]->x, &temp_rect->points[2]->y);
	printf("D ");
	scanf("%f %f", &temp_rect->points[3]->x, &temp_rect->points[3]->y);
		
	}
	
	printf("The rectangle is right))\n");
	
	return temp_rect;
};


void print_param(ppoint par_rect)
{
	float AB, BC;
	
	AB = p_lenght(par_rect->points[0]->x, par_rect->points[0]->y, par_rect->points[1]->x, par_rect->points[1]->y);
	BC = p_lenght(par_rect->points[1]->x, par_rect->points[1]->y, par_rect->points[2]->x, par_rect->points[2]->y);
	
	printf("Parameters of rectangle:\n\n");
	
	printf("    ****Coordinates****\n");
	printf("A = (%.2f,%.2f)  ", par_rect->points[0]->x, par_rect->points[0]->y);
	printf("B = (%.2f,%.2f)\n", par_rect->points[1]->x, par_rect->points[1]->y);
	printf("C = (%.2f,%.2f)  ", par_rect->points[2]->x, par_rect->points[2]->y);
	printf("D = (%.2f,%.2f)\n\n", par_rect->points[3]->x, par_rect->points[3]->y);
	
	printf("   ****Length of sides****\n");
	printf("AB = CD = %.2f ", AB);
	printf("BC = AD =%.2f\n\n", BC);
	
	printf("   ****Square****\n");
	printf("S = %.2f sq. un.\n", AB*BC);
	
};


void deleting(ppoint del_rect)
{
	for(int i = 0; i < 4; ++i) free(del_rect->points[i]); 
	
	free(del_rect);
	printf("Deleting is succesfull!))\n");
	
}


