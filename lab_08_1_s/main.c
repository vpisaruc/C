#include <stdio.h>
#include "functions.h"

#define OK 0
#define ELEMENTS_ERROR -2 
#define FILE_ERROR -3

#define N 5
#define M 7






int main(int argc, char **argv)
{
    int size1, size2;
    int array[N][M];
    int retVal;
    
    
    
    FILE *file;
    
    file = fopen(argv[argc - 1], "r");
    
    retVal = fill_matrix(file, &size1, &size2, array);
    
    if (retVal == OK)
    {
        print(array, size1, size2);
    } 
    
    else if (retVal == ELEMENTS_ERROR)
    {
        printf("Libo odin iz elementov raven ili menishe nulia, libo bolishe constanti");
    }
    else
    {
        printf("Chto-to ne tak s failom");
    }
    
    fclose(file);
    
}
