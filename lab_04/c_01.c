
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ZERO_ELEMENTS_ARRAY -1
#define ARRAY_OVERCOMING -2
#define DATA_ERROR -3
#define CNT_ERROR -4
#define NON_EVEN -5
#define NON_ODD -6




// Menu function
int getMenuItem()
{
    int item_menu = -1;
    while (item_menu < 0 || item_menu > 9)
    {
        printf("\n\n_________________________________________________________________________________________________\n\n");
        printf("1.Input array\n");
        printf("2.Test data\n");
        printf("3.Summ of even elements and multiply of odd\n");
        printf("4.Rewriting elements bigger then average\n");
        printf("5.Deliting minus numbers\n");
        printf("6.Add summ after equal elements\n");
        printf("7.Change max even and min odd\n");
        printf("8.Writing the place of the maximum element, divisible by 3, the sum of the elements ending in 3\n");
        printf("9.Sort elements between min and max\n");
        printf("0.Exit\n");
        printf("\n\n__________________________________________________________________________________________________\n\n");

        scanf("%d", &item_menu);
        printf("\n\n\n");

    } 


    return item_menu;
}




int inputTestData(int *arrWork)
{
    int cnt;


    printf("Vvedite razmernosti massiva:\n");
    scanf("%d", &cnt);
    if (cnt > 0)
    {
        printf("Vvedite elementy massiva: \n");
        for (int i = 0; i<cnt; i++)  
        {
            printf("\nElement %2d massiva = ", i);
            scanf("%d", &arrWork[i]);
        }

        printf("\n\n");
        return cnt;
    }

    else
    {
        return CNT_ERROR;
    }

}




// Test data
int setTestData(int *arrWork)
{
    int cnt = 10;
    int  arrTest[10] = { 3, -13, 23, 16, -1, 33, 24, 48, 33, 11 };

    for (int i = 0; i < cnt; i++)
    {
        arrWork[i] = arrTest[i];
    }
    return cnt;
}


int printArray(int *arrWork, int cnt, int signResult)
    {
    if (signResult == 0)
    {
        printf("Ishodnyi massiv\n\n");
    }
    else
    {
        printf("Massiv resulitatov\n\n");
    }
    for (int i = 0; i < cnt; i++)
    {
        printf("%4d", arrWork[i]);
    }
    printf("\n\n");
    return OK;
}


// Sum of even  and mult odd
int sumAndMultElements(int *arrWork, int *sumElem, int *multElem, int cnt )
{

    if (cnt != 0)
    {
        for (int i = 0; i < cnt; i++)
        {
            if (((i / 2) * 2 - i) == 0)
            {
                *sumElem = *sumElem + arrWork[i];
            }
            else
            {
                *multElem = *multElem * arrWork[i];
            }
        }

        return OK;
    }
return ZERO_ELEMENTS_ARRAY;
}

// Output elements bigger then average
int elemMoreAverage(int *arrWork, int cnt, int  *arrResult, double *arrAvg ,int *cntRes )
{

    int sumElem = 0;
    int idx = 0;


    if (cnt == 0)
    {
        return ZERO_ELEMENTS_ARRAY;
    }


	for (int i = 0; i < cnt; i++)
    {
        sumElem = sumElem + arrWork[i];
    }

    *arrAvg = (double)sumElem / cnt;


    for (int i = 0; i < cnt; i++)
    {
        if ((double)arrWork[i] > *arrAvg)
        {
            arrResult[idx] = arrWork[i];
            idx++;
        }
    }

    *cntRes = idx;


    //printArray(arrWork, cnt, 0);



    return OK;

}


// Deliting negative elements
int delNegative(int *arrWork, int cnt, int *arrResult, int *cntRes)
{
    int idx = 0;

    if (cnt == 0)
    {
        return ZERO_ELEMENTS_ARRAY;
    }


    for (int i = 0; i < cnt; i++)
    {
        if (arrWork[i] > 0)
        {
            arrResult[idx] = arrWork[i];
            idx++;
        }
    }

    *cntRes = idx;


    return OK;

}


