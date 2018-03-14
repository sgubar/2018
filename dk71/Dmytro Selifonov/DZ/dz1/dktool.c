#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dktool.h"

int kilkist_sliv(){
	char rechena[100];
	int words=0, i = 0;
	printf("vvedit rechena do 100 sumvoliv\n");
	for(i = 0;i < 100;i++){
		scanf("%c",&rechena[i]);
		if(rechena[i]=='.'){
			if(rechena[i-1]!=' '){
			words++;	
			}
			break;
		}
		if((rechena[i]==' '||rechena[i]=='('||rechena[i]=='\n')&&rechena[i+1]!=' '&&rechena[i+1]!='.'&&rechena[i-1]!=' '){
			words++;
		}
	}
	
	return words;
}
