//
//  dk_tool_array.c
//  dz3
//
//  Created by Vadym Vaskovets on 3/29/18.
//  Copyright © 2018 Vadym Vaskovets. All rights reserved.
//
#include <stdlib.h>
#include <locale.h>
#include "dk_tool_array.h"
#include "dk_tool.h"

	triangleArray *createArray(int aNumber)
		{
			setlocale(LC_ALL, "RUS");
			triangleArray *theResult = NULL;

		if (aNumber > 0)
			{
				theResult = (triangleArray *)malloc(sizeof(triangleArray));

				if (NULL != theResult)
				{
					theResult->triangles = (triangle **)malloc(sizeof(triangle *)*aNumber);

					if (NULL != theResult->triangles)
					{
						theResult->number = aNumber;
						theResult->count = 0;
					}
					else
						{
							free(theResult);
							theResult = NULL;
						}
				}
			}

		return theResult;
		}

	void freeArray(triangleArray *anArray)
	{
		int i;
		if (NULL != anArray)
		{
			for (i = 0; i < anArray->count; i ++)
			{
				destroy_triangle(anArray->triangles[i]);
			}

			free(anArray->triangles);
			free(anArray);
		}
	}	


	int addElement(triangleArray *anArray, triangle *atriangle)
	{
		int theResult = -1;

		if (NULL != anArray && NULL != atriangle &&	anArray->count < anArray->number)
			{
					anArray->triangles[anArray->count] =
					create_triangle(atriangle->A, atriangle->B, atriangle->C);
					theResult = anArray->count;
					anArray->count ++;
			}

		return theResult;
	}

void writeArrayToJSON(FILE *aFile, triangleArray *anArray)
	{
		int i;
		if (NULL == anArray || NULL == aFile)
			{
				return ;
			}

			fprintf(aFile, "{\n\"Íîìåð\" : %d,\n\"Êîëè÷åñòâî òðåóãîëüíèêîâ\" : %d,\n",
			anArray->number, anArray->count);
			fprintf(aFile, "\"Òðåóãîëüíèêè\" : \n[\n");

	for (i = 0; i < anArray->count; i ++)
			{
				writetriangleToJSON(aFile, anArray->triangles[i]);
					if (i < anArray->count - 1)
					{
						fprintf(aFile, ",");
					}
				fprintf(aFile, "\n");
			}
		fprintf(aFile, "]\n}");
	}
