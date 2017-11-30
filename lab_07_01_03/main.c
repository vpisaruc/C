#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "functions.h"


int main(int argc, char **argv)
{
    FILE * file;
    int retVal, cntElem, cntWorkElem;
    int *arrInp = NULL, *arrWork = NULL, *afterLastElem = NULL, *lastPrintElem = NULL, *idxWork = NULL;
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

    // ��������� ������
    arrInp = (int*)malloc(cntElem * sizeof(int));
    if (!arrInp)
    {
        printf("\nMemory allocation error\n");
        exit(MEMMORY_ERROR);
    }
    afterLastElem = arrInp + cntElem;
    
    // �������� ������
    retVal = loadFileData(file, arrInp, &cntElem);
    if (retVal < 0)
    {
        // ������� ���� ������
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
            int **arrWorkPtr, **arrWorkAfterPtr;
            arrWorkPtr = (int**)malloc(sizeof(int*));
            arrWorkAfterPtr = (int**)malloc(sizeof(int*));
            retVal = key(arrInp, afterLastElem, arrWorkPtr, arrWorkAfterPtr);
            if (retVal == MEMMORY_ERROR)
            {
                printf("\nMemory error\n");
                exit(MEMMORY_ERROR);
            }
            if (retVal == INCORRECT_PARAM)
            {
                printf("\nIncorrect parametres\n");
                exit(INCORRECT_PARAM);
            }

            if (retVal == NONE_ELEMENTS)
            {
                printf("\nNone elements before negative\n");
                exit(NONE_ELEMENTS);
            }

            if (retVal == SIZE_ERROR)
            {
                printf("Size error");
                exit(SIZE_ERROR);
            }

            arrWork = *arrWorkPtr;
            idxWork = *arrWorkAfterPtr;
            cntWorkElem = idxWork - arrWork;

            
            // ������ ���������������� �������
            lastPrintElem = arrWork + cntWorkElem;
            printArray("Filtered Array", arrWork, lastPrintElem);
        }
    }
    else
    {
        // ��� ����������
        arrWork = arrInp;
        cntWorkElem = cntElem;
    }
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

        exit(ERROR_FILE_OPEN_WRITE);
    }
    // ������ �������

    lastPrintElem = arrWork + cntWorkElem;

    write_file(file, arrWork, lastPrintElem);

    fclose(file);

    // ������� ��������
    free(arrInp);
    if (argc == 4)
    {
        if (argv[argc - 1] == 0)
        {
            // ��������� ������ ��� ����������
            free(arrWork);
        }
    }



    return 0;
}


