#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "functions.h"


int main(int argc, char **argv)
{
    FILE *file;
    int retVal, cntElem, cntWorkElem, cntQsort;
    int *arrInp, *arrWork, *arrQsort, *afterLastElem, *lastPrintElem;
    unsigned long long tb_mySort, te_mySort, tb_qSort, te_qSort;
    
    
    // �������� ����� c ��������� ������� ��� ������
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
    if(!arrInp)
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
    if(argc == 4)
    {
        if (*argv[argc - 1] == 'f')
        {
        
            int **arrWorkPtr, **cntWorkElemPtr;
            arrWorkPtr = (int**)malloc(sizeof(int*));
            cntWorkElemPtr = (int**)malloc(sizeof(int*));
            retVal = key(arrInp, afterLastElem, arrWorkPtr, cntWorkElemPtr);
            if(retVal == MEMMORY_ERROR)
            {
                printf("\nMemory error\n");
                exit(MEMMORY_ERROR);
            }
            if(retVal == INCORRECT_PARAM)
            {
                printf("\nIncorrect parametres\n");
                exit(INCORRECT_PARAM);
            }

            arrWork = *arrWorkPtr;
            cntWorkElem = **cntWorkElemPtr;
            arrQsort = *arrWorkPtr;
            cntQsort = **cntWorkElemPtr;
            
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
        arrQsort = arrInp;
        cntQsort = cntElem;
    }
    
    



    // ���������� ����������������/������������������ ������� � ����� �������
    tb_mySort = tick();
    mysort(arrWork, cntWorkElem, sizeof(int), compareFunc);
    te_mySort = tick();
    printf("\nTime of mySort func: %llu\n ", (te_mySort - tb_mySort));
    
    
    tb_qSort = tick();
    qsort(arrQsort, cntQsort, sizeof(int), compareFunc);
    te_qSort = tick();
    printf("\nTime of qSort func: %llu\n\n ", (te_qSort - tb_qSort));

    // ������ ���������������� �������
    lastPrintElem = arrWork + cntWorkElem;
    printArray("Sorting Array with mysort", arrWork, lastPrintElem);
    printArray("Sorting Array with Qsort", arrQsort, lastPrintElem);

    // ������ ������ � ����
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

        exit(ERROR_FILE_OPEN_WRITE);
    }
    // ������ �������

    lastPrintElem = arrWork + cntWorkElem;

    write_file(file, arrWork, lastPrintElem);

    fclose(file);

    // ������� ��������
    free(arrInp);
    if(argc == 4)
    {
        if (argv[argc - 1] == 0)
        {
            // ��������� ������ ��� ����������
            free(arrWork);
        }
    }

    printf("Ok. Input any key for Exit");
    

    return 0;
}


