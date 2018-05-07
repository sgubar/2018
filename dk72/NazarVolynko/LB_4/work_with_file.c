#include <stdio.h>
#include "spysok.h"
#include "work_with_file.h"

void loadFile (char * path, CharList *Before_Range, CharList *IN_Range, CharList *After_Range, char minimum, char maximum)
{

  FILE *theFile = fopen(path, "r");

  if (theFile ==NULL)return ;

  char symbol;

  CharNode *theNode = NULL;

  while(!feof(theFile))
  {
      fscanf (theFile, "%c", &symbol);

      if(symbol<minimum)
      {
          theNode = SLCreateNodeWithCharValue(symbol);
          SLAddNode(Before_Range, theNode);
      }

      if(symbol>=minimum && symbol<=maximum)
      {
          theNode = SLCreateNodeWithCharValue(symbol);
          SLAddNode(IN_Range, theNode);
      }
      if(symbol>maximum)
      {
          theNode = SLCreateNodeWithCharValue(symbol);
          SLAddNode(After_Range, theNode);
      }
  }

  fclose(theFile);
}

void Enter_range(char *minimum, char *maximum)
{
    printf("\n\nEnter the required range:\n");
    printf("minimum: ");
    scanf("%c%*c", minimum);
    printf("maximum: ");
    scanf("%c", maximum);
}
