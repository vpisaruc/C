#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "functions.h"




int main (void)
{
    unsigned long long tb, te, te_1, tb_1;
    int test_array[16] = {12, 3, 7, 5, 1, 12, 3, 7, 5, 1, -5, 12, -45, 1 ,0, 0}; 
    int sort_array[16];
    
    te = tick();
    for(int i = 0; i < 5; i++)
    {
        memcpy(sort_array, test_array, sizeof(sort_array));
        mysort(sort_array, 16, sizeof(int), compareFunc);
    }
    tb = tick();

    te_1 = tick();
    for(int i = 0; i < 5; i++)
    {
        memcpy(sort_array, test_array, sizeof(sort_array));
        qsort(sort_array, 16, sizeof(int), compareFunc);
    }
    tb_1 = tick();

    printf("Time mysort: %llu\n", (te - tb) / 100);
    printf("Time qsort : %llu\n", (te_1 - tb_1) / 100);
}

