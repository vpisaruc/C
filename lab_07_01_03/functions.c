#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "functions.h"



// Количество элементов в файле
int countFileData(FILE *file, int *cntElem)
{
    int retVal = 1, cnt = 0, value;

    // устмновка указателя на начало файла
    rewind(file);
    
    // считывание файла  
    while (retVal == 1)
    {
        retVal = fscanf(file, "%d", &value);

        switch (retVal)
        {
            case 0:
            {
                      // неправильная структура файла
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
        // нет данных
        return ERROR_FILE_EMPTY;
    }

    // число элементов
    *cntElem = cnt;

    return OK;
}

// Загрузка данных
int loadFileData(FILE *file, int *arrInp)
{
    int retVal = 1, cnt = 0, value, *idx;

    // устмновка указателя на начало файла
    rewind(file);

    idx = arrInp;

    // считывание файла  
    while (retVal == 1)
    {
        retVal = fscanf(file, "%d", &value);

        switch (retVal)
        {
            case 0:
            {
                      // неправильная структура файла
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
        // нет данных
        return ERROR_FILE_EMPTY;
    }

    return OK;
}

// Фильтрация и перезапись данных в рабочий массив
void filterData(int *arrInp, int *afterLastElem,  int *arrWork, int *cntWorkElem)
{
    int *idxInp, *idxWork, *lastNegativeElem;
    int cnt=0, cntToLastNegative=0;

    // Начальный элемент массива - ссылка
    idxInp = arrInp;
    while (idxInp < afterLastElem)
    {
        cnt++;
        if (*idxInp < 0)
        {
            // все положительные - будут перезаписаны все элементы
            cntToLastNegative = cnt;
        }
        idxInp++;
    }
    if (cntToLastNegative == 0)
    {
        cntToLastNegative = cnt;
    }

    arrWork = (int*)realloc(arrWork, cntToLastNegative * sizeof(int));

    // Начальный элемент массива - ссылка
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

// Печать массива данных
void printArray(int typeHead, int *arrPrint, int *lastPrintElem)
{
    int *idx;

    // Начальный элемент массива - ссылка
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

// Функция сравнения
int compareFunc(const void *a, const void *b) 
{
    return *(int*)a - *(int*)b;
}

// функция сортировки массива
void sortArray(void * arrSort, size_t cntElem, size_t sizeElem, int(*compareFunc) (const void *, const void *))
{
    int *idx, *lastElem, *maxElem, *startElem;
    int tmpValue;

    // Начальный элемент массива - ссылка
    startElem = (int*)arrSort;
    lastElem = startElem + cntElem - 1;

    while (startElem <= lastElem)
    {
        idx = startElem;
        maxElem = idx;
        while (idx <= lastElem)
        {
            // Сравнение текущего элемента с максимальным
            if (compareFunc(idx, maxElem) > 0)
            {
                maxElem = idx;
            }
            idx++;
        }
        if (maxElem != lastElem)
        {
            // Замена максимального и последнего элементов
            tmpValue = *maxElem;
            *maxElem = *lastElem;
            *lastElem = tmpValue;
        }
        lastElem--;
    }
}


