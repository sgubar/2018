//dk_tool.c
#include "dk_tool.h"


int get_int8(void){
	int result=0;
	char* str = malloc(10);
	scanf("%s",str);
	while(!is_base8(str)){ 
		printf("Retry: "); 
		scanf("%s",str);
	}
	
	while(*str){
		result=result<<3;
		result+=(*str-'0');
		str++;
	}

	return result;
}


int is_base8(char* str){
	while(*str){
		if(*str<'0' || *str >'7'){
			return 0;
		}
		str++;
	}
	return 1;
}