// Additions after the elements equal to the entered number, the sum of the elements preceding it
int insSumAfterValue(int *arrWork, int cnt, int *arrResult, int *cntRes, int *compareValue)
{
    int sumElem = 0, idx = 0;


    if (cnt == 0)
    {
       return ZERO_ELEMENTS_ARRAY;
    }





    for (int i = 0; i < cnt; i++)
    {
        arrResult[idx] = arrWork[i];
        idx++;

        if (arrWork[i] == *compareValue)
        {
            // Dopolnitelinii element
            arrResult[idx] = sumElem;
            idx++;
        }

        sumElem = sumElem + arrWork[i];
    }
    *cntRes = idx;

    return OK;
}


// Exchange in the array the maximum element among the even and the minimum element among the odd
int changeMinMax(int *arrWork, int cnt , int *arrResult, int *cntRes)
{
    int maxValue, maxIdx = -1, minValue, minIdx = -1;


    if (cnt == 0)
    {
        return ZERO_ELEMENTS_ARRAY;
    }
    if (cnt == 1)
    {
        return DATA_ERROR;
    }


    for (int i = 0; i < cnt; i++)
    {
        if (((arrWork[i] / 2) * 2 - arrWork[i]) == 0)
        {

            if (maxIdx == -1)
            {

                maxIdx = i;
                maxValue = arrWork[i];
            }
            else
            {

                if (arrWork[i] > maxValue)
                {
                    maxIdx = i;
                    maxValue = arrWork[i];
                }
            }
        }
        else
        {

            if (minIdx == -1)
            {

                minIdx = i;
                minValue = arrWork[i];
            }
            else
            {

                if (arrWork[i] < minValue)
                {
                    minIdx = i;
                    minValue = arrWork[i];
                }
            }
        }
    }
    
    if (minIdx == -1)
    {
        return NON_ODD;
    }

    if (maxIdx == -1)
    {
        return NON_EVEN;
    }

    for (int i = 0; i < cnt; i++)
    {
        if (i == minIdx)
            arrResult[i] = arrWork[maxIdx];
        else if (i == maxIdx)
            arrResult[i] = arrWork[minIdx];
        else
            arrResult[i] = arrWork[i];
    }

    *cntRes = cnt;


    return OK;

}


int changeMax3(int *arrWork, int cnt, int *arrResult, int *cntRes)
{
    int maxValue, maxIdx = -1, sumElem3 = 0;

    if (cnt == 0)
    {
        return ZERO_ELEMENTS_ARRAY;
    }

    // Determination of Max values ​​for numbers divisible by 3 without remainder and sum of numbers with the last digit 3
    for (int i = 0; i < cnt; i++)
    {
        if (((arrWork[i] / 3) * 3 - arrWork[i]) == 0)
        {
            if (maxIdx == -1)
            {
                maxIdx = i;
                maxValue = arrWork[i];
            }
            else
            {
                if (arrWork[i] > maxValue)
                {
                    maxIdx = i;
                    maxValue = arrWork[i];
                }
            }
        }
        if (abs(arrWork[i] - (arrWork[i] / 10) * 10) == 3)
        {
            sumElem3 = sumElem3 + arrWork[i];
        }
    }

    if (maxIdx == -1)
    {
        return DATA_ERROR;
    }

    for (int i = 0; i < cnt; i++)
    {
        if (i == maxIdx)
        {
            arrResult[i] = sumElem3;
        }
        else
        {
            arrResult[i] = arrWork[i];
        }
    }

    *cntRes = cnt;

    return OK;
    }


// Ordering of elements located between the minimum and maximum elements of the array
int sortMinMax(int *arrWork, int cnt, int *arrResult, int *cntRes)
{
    int maxValue, maxIdx = 0, minValue, minIdx = 0;


    if (cnt == 0)
    {
        return ZERO_ELEMENTS_ARRAY;
    }
    if (cnt == 1)
    {
        return DATA_ERROR;
    }


    maxValue = arrWork[0];
    minValue = arrWork[0];


    for (int i = 0; i < cnt; i++)
    {
        if (arrWork[i] < minValue)
        {
            minIdx = i;
            minValue = arrWork[i];
        }
        if (arrWork[i] > maxValue)
        {
            maxIdx = i;
            maxValue = arrWork[i];
        }
    }


    for (int i = 0; i < cnt; i++)
    {
        arrResult[i] = arrWork[i];
    }
    // sort betwen min and max
    if (minIdx > maxIdx)	
    {
        maxValue = maxIdx;
        maxIdx = minIdx;
        minIdx = maxValue;
    }

    //sort 
    int minPosition;
    for (int i = minIdx; i < maxIdx; i++)
    {
        minPosition = i;
        for (int j = i + 1; j < maxIdx; j++)
        {
            if (arrResult[minPosition] > arrResult[j])
            {
                minPosition = j;
            }
        }
        maxValue               = arrResult[minPosition];
        arrResult[minPosition] = arrResult[i];
        arrResult[i]           = maxValue;
    }

    *cntRes = cnt;

    return OK;
}






