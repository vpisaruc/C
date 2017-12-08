#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#include "functions.h"


int main(int argc, char **argv)
{
    FILE * file = NULL, * file1 = NULL;
    int retVal, cntElem, cntWorkElem;
    int *arrInp = NULL, *arrWork = NULL, *afterLastElem = NULL, *lastPrintElem = NULL, *afterLastElemWork = NULL;
    int out;
    // �������� ����� c ��������� ������� ��� ������
    if (argc < 3 || argc > 4)
    {
        out = COMMAND_LINE_ERROR;
        printf("Incorrect data was entered");
    }
    else
    {
        file =  fopen(argv[1], "r");
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
                    free(arrInp);
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
                        free(arrInp);
                        out = retVal;
                    }
                    else
                    {
                        // �������� �����

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
                                else if (out == INCORRECT_PARAM)
                                {
                                    printf("\nIncorrect parametres\n");
                                    free(arrInp);
                                    out = INCORRECT_PARAM;
                                }
                                else if (out == NONE_ELEMENTS)
                                {
                                    printf("\nNone elements before negative\n");
                                    free(arrInp);
                                    out = NONE_ELEMENTS;
                                }
                                else if (out == SIZE_ERROR)
                                {
                                    printf("Size error");
                                    free(arrInp);
                                    free(arrWork);
                                    out = SIZE_ERROR;
                                }
                                else
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
                                file1 = fopen(argv[argc - 2], "w");
                            }
                            else if (argc == 3)
                            {
                                file1 = fopen(argv[argc - 1], "w");
                            }
                            if (file1 == NULL)
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

                            fclose(file1);
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
        fclose(file);
    }
    printf("\nProgram finished with exit code = %i\n", out);
    return out;
}

