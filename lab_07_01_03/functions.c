#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "functions.h"



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
                      // ������������ ��������� �����
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
int loadFileData(FILE *file, int *arrInp)
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

// ���������� � ���������� ������ � ������� ������
void filterData(int *arrInp, int *afterLastElem,  int *arrWork, int *cntWorkElem)
{
    int *idxInp, *idxWork, *lastNegativeElem;
    int cnt=0, cntToLastNegative=0;

    // ��������� ������� ������� - ������
    idxInp = arrInp;
    while (idxInp < afterLastElem)
    {
        cnt++;
        if (*idxInp < 0)
        {
            // ��� ������������� - ����� ������������ ��� ��������
            cntToLastNegative = cnt;
        }
        idxInp++;
    }
    if (cntToLastNegative == 0)
    {
        cntToLastNegative = cnt;
    }

    arrWork = (int*)realloc(arrWork, cntToLastNegative * sizeof(int));

    // ��������� ������� ������� - ������
    idxInp = arrInp;
    idxWork = arrWork;
    lastNegativeElem = idxInp + cntToLastNegative - 1;

    while (idxInp <= lastNegativeElem)
    {
        *idxWork = *idxInp;
        idxInp++;
        idxWork++;
    }

    *cntWorkElem = cntToLastNegative;
}

// ������ ������� ������
void printArray(int typeHead, int *arrPrint, int *lastPrintElem)
{
    int *idx;

    // ��������� ������� ������� - ������
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
                  printf("Sorting Array\n");
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

// ������� ���������
int compareFunc(const void *a, const void *b) 
{
    return *(int*)a - *(int*)b;
}

// ������� ���������� �������
void sortArray(void * arrSort, size_t cntElem, size_t sizeElem, int(*compareFunc) (const void *, const void *))
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