// main function

int main()

{

    int arrWork[10];



    int k = 0;

    int cntEl = 0;

    int retVal;

    int  arrResult[20];

    int cntRes = 0;



    while (k == 0)

    {

        switch (getMenuItem())
        {
            case 1:
            {
                
                cntEl = inputTestData(arrWork);
                if(cntEl == CNT_ERROR)
                {
                    printf("\nInput positive counts of elements in array\n");
                }
                else
                {
                    printArray(arrWork, cntEl, 0);
                }
                break;
            }
            case 2:
            {
                cntEl = setTestData(arrWork);
                printArray(arrWork, cntEl, 0);
                break;
            }
            case 3:
            {
                int sumElem = 0, multElem = 1;
                
                retVal = sumAndMultElements(arrWork, &sumElem, &multElem, cntEl);
                if (retVal == OK)
                {
                    printf("Summ of even = %d;   Multiply of odd = %d\n\n", sumElem, multElem);
                }
                else
                {
                    printf("Array have zero elements");
                }
                break;
                
            }
            case 4:
            {

                double arrAvg;
                

                retVal =elemMoreAverage(arrWork, cntEl, arrResult, &arrAvg, &cntRes);
                if (retVal == OK)
                {
                    printf("Average value = %6.1f\n\n", arrAvg);

                    printf("Elements bigger then average value\n\n");
                    printArray(arrResult, cntRes, 1);
                    
                    
                }

                else
                {
                    printf("Array have zero elements");
                }
                break;
            }
            case 5:
            {

                retVal = delNegative(arrWork, cntEl, arrResult, &cntRes);
                if (retVal == OK)
                {
                    printf("Deliting minus numbers\n\n");
                    printArray(arrResult, cntRes, 1);
                }
                else
                {
                    printf("Array have zero elements");
                }
                 break;

            }
            case 6:
            {
                int compareValue;
                printf("Input number to compare :\n");
                scanf("%d", &compareValue);
                retVal = insSumAfterValue(arrWork, cntEl, arrResult, &cntRes, &compareValue);
                if (retVal == OK)
                {
                    printf("Add summ after equal elements\n\n");
                    printArray(arrResult, cntRes, 1);
                }
                else
                {
                    printf("Array have zero elements");
                }
                break;
            }
            case 7:
            {
                retVal = changeMinMax(arrWork, cntEl, arrResult, &cntRes);
                if (retVal == OK)
                {
                    printf("Change max even number and min odd number\n");
                    printArray(arrResult, cntRes, 1);
                    break;
                }
                else if (retVal == ZERO_ELEMENTS_ARRAY)
                {
                    printf("Array have zero elements");
                }
                else if (retVal == NON_ODD)
                {
                    printf("Array have no odd elements");
                }
                else if (retVal == NON_EVEN)
                {
                    printf("Array have no even elements");
                }
                else
                {
                    printf("Array must have more then 1 element");
                }
                break;
            }
            case 8:
            {
                retVal = changeMax3(arrWork, cntEl, arrResult, &cntRes);
                if (retVal == OK)
                {
                    printf("Writing the place of the maximum element, divisible by 3, the sum of the elements ending in 3\n\n");
                    printArray(arrResult, cntRes, 1);
                    break;
                }
                else if (retVal == DATA_ERROR)
                {
                    printf("Array don't contain elements that multiple 3");
                }
                else
                {
                    printf("Array have zero elements ");
                }
                break;
            }
            case 9:
            {
                retVal = sortMinMax(arrWork, cntEl,arrResult, &cntRes);
                if (retVal == OK)
                {
                    printf("Sort between min and max elements\n\n");
                    printArray(arrResult, cntRes, 1);
                    break;
                }
                else if (retVal == DATA_ERROR)
                {
                    printf("Array must have more then 2 elements");
                }
                else
                {
                    printf("Array have zero elements ");
                }
                break;
            }
            case 0:
            {
                k = 1;
                break;
            }
        }
    }

    return OK;
}