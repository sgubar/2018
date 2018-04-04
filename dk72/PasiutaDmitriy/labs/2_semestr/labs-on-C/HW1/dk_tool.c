#include "dk_tool.h"

void additionmatrix(int length, int resultmatrix[length][length], int fisrtmatrix[length][length], int secondmatrix[length][length])
{
    int i = 0, j = 0;

    for(i = 0; i < length; i++)
    {
        for(j = 0; j < length; j++)
        {
            resultmatrix[i][j] = 0;
            resultmatrix[i][j] = fisrtmatrix[i][j] + secondmatrix[i][j];
        }
    }
}
