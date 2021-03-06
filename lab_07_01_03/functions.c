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
    int retVal = 1, cnt = 0, value, *idx = NULL;
    

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
                    if (cnt > *cntElem)
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



int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int *idxInp = NULL, *idxWork = NULL, *lastNegativeElem = NULL, *arrWork = NULL;
    int cnt = 0, cntToLastNegative = 0, cnt_neg = 0;

    if (!pb_src || !pe_src)
    {
        return INCORRECT_PARAM;
    }
    
    if (pb_src == pe_src)
    {
        return INCORRECT_PARAM;
    }


    // Начальный элемент массива - ссылка
    idxInp = (int *)pb_src;
    while (idxInp < pe_src)
    {
        cnt++;
        if (*idxInp < 0)
        {
            // все положительные - будут перезаписаны все элементы
            cntToLastNegative = cnt;
            cnt_neg++;
        }
        idxInp++;
    }

    if (cntToLastNegative == 1 && cnt_neg == 1)
    {
        return NONE_ELEMENTS;
    }

    if (cntToLastNegative == 0)
    {
        // Создаем Array c 1 элементом
        //cntToLastNegative = 1;
        cntToLastNegative = cnt;
    }
    else
    {
        cntToLastNegative--;
    }

    arrWork = (int*)malloc(cntToLastNegative * sizeof(int));
    
    if (!arrWork)
    {
        free(arrWork);
        return MEMMORY_ERROR;
    }

    // Начальный элемент массива - ссылка
    idxInp = (int*)pb_src;
    idxWork = arrWork;
    lastNegativeElem = idxInp + cntToLastNegative - 1;

    while (idxInp <= lastNegativeElem)
    {
        *idxWork = *idxInp;
        idxInp++;
        idxWork++;
    }

    *pb_dst = arrWork;
    *pe_dst = arrWork + cntToLastNegative;
    
    if (*pb_dst > *pe_dst)
    {
        return SIZE_ERROR;
    }
    return 0;
}





// ������ ������� ������
void printArray(const char *headString, int *arrPrint, int *lastPrintElem)
{
    int *idx = NULL;

    // ��������� ������� ������� - ������
    idx = arrPrint;

    printf("%s\n", headString);


    while (idx < lastPrintElem)
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
void mysort(void *arrSort, size_t cntElem, size_t sizeElem, int(*compareFunc)(const void *, const void *))
{
    char *maxElemAddr = NULL, *idxAddr = NULL, *startElemAddr = NULL, *lastElemAddr = NULL;
    char tmpValue;

    // Проверка на необходимость сортировки 
    if (cntElem == 0 || cntElem == 1)
        return;

    // Начальный элемент массива - ссылка
    startElemAddr = (char*)arrSort;
    lastElemAddr = startElemAddr + (cntElem - 1) * sizeElem;

    while (startElemAddr <= lastElemAddr)
    {
        maxElemAddr = startElemAddr;
        idxAddr = startElemAddr + sizeElem;
        while (idxAddr <= lastElemAddr)
        {
            // Сравнение текущего элемента с максимальным
            if (compareFunc(idxAddr, maxElemAddr) > 0)
            {
                maxElemAddr = idxAddr;
            }
            idxAddr = idxAddr + sizeElem;
        }
        if (maxElemAddr != lastElemAddr)
        {
            // Замена максимального и последнего элементов
            idxAddr = lastElemAddr;
            for (size_t i = 0; i < sizeElem; i++)
            {
                tmpValue = *maxElemAddr;
                *maxElemAddr = *idxAddr;
                *idxAddr = tmpValue;
                maxElemAddr++;
                idxAddr++;
            }
        }
        lastElemAddr = lastElemAddr - sizeElem;
    }
}




void write_file(FILE *file, int *arrWork, int *lastPrintElem)
{
    int *idxWork = arrWork;

    while (idxWork < lastPrintElem)
    {
        fprintf(file, "%d ", *idxWork);
        idxWork++;
    }
}