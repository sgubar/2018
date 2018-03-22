#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int  func(char *s, char *g)
	{
		int a,b;
		int d = 0;
		int longS = strlen(s);
		int longG = strlen(g);
		for(a=0;a<longS;a++)
		{
			for(b=0;b<longG;b++)
				{
					if (s[a+b]==g[0+b])
						{
							d++;
						}
				}

		}
		return d/longG;
	}
