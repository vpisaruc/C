

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ZERO_ELEMENTS_ARRAY -1
#define ARRAY_OVERCOMING -2
#define DATA_ERROR -3






// Menu function
int getMenuItem()
{
	int item_menu = -1;
    while (item_menu < 0 || item_menu > 9)
	{
		printf("\n\n___________________________________________________\n\n");
		printf("1.Vvod masssiva\n");
		printf("2.Testovie dannie\n");
		printf("3.Summa 4etnyh i proizvedenie ne4etnyh\n");
		printf("4.Perezapisi elementov bolishe srednego\n");
		printf("5.Udalenie otricatelinyh\n");
		printf("6.Dobavlenie summy posle ravnyh\n");
		printf("7.Obmen max 4etnogo i min ne4etnogo\n");
		printf("8.Zapisi summy s poslednei 3 vmesto Max kratnogo 3\n");
		printf("9.Sortirovka elementov mejdu Min i Max\n");
		printf("0.Vyhod\n");
		printf("\n\n___________________________________________________\n\n");

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

	printf("Vvedite elementy massiva: \n");
	for (int i = 0; i<cnt; i++)  
	{
		printf("\nElement %2d massiva = ", i);
		scanf("%d", &arrWork[i]);
	}

	printf("\n\n");

	return cnt;
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
int sumAndMultElements(int *arrWork, int cnt)
{
	int sumElem = 0, multElem = 1;


	if (cnt != 0)
	{
	    for (int i = 0; i < cnt; i++)
	    {
		    if (((i / 2) * 2 - i) == 0)
            {
                sumElem = sumElem + arrWork[i];
            }
		    else
            {
			    multElem = multElem * arrWork[i];
            }
	    }

	    printf("Summa 4etnyh i proizvedenie ne4etnyh\n\n");


	    printArray(arrWork, cnt, 0);


	    printf("Summa 4etnyh = %d;   Proizvedenie ne4etnyh = %d\n\n", sumElem, multElem);
        return OK;
    }
return ZERO_ELEMENTS_ARRAY;
}

// Output elements bigger then average
int elemMoreAverage(int *arrWork, int cnt)
{
	int  arrResult[10], cntRes = 0;
	int sumElem = 0;
	double arrAvg;


	if (cnt == 0)
	{
		printf("Net dannyh dlia ras4eta. Vypolnite p.1 ili p.2 menu\n\n");
		return ZERO_ELEMENTS_ARRAY;
	}


	for (int i = 0; i < cnt; i++)
    {
		sumElem = sumElem + arrWork[i];
    }

	arrAvg = (double)sumElem / cnt;


	for (int i = 0; i < cnt; i++)
	{
		if ((double)arrWork[i] > arrAvg)
		{
			arrResult[cntRes] = arrWork[i];
			cntRes++;
		}
	}

	printf("Elementy bolishe srednego\n\n");


	printArray(arrWork, cnt, 0);


	printf("Srednee zna4enie = %6.1f\n\n", arrAvg);


	printArray(arrResult, cntRes, 1);
    return OK;

}


// Deliting negative elements
int delNegative(int *arrWork, int cnt)
{
	int  arrResult[10], cntRes = 0;


	if (cnt == 0)
	{
		printf("Net dannyh dlia ras4eta. Vypolnite p.1 ili p.2 menu\n\n");
		return ZERO_ELEMENTS_ARRAY;
	}


	for (int i = 0; i < cnt; i++)
	{
		if (arrWork[i] > 0)
		{
			arrResult[cntRes] = arrWork[i];
			cntRes++;
		}
	}

	printf("Udalenie otricatelinyh\n\n");


	printArray(arrWork, cnt, 0);
	printArray(arrResult, cntRes, 1);
    return OK;

}


// Additions after the elements equal to the entered number, the sum of the elements preceding it
int insSumAfterValue(int *arrWork, int cnt)
{
	int  arrResult[20], cntRes = 0, sumElem = 0, compareValue;


	if (cnt == 0)
	{
		printf("Net dannyh dlia ras4eta. Vypolnite p.1 ili p.2 menu\n\n");
		return ZERO_ELEMENTS_ARRAY;
	}


	printf("Vvedite 4islo dlia sravnenia:\n");
	scanf("%d", &compareValue);


	for (int i = 0; i < cnt; i++)
	{
		arrResult[cntRes] = arrWork[i];
		cntRes++;

		if (arrWork[i] == compareValue)
		{
			// Dopolnitelinii element
			arrResult[cntRes] = sumElem;
			cntRes++;
		}

		sumElem = sumElem + arrWork[i];
	}

	printf("Dobavlenie summy posle ravnyh\n\n");
	printArray(arrWork, cnt, 0);


	printArray(arrResult, cntRes, 1);
    return OK;
}


// Exchange in the array the maximum element among the even and the minimum element among the odd
int changeMinMax(int *arrWork, int cnt)
{
	int  arrResult[10], maxValue, maxIdx = 1, minValue, minIdx = 0;


	if (cnt == 0)
	{
		printf("Net dannyh dlia ras4eta. Vypolnite p.1 ili p.2 menu\n\n");
		return ZERO_ELEMENTS_ARRAY;
	}
	if (cnt == 1)
	{
		printf("Razmernosti massiva doljna byti >= 2\n\n");
		return DATA_ERROR;
	}
	
	// nachalinie znacheniia min and max
	maxValue = arrWork[maxIdx];
	minValue = arrWork[minIdx];


	for (int i = 0; i < cnt; i++)
	{
		if (((i / 2) * 2 - i) != 0)
		{
			if (arrWork[i] > maxValue)
			{
				maxIdx = i;
				maxValue = arrWork[i];
			}
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

	for (int i = 0; i < cnt; i++)
	{
		if (i == minIdx)
        {
			arrResult[i] = arrWork[maxIdx];
        }
		else if (i == maxIdx)
        {
			arrResult[i] = arrWork[minIdx];
        }
		else
        {
			arrResult[i] = arrWork[i];
        }
	}

	printf("Obmen max 4etnogo i min ne4etnogo\n\n");


	printArray(arrWork, cnt, 0);
	printArray(arrResult, cnt, 1);

    return OK;
}


int changeMax3(int *arrWork, int cnt)
{
	int  arrResult[10], maxValue, maxIdx = -1, sumElem3 = 0;

	if (cnt == 0)
	{
		printf("Net dannyh dlia ras4eta. Vypolnite p.1 ili p.2 menu\n\n");
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
		printf("Net 4isel deliashihsia na 3 v  massive\n\n");
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

	printf("Zapisi summy s poslednei 3 vmesto Max kratnogo 3\n\n");
	printArray(arrWork, cnt, 0);
	printArray(arrResult, cnt, 1);
    return OK;
}


// Ordering of elements located between the minimum and maximum elements of the array
int sortMinMax(int *arrWork, int cnt)
{
	int  arrResult[10], maxValue, maxIdx = 0, minValue, minIdx = 0;


	if (cnt == 0)
	{
		printf("Net dannyh dlia ras4eta. Vypolnite p.1 ili p.2 menu\n\n");
		return ZERO_ELEMENTS_ARRAY;
	}
	if (cnt == 1)
	{
		printf("Razmernosti massiva doljna byti >= 2\n\n");
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

	printf("Sortirovka elementov mejdu Min i Max\n\n");

    printArray(arrWork, cnt, 0);


	printArray(arrResult, cnt, 1);
    return OK;
}






// main function

int main()

{

	int arrWork[10];

	int k = 0;

	int cntEl = 0;

	

	while (k == 0)

	{

		switch (getMenuItem())
		{
		    case 1:
            {
            
			    cntEl = inputTestData(arrWork);
			    printArray(arrWork, cntEl, 0);
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
                sumAndMultElements(arrWork, cntEl);
                break;
			    
            }
		    case 4:
            {
			    elemMoreAverage(arrWork, cntEl);
			    break;
            }
		    case 5:
            {
			    delNegative(arrWork, cntEl);
			    break;
            }
		    case 6:
			    insSumAfterValue(arrWork, cntEl);
			    break;
		    case 7:
            {
			    changeMinMax(arrWork, cntEl);
			    break;
            }
		    case 8:
            {
			    changeMax3(arrWork, cntEl);
			    break;
            }
		    case 9:
            {
			    sortMinMax(arrWork, cntEl);
			    break;
            }
		    case 0:
            {
			    k = 1;
			    break;
            }
		}
	}

	return 0;
}
