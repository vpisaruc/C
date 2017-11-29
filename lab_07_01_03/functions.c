#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "functions.h"


// ���������� �������


//������� ������ �������
unsigned long long tick(void)

{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    
    return d;
}

// ���������� ��������� � �����
int countFileData(FILE *file, int *cntElem)
{
    int retVal = 1, cnt = 0, value;

    // ��������� ��������� �� ������ �����
    rewind(file);
    
    // ���������� �����  
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
        // ��� ������
        return ERROR_FILE_EMPTY;
    }

    // ����� ���������
    *cntElem = cnt;

    return OK;
}

// �������� ������
int loadFileData(FILE *file, int *arrInp, int *cntElem)
{
    int retVal = 1, cnt = 0, value, *idx;
    

    // ��������� ��������� �� ������ �����
    rewind(file);

    idx = arrInp;

    // ���������� �����  
    while (retVal == 1)
    {
        retVal = fscanf(file, "%d", &value);

        switch (retVal)
        {
            case 0:
            {
                      // ������������ ��������� �����
                      return ERROR_FILE_DATA_STRUCTURE;
                      break;
            }
            case 1:
            {
                      *idx = value;
                      idx++;
                      cnt++;
                      if(cnt > *cntElem)
                      {
                        return BUFFER_ERROR;
                      }
            }
        }
    }

    if (cnt == 0)
    {
        // ��� ������
        return ERROR_FILE_EMPTY;
    }

    return OK;
}



// ����� ������ ����������(�� �������) 
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int *idxInp, *idxWork, *lastNegativeElem, *arrWork;
    int cnt = 0, cntToLastNegative = 0;

    // ��������� ������� ������� - ������
    if(!pb_src || !pe_src)
    {
        return INCORRECT_PARAM;
    }
    
    idxInp =  (int *)pb_src;
    while (idxInp < pe_src)
    {
        cnt++;
        if (*idxInp < 0)
        {
            cntToLastNegative = cnt - 1;
        }
        idxInp++;
    }
    if (cntToLastNegative == 0 || cnt == 0)
    {
        return NONE_ELEMENTS;
    }

    arrWork = (int*)malloc(cntToLastNegative * sizeof(int));
    
    if (!arrWork)
    {
        return MEMMORY_ERROR;
    }

    // ��������� ������� ������� - ������
    idxInp = (int*)pb_src;
    idxWork = arrWork;
    lastNegativeElem = idxInp + cntToLastNegative - 1;

    while (idxInp < lastNegativeElem)
    {
        *idxWork = *idxInp;
        idxInp++;
        idxWork++;
    }

    *pe_dst = &cntToLastNegative;
    *pb_dst = arrWork;

    if(pe_dst < pb_dst)
    {
        return SIZE_ERROR;
    }


    return 0;
}


// ������ ������� ������
void printArray(const char *headString, int *arrPrint, int *lastPrintElem)
{
    int *idx;

    // ��������� ������� ������� - ������
    idx = arrPrint;

    printf("%s\n", headString);


    while (idx < lastPrintElem - 1 )
    {
        printf("%5d", *idx);
        idx++;
    }
    printf("\n\n");
}

// ������� ���������
int compareFunc(const void *a, const void *b) 
{
    return *(int*)a - *(int*)b;
}


// ������� ���������� �������
void mysort(void * arrSort, size_t cntElem, size_t sizeElem, int(*compareFunc) (const void *, const void *))
{
    int *idx, *lastElem, *maxElem, *startElem;
    int tmpValue;

    // ��������� ������� ������� - ������
    startElem = (int*)arrSort;
    lastElem = startElem + cntElem - 1;

    while (startElem <= lastElem)
    {
        idx = startElem;
        maxElem = idx;
        while (idx <= lastElem)
        {
            // ��������� �������� �������� � ������������
            if (compareFunc(idx, maxElem) > 0)
            {
                maxElem = idx;
            }
            idx++;
        }
        if (maxElem != lastElem)
        {
            // ������ ������������� � ���������� ���������
            tmpValue = *maxElem;
            *maxElem = *lastElem;
            *lastElem = tmpValue;
        }
        lastElem--;
    }
}


void write_file(FILE *file, int *arrWork, int *lastPrintElem)
{
    int *idxWork = arrWork;

    while (idxWork < lastPrintElem - 1)
    {
        fprintf(file, "%d ", *idxWork);
        idxWork++;
    }
}
