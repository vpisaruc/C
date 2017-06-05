#include <stdio.h>

#define OK 0
#define DATA_MORE_100 200
#define ERROR_FILE_NOT_EXISTS -1
#define ERROR_FILE_DATA_STRUCTURE -2
#define ERROR_FILE_EMPTY -3



int loadTestData(FILE *file, int *arrInp)
{
    int retVal = 1, cnt = 0, value, *idx;

    idx = arrInp;


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
            case EOF:
            {

                retVal = 0;
                break;
            }
            case 1:
            {
                if (cnt >= 100)
                {
                    return DATA_MORE_100;
                    break;
                }

                if (cnt > 0)
                {
                    idx++;
                }

                *idx = value;
                cnt++;
            }
        }
    }

    if (cnt == 0)
    {
        return ERROR_FILE_EMPTY;
    }
    else
    {
        return cnt;
    }
}






void getMaxSum(int *arrWork, int *lastElem, int *maxSum)
{
    int *leftIdx, *rightIdx, currSum;

    // Начальная сумма
    leftIdx  = arrWork;
    rightIdx = lastElem;
    *maxSum = *leftIdx + *rightIdx;

    printf("Ishodnyi massiv\n\n");

    while (leftIdx <= rightIdx)
    {
        // Текущая сумма
        currSum = *leftIdx + *rightIdx;
        printf("Pair %4d %4d  Sum = %d\n", *leftIdx, *rightIdx, currSum);

        // Проверка на Max
        if (currSum > *maxSum)
        {
            *maxSum = currSum;
        }

        // Следующие элементы
        leftIdx++;
        rightIdx--;
    }

}


void printArray(int *arrWork, int *lastElem)
{
    int *idx;

    // Начальный элемент массива 
    idx = arrWork;

    printf("Ishodnyi massiv\n\n");

    while (idx <= lastElem)
    {
        printf("%4d", *idx);
        idx++;
    }
    printf("\n\n");
}


int main()
{
    FILE *file;
    int arrData[100];            
    int *lastElem;                
    int retVal;
    int maxSum;

    file = fopen("in_z.txt", "r");
    if (file == NULL)
    {
        printf("Error: File in_z.txt not exists");

        return ERROR_FILE_NOT_EXISTS;
    }

    retVal = loadTestData(file, arrData);

    fclose(file);

    if (retVal == ERROR_FILE_DATA_STRUCTURE)
    {
        printf("File doesn't contain integer numbers");

    }
    
    if (retVal == DATA_MORE_100)
    {
        printf("File contain more then 100 elements");

    }
    
    else
    {
        lastElem = arrData + retVal - 1;
        printArray(arrData, lastElem);

        getMaxSum(arrData, lastElem, &maxSum);
        printf("\n\nMax sum = %d\n\n", maxSum);
        return OK;
    }

}




