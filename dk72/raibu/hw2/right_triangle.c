
#include "right_triangle.h"
 
prtriangle2d new_rtriangle2d_arr(ppoint2d* arr){
	prtriangle2d ret = (prtriangle2d)malloc(sizeof(rtriangle2d));
	for (int i = 0; i < 3; ++i)
	{
		ret->points[i] = malloc(sizeof(point2d)); 
		memcpy(ret->points[i], arr[i], sizeof(point2d));

		#ifdef DEBUG
			printf("point %d on %.2f, %.2f\n", i, ret->points[i]->x, ret->points[i]->y);
		#endif
	}
	return ret;
}


prtriangle2d new_rtriangle2d_points(ppoint2d p0, ppoint2d p1, ppoint2d p2){
	prtriangle2d ret = (prtriangle2d)malloc(sizeof(rtriangle2d));
	for (int i = 0; i < 3; ++i)
	{
		ret->points[i] = malloc(sizeof(point2d)); 
	}
	memcpy(ret->points[0], p0, sizeof(point2d));
	memcpy(ret->points[1], p1, sizeof(point2d));
	memcpy(ret->points[2], p2, sizeof(point2d));

	#ifdef DEBUG
		for (int i = 0; i < 3; ++i)
		{
			printf("point %d on %.2f, %.2f\n", i, ret->points[i]->x, ret->points[i]->y);
		}
	#endif

	return ret;
}



prtriangle2d new_rtriangle2d_coords(double x0, double y0, double x1, double y1, double x2, double y2){
	prtriangle2d ret = (prtriangle2d)malloc(sizeof(rtriangle2d));
	for (int i = 0; i < 3; ++i)
	{
		ret->points[i] = malloc(sizeof(point2d)); 
	}
	ret->points[0]->x = x0;
	ret->points[1]->x = x1;
	ret->points[2]->x = x2;
	ret->points[0]->y = y0;
	ret->points[1]->y = y1;
	ret->points[2]->y = y2;


	#ifdef DEBUG
		for (int i = 0; i < 3; ++i)
		{
			printf("point %d on %.2f, %.2f\n", i, ret->points[i]->x, ret->points[i]->y);
		}
	#endif

	return ret;
}



void triangle_free(prtriangle2d in){
	for (int i = 0; i < 3; ++i)
	{
		free(in->points[i]);
	}
	free(in);
}


params_check validate(prtriangle2d triangle){
	params_check ret = INVALID;
	double sidelen[3];
	for (int i = 0; i < 3; ++i)
	{
		double tempx = (triangle->points[i]->x - triangle->points[(i+1)%3]->x);
		double tempy = (triangle->points[i]->y - triangle->points[(i+1)%3]->y);
		sidelen[i] = sqrt(tempy*tempy + tempx*tempx); 
	}
	for (int i = 0; i < 3; ++i)
	{
		if(sidelen[i]*sidelen[i] == sidelen[(i+1)%3]*sidelen[(i+1)%3] + sidelen[(i+2)%3]*sidelen[(i+2)%3])ret=VALID;

		#ifdef DEBUG
		printf("len of %dst side is %.3f\n", i, sidelen[i]);
		#endif
	}
	return ret;
}



prtriangle2d enter_params(){
	prtriangle2d ret;
	double args[3][2];
invalid: 
	printf("Enter coordinates of 3 points: [x y]\n");
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			printf("Enter %c%d: ", (j==0)?'x':'y', i);
			get_double(&(args[i][j]));
		}
	}
	if(validate(ret = new_rtriangle2d_coords(args[0][0], args[0][1], args[1][0], args[1][1], args[2][0], args[2][1])) == INVALID){
		free(ret);
		printf("Triangle you entered is not right.\n");
		goto invalid;
	}
	return ret;
}




void get_double(double* arg){
	regex_t pattern;
	char* str = malloc(64);
	scanf("%s", str);
	regcomp(&pattern, "[+-]?([0-9]*[.])?[0-9]+", REG_EXTENDED | REG_NOSUB);
	while(regexec(&pattern, str, 0, NULL, 0)){
		printf("Retry: ");
		scanf("%s", str);
	}
	*arg = atof(str);
	regfree(&pattern); 
}


void print_rtriangle(prtriangle2d in){
	for (int i = 0; i < 3; ++i)
	{
		printf("point %d on (%.2f, %.2f)\n", i, in->points[i]->x, in->points[i]->y);
	}
	double sidelen[3];
	for (int i = 0; i < 3; ++i)
	{
		double tempx = (in->points[i]->x - in->points[(i+1)%3]->x);
		double tempy = (in->points[i]->y - in->points[(i+1)%3]->y);
		sidelen[i] = sqrt(tempy*tempy + tempx*tempx); 
	}
	for (int i = 0; i < 3; ++i)
	{
		
		printf("len of %dst side is %.3f\n", i, sidelen[i]);
		
	}	
}
