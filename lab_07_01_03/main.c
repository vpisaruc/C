#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "functions.h"


int main(int argc, char **argv)
{
    FILE * file = NULL;
    int retVal, cntElem, cntWorkElem;
    int *arrInp = NULL, *arrWork = NULL, *afterLastElem = NULL, *lastPrintElem = NULL, *afterLastElemWork = NULL;
    int out;
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
        out = ERROR_FILE_NOT_EXISTS;
    }
    else
    {
        // ������� ���������� ���������
        retVal = countFileData(file, &cntElem);
        if (retVal < 0)
        {
            // ������� ���� ������
            printf("Error = %d\n\nInput any key for Exit", retVal);
            out = retVal;
        }
        else
        {
            // ��������� ������
            arrInp = (int*)malloc(cntElem * sizeof(int));
            if (!arrInp)
            {
                printf("\nMemory allocation error\n");
                out = MEMMORY_ERROR;
            }
            else
            {
                afterLastElem = arrInp + cntElem;
                arrWork = arrInp;
                afterLastElemWork = afterLastElem;

                // �������� ������
                retVal = loadFileData(file, arrInp, &cntElem);
                if (retVal < 0)
                {
                    // ������� ���� ������
                    printf("Error = %d\n\nInput any key for Exit", retVal);
                    out = retVal;
                }
                else
                {
                    // �������� �����
                    fclose(file);

                    // ������ �������� �������
                    lastPrintElem = afterLastElem;
                    printArray("Input Array", arrInp, lastPrintElem);

                    cntWorkElem = cntElem;

                    // ���������� � ���������� ������ � ������� ������
                    if (argc == 4)
                    {
                        if (*argv[argc - 1] == 'f')
                        {
                            out = key(arrInp, afterLastElem, &arrWork, &afterLastElemWork);
                            if (out == MEMMORY_ERROR)
                            {
                                printf("\nMemory error\n");
                                free(arrInp);
                                free(arrWork);
                                out = MEMMORY_ERROR;
                            }
                            if (out == INCORRECT_PARAM)
                            {
                                printf("\nIncorrect parametres\n");
                                free(arrInp);
                                out = INCORRECT_PARAM;
                            }
                            if (out == NONE_ELEMENTS)
                            {
                                printf("\nNone elements before negative\n");
                                free(arrInp);
                                out = NONE_ELEMENTS;
                            }
                            if (out == SIZE_ERROR)
                            {
                                printf("Size error");
                                free(arrInp);
                                free(arrWork);
                                out = SIZE_ERROR;
                            }
                            if(out == OK)
                            {
                                cntWorkElem = afterLastElemWork - arrWork;

                                // ������ ���������������� �������
                                lastPrintElem = arrWork + cntWorkElem;
                                printArray("Filtered Array", arrWork, lastPrintElem);
                            }
                        }
                        else
                        {
                            free(arrInp);
                            printf("To use filter print [f]");
                            out = COMMAND_LINE_ERROR;
                        }
                    }

                    if(out == OK)
                    {
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
                            free(arrInp);
                            if (argc == 4)
                            {
                                free(arrWork);
                            }
                            out = ERROR_FILE_NOT_EXISTS;
                        }
                        // ������ �������

                        lastPrintElem = arrWork + cntWorkElem;

                        write_file(file, arrWork, lastPrintElem);

                        fclose(file);
                        // ������� ��������

                        free(arrInp);
                        if (argc == 4)
                        {
                            free(arrWork);
                        }
                    }
                }
            }
        }    
    }       
    return out;
}

