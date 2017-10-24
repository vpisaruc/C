#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "functions.h"


int main(int argc, char **argv)
{
    FILE *file;
    int retVal, cntElem, cntWorkElem, cntQsort;
    int *arrInp, *arrWork, *arrQsort, *idxWork, *afterLastElem, *lastPrintElem;
    unsigned long long tb_mySort, te_mySort, tb_qSort, te_qSort;
    
    
    // Открытие файла c тестовыми данными для чтения
    if(argc == 4)
    {
        file = fopen(argv[argc - 3], "r");
    }
    else if(argc == 3)
    {
        file = fopen(argv[argc - 2], "r");
    }
    else
    {
        printf("Must be 3 or 4 argumets of command line");
        return COMMAND_LINE_ERROR;
    }
    if (file == NULL)
    {
        printf("Error: File  not exists");
        getchar();

        return ERROR_FILE_NOT_EXISTS;
    }

    // Подсчет количества элементов
    retVal = countFileData(file, &cntElem);
    if (retVal < 0)
    {
        // Вовзрат кода ошибки
        printf("Error = %d\n\nInput any key for Exit", retVal);
        getchar();

        return retVal;
    }

    // Выделение памяти
    arrInp = (int*)malloc(cntElem * sizeof(int));
    afterLastElem = arrInp + cntElem;
    
    // Загрузка данных
    retVal = loadFileData(file, arrInp);
    if (retVal < 0)
    {
        // Вовзрат кода ошибки
        printf("Error = %d\n\nInput any key for Exit", retVal);
        getchar();

        return retVal;
    }

    // Закрытие файла
    fclose(file);

    // Печать входного массива
    lastPrintElem = afterLastElem - 1;
    printArray(0, arrInp, lastPrintElem);

    // Фильтрация и перезапись данных в рабочий массив
    if(argc == 4)
    {
        if (*argv[argc - 1] == 'f')
        {
        
            int **arrWorkPtr, **cntWorkElemPtr;
            arrWorkPtr = (int**)malloc(sizeof(int*));
            cntWorkElemPtr = (int**)malloc(sizeof(int*));
            retVal = key(arrInp, afterLastElem, arrWorkPtr, cntWorkElemPtr);

            // Присвоение данных из функции
            arrWork = *arrWorkPtr;
            cntWorkElem = **cntWorkElemPtr;
            arrQsort = *arrWorkPtr;
            cntQsort = **cntWorkElemPtr;
            
            // Печать отфильтрованного массива
            lastPrintElem = arrWork + cntWorkElem - 1;
            printArray(1, arrWork, lastPrintElem);
        }
    }
    else
    {
        // Без фильтрации
        arrWork = arrInp;
        cntWorkElem = cntElem;
        arrQsort = arrInp;
        cntQsort = cntElem;
    }
    
    



    // Сортировка отфильтрованного/неотфильтрованного массива и замер времени
    tb_mySort = tick();
    mySort(arrWork, cntWorkElem, sizeof(int), compareFunc);
    te_mySort = tick();
    printf("\nTime of mySort func: %llu\n ", (te_mySort - tb_mySort));
    
    
    tb_qSort = tick();
    qsort(arrQsort, cntQsort, sizeof(int), compareFunc);
    te_qSort = tick();
    printf("\nTime of qSort func: %llu\n\n ", (te_qSort - tb_qSort));

    // Печать отсортированного массива
    lastPrintElem = arrWork + cntWorkElem - 1;
    printArray(2, arrWork, lastPrintElem);
    printArray(3, arrQsort, lastPrintElem);

    // Запись данных в файл
    if(argc == 4 )
    {
        file = fopen(argv[argc - 2], "w");
    }
    else if(argc == 3)
    {
        file = fopen(argv[argc - 1], "w");
    }
    if (file == NULL)
    {
        printf("Error: Can't open file for write");
        getchar();

        return ERROR_FILE_OPEN_WRITE;
    }
    // запись массива
    idxWork = arrWork;
    lastPrintElem = arrWork + cntWorkElem - 1;
    while (idxWork <= lastPrintElem)
    {
        fprintf(file, "%d ", *idxWork);
        idxWork++;
    }
    fclose(file);

    // Очистка массивов
    free(arrInp);
    if(argc == 4)
    {
        if (argv[argc - 1] == 0)
        {
            // Очищается только при фильтрации
            free(arrWork);
        }
    }

    printf("Ok. Input any key for Exit");
    getchar();

    return 0;
}


