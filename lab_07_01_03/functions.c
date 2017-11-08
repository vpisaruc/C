#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "functions.h"


//  


//  
unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    
    return d;
}

//    
int countFileData(FILE *file, int *cntElem)
{
    int retVal = 1, cnt = 0, value;

    //     
    rewind(file);
    
    //    
    while (retVal == 1)
    {
        retVal = fscanf(file, "%d", &value);

        switch (retVal)
        {
            case 0:
                {
                    return ERROR_FILE_DATA_STRUCTURE;
                    break;
                }
            case 1:
                {
                    cnt++;
                }
        }
    }
    if (cnt == 0)
    {
        //  
        return ERROR_FILE_EMPTY;
    }

    //  
    *cntElem = cnt;

    return OK;
}

//  
int loadFileData(FILE *file, int *arrInp)
{
    int retVal = 1, cnt = 0, value, *idx;

    //     
    rewind(file);

    idx = arrInp;

    //    
    while (retVal == 1)
    {
        retVal = fscanf(file, "%d", &value);

        switch (retVal)
        {
            case 0:
                {
                    return ERROR_FILE_DATA_STRUCTURE;
                    break;
                }
            case 1:
                {
                    *idx = value;
                    idx++;
                    cnt++;
                }
        }
    }
    if (cnt == 0)
    {
        //  
        return ERROR_FILE_EMPTY;
    }

    return OK;
}



//   ( ) 
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int *idxInp, *idxWork, *lastNegativeElem, *arrWork;
    int cnt = 0, cntToLastNegative = 0;

    //    - 
    idxInp = (int *)pb_src;
    while (idxInp < pe_src)
    {
        cnt++;
        if (*idxInp < 0)
        {
            //   -    
            cntToLastNegative = cnt;
        }
        idxInp++;
    }
    if (cntToLastNegative == 0)
    {
        cntToLastNegative = cnt;
    }

    arrWork = (int*)malloc(cntToLastNegative * sizeof(int));

    //    - 
    idxInp = (int*)pb_src;
    idxWork = arrWork;
    lastNegativeElem = idxInp + cntToLastNegative - 1;

    while (idxInp <= lastNegativeElem)
    {
        *idxWork = *idxInp;
        idxInp++;
        idxWork++;
    }

    *pe_dst = &cntToLastNegative;
    *pb_dst = arrWork;

    return 0;
}


//   
void printArray(int typeHead, int *arrPrint, int *lastPrintElem)
{
    int *idx;

    //    - 
    idx = arrPrint;

    switch (typeHead)
    {
        case 0:
            {
                printf("Input Array\n");
                break;
            }
        case 1:
            {
                printf("Filtered Array\n");
                break;
            }
        case 2:
            {
                printf("Sorting Array with mysort\n");
                break;
            }
        case 3:
            {
                printf("Sorting Array with Qsort\n");
                break;
            }
    }

    while (idx <= lastPrintElem)
    {
        printf("%5d", *idx);
        idx++;
    }
    printf("\n\n");
}

//  
int compareFunc(const void *a, const void *b) 
{
    return *(int*)a - *(int*)b;
}


//   
void mySort(void * arrSort, size_t cntElem, size_t sizeElem, int(*compareFunc) (const void *, const void *))
{
    int *idx, *lastElem, *maxElem, *startElem;
    int tmpValue;

    //    - 
    startElem = (int*)arrSort;
    lastElem = startElem + cntElem - 1;

    while (startElem <= lastElem)
    {
        idx = startElem;
        maxElem = idx;
        while (idx <= lastElem)
        {
            //     
            if (compareFunc(idx, maxElem) > 0)
            {
                maxElem = idx;
            }
            idx++;
        }
        if (maxElem != lastElem)
        {
            //     
            tmpValue = *maxElem;
            *maxElem = *lastElem;
            *lastElem = tmpValue;
        }
        lastElem--;
    }
}




