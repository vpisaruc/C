#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#define COMPARE_ERROR -1
#define OK 0

int compare_arrays(int row, int column, double **array_1, double **array_2)
{
    for(int i = 0; i < row, i++ )
    {
        for(int j = 0; j < column; j++)
        {
            if(array1[i][j] != array_2[i][j])
            {
                return COMPARE_ERROR;
            }
        }
    }
    return OK;
}