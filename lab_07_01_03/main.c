#include <stdio.h>
#include <malloc.h>

#include "functions.h"


int main(int argc, char **argv)
{
    FILE *file;
    int retVal, cntElem, cntWorkElem;
    int *arrInp, *arrWork, *idxWork, *afterLastElem, *lastPrintElem;
    
    unsigned long long tb, te;

    // �������� ����� c ��������� ������� ��� ������
    file = fopen("in_z.txt", "r");
    if (file == NULL)
    {
        printf("Error: File in_z.txt not exists");
        getchar();

        return ERROR_FILE_NOT_EXISTS;
    }

    // ������� ���������� ���������
    retVal = countFileData(file, &cntElem);
    if (retVal < 0)
    {
        // ������� ���� ������
        printf("Error = %d\n\nInput any key for Exit", retVal);
        getchar();

        return retVal;
    }

    // ��������� ������
    arrInp = (int*)malloc(cntElem * sizeof(int));
    arrWork = (int*)malloc(cntElem * sizeof(int));
    afterLastElem = arrInp + cntElem;
    
    // �������� ������
    retVal = loadFileData(file, arrInp);
    if (retVal < 0)
    {
        // ������� ���� ������
        printf("Error = %d\n\nInput any key for Exit", retVal);
        getchar();

        return retVal;
    }

    // �������� �����
    fclose(file);

    // ������ �������� �������
    lastPrintElem = afterLastElem - 1;
    printArray(0, arrInp, lastPrintElem);

    // ���������� � ���������� ������ � ������� ������
    filterData(arrInp, afterLastElem, arrWork, &cntWorkElem);

    // ������ ���������������� �������
    lastPrintElem = arrWork + cntWorkElem - 1;
    printArray(1, arrWork, lastPrintElem);

    // ���������� ���������������� �������
    tb = tick();
    sortArray(arrWork, cntWorkElem, sizeof(int), compareFunc);
    te = tick();
    
    printf("\n\ntest 'time': %llu\n\n", (te - tb));
    // ������ ���������������� �������
    lastPrintElem = arrWork + cntWorkElem - 1;
    printArray(1, arrWork, lastPrintElem);

    // ������ ������ � ����
    file = fopen("out_z.txt", "w");
    if (file == NULL)
    {
        printf("Error: Can't open file out_z.txt for write");
        getchar();

        return ERROR_FILE_OPEN_WRITE;
    }
    // ������ �������
    idxWork = arrWork;
    lastPrintElem = arrWork + cntWorkElem - 1;
    while (idxWork <= lastPrintElem)
    {
        fprintf(file, "%d ", *idxWork);
        idxWork++;
    }
    fclose(file);

    // ������� ��������
    free(arrWork);
    free(arrInp);

    printf("Ok. Input any key for Exit");
    getchar();

    return 0;
}

