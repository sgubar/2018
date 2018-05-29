#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
int main()
{
	
	Node *thetree = NULL;
	
	int check = 0;
	double val = 0;
	
	printf("\n\tAll operation:");
	printf("\n 1.---add element to tree");
	printf("\n 2.---search element");
	printf("\n 3.---delete element");
	printf("\n 4.---print tree");
	printf("\n 5.---delete tree");
	printf("\n 6.---max or min of tree");
	printf("\n 7.---size of tree");
	printf("\n 8.---height of tree");
	printf("\n 9.---exit\n");

	while(1)
    {
    	
	    scanf("%d", &check);
	    
	     switch(check)
		{
		 case 1:
		 	printf("\nEnter element to add:");
		 	scanf("%f", &val);
			add_node(thetree, val);
			     break;
	    
		 case 2:
		 	 printf("\nEnter element to search:");
		 	 scanf("%f", &val);
			 if(search(thetree, val) == 1)
			 printf("\n found!");
			 else
			 printf("\n not found:(");
			     break;
		
		 case 3: 
			 printf("\nEnter element to delete:");
			 scanf("%f", &val);
		  	 delete_node(thetree, val);
			     break;
		
		 case 4:
		 		 printf("\n Tree:\n");
				 tree_print(thetree);			 
				 break;
		
	  	 case 5:
		
			 tree_free(thetree);
			 printf("\nThe tree was deleted!");
			 	 break;
			 	 
		 case 6:
		
			 printf("\n Find Max [1] Find Min [2]");
			 printf("\n %f", find_max_min(thetree, val));
			 	 break;
		
		 case 7:

			 printf("\n Size = %d", size(thetree));
			 	 break;
			 	
		 case 8:

			 printf("\n Height = %d", height(thetree));
			 	 break;		  
		
		 case 9:
printf("___________������_��������\n"
"__________�_____��________�\n"
"________���_______________ �������\n"
"________�_______________________���\n"
"_______ ��____�__________________ �\n"
"______���____���������____________���\n"
"______��______�����_______ ��_______��_��\n"
"_____������_______________��__�_��___������\n"
"___���__����__���_________�������____��___���\n"
"___�______���_�_�__�__�_���________________���\n"
"__ �________�_�_����������_��________________��\n"
"___��____����_�_���_����_�_����������________��\n"
"__����___��������___���_�__���____����______���\n"
"_���_�����_������_��_���____��������________���\n"
"��_____���__��_�����__��___������_�_____���___��\n"
"�_____���___�_�_���___��_��__�__�����__���_____��\n"
"��___������_���___�____���__����������������____�\n"
"_��__������������_���__��__�������__����__�____���\n"
"__ ����_____�_���______��___��_____���_________�\n"
"____________���__��_____�___���_�����������___��\n"
"___�����������������_��_��_���������������������\n"
"__ �_____�����___���_��__����___���________���\n"
"__ ��____��_______��_��___����_�����_____���\n"
"__ �_____�___�_���_�_��___��_���__���____��\n"
"__ ��_______����__��______ �________������\n"
"___�__�������_____�___���__�__________���\n"
"___���������_____��__�����_��\n"
"________________��___����___��\n"
"_______________��____����___��\n"
"____________����_____��_____��\n"
"___________ ��_______��_____��\n"
"__________���___��___��_____��\n"
"________����____��___�______��\n"
"______ �����____�______��____��\n"
"_____��������_���_�____��_�___��\n"
"___�����������K�������������������\n"
"__ ��������������_������____�����_���\n");
			return 0;
		}
	}
}


