#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "functions.h"


int main(int argc, char **argv)
{
    FILE * file = NULL;
    int retVal, cntElem, cntWorkElem;
    int *arrInp = NULL, *arrWork = NULL, *afterLastElem = NULL, *lastPrintElem = NULL, *idxWork = NULL, *idxInp = NULL;
    //unsigned long long tb_mySort, te_mySort, tb_qSort, te_qSort;
    
    
    // �������� ����� c ��������� ������� ��� ������
    if (argc == 4)
    {
        file = fopen(argv[argc - 3], "r");
    }
    else if (argc == 3)
    {
        file = fopen(argv[argc - 2], "r");
    }
    else
    {
        printf("Must be 3 or 4 argumets of command line, elements of cammand line(app.exe in_file out_file [f])");
        exit(COMMAND_LINE_ERROR);
    }
    if (file == NULL)
    {
        printf("Error: File  not exists");
        

        exit(ERROR_FILE_NOT_EXISTS);
    }

    // ������� ���������� ���������
    retVal = countFileData(file, &cntElem);
    if (retVal < 0)
    {
        // ������� ���� ������
        printf("Error = %d\n\nInput any key for Exit", retVal);
        

        exit(retVal);
    }

    // Выделение памяти
    arrInp = (int*)malloc(cntElem * sizeof(int));
    if (!arrInp)
    {
        printf("\nMemory allocation error\n");
        return MEMORY_ERROR;
    }
    afterLastElem = arrInp + cntElem;
    arrWork = (int*)malloc(cntElem * sizeof(int));
    if (!arrWork)
    {
        free(arrInp);
        printf("\nMemory allocation error\n");
        return MEMORY_ERROR;
    }
    
    // �������� ������
    retVal = loadFileData(file, arrInp, &cntElem);
    if (retVal < 0)
    {
        // Вовзрат кода ошибки
        free(arrInp);
        free(arrWork);
        printf("Error = %d\n\nInput any key for Exit", retVal);

        exit(retVal);
    }

    // �������� �����
    fclose(file);

    // ������ �������� �������
    lastPrintElem = afterLastElem;
    printArray("Input Array", arrInp, lastPrintElem);

    // ���������� � ���������� ������ � ������� ������
    if (argc == 4)
    {
        if (*argv[argc - 1] == 'f')
        {
            int **arrWorkPtr = NULL, **arrWorkAfterPtr = NULL;
            arrWorkPtr = (int**)malloc(sizeof(int));
            arrWorkAfterPtr = (int**)malloc(sizeof(int));
            *arrWorkPtr = arrWork;
            *arrWorkAfterPtr = *arrWorkPtr + cntElem;
            retVal = key(arrInp, afterLastElem, arrWorkPtr, arrWorkAfterPtr);
            if (retVal == MEMORY_ERROR)
            {
                printf("\nMemory error\n");
                free(arrWorkPtr);
                free(arrWorkAfterPtr);
                exit(MEMORY_ERROR);
            }
            if (retVal == INCORRECT_PARAM)
            {
                printf("\nIncorrect parametres\n");
                free(arrWorkPtr);
                free(arrWorkAfterPtr);
                exit(INCORRECT_PARAM);
            }

            if (retVal == NONE_ELEMENTS)
            {
                printf("\nNone elements before negative\n");
                free(arrWorkPtr);
                free(arrWorkAfterPtr);
                exit(NONE_ELEMENTS);
            }

            if (retVal == SIZE_ERROR)
            {
                printf("Size error");
                free(arrWorkPtr);
                free(arrWorkAfterPtr);
                exit(SIZE_ERROR);
            }

            // Присвоение данных из функции
            cntWorkElem = *arrWorkAfterPtr - *arrWorkPtr;

            // ������ ���������������� �������
            lastPrintElem = arrWork + cntWorkElem;
            printArray("Filtered Array", arrWork, lastPrintElem);

            free(arrWorkPtr);
            free(arrWorkAfterPtr);
        }
    }
    else
    {
        // Без фильтрации
        idxInp = arrInp;
        idxWork = arrWork;
        // Перезапись массива
        for (int i = 0; i < cntElem; i++)
        {
            *idxWork++ = *idxInp++;
        }
        cntWorkElem = cntElem;
    }

    //Sort array
    mysort(arrWork, cntWorkElem, sizeof(int), compareFunc);

    // ������ ���������������� �������
    lastPrintElem = arrWork + cntWorkElem;
    printArray("Sorting Array", arrWork, lastPrintElem);

    // ������ ������ � ����
    if (argc == 4)
    {
        file = fopen(argv[argc - 2], "w");
    }
    else if (argc == 3)
    {
        file = fopen(argv[argc - 1], "w");
    }
    if (file == NULL)
    {
        printf("Error: Can't open file for write");
        free(arrWork);
        free(arrInp);
        exit(ERROR_FILE_OPEN_WRITE);
    }

    //file output
    lastPrintElem = arrWork + cntWorkElem;
    write_file(file, arrWork, lastPrintElem);

    fclose(file);

    // ������� ��������

    free(arrInp);
    free(arrWork);

    return 0;
}


