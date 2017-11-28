#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#define COMPARE_ERROR -1
#define OK 0

int compare_arrays(int cnt, int array_1[], int array_2[])
{
    int i = 0;
    while(i < cnt)
    {
        if(array_1[i] == array_2[i])
        {
            if(i != (cnt -1))
            {
                i++;
            }
            else
            {
                return OK;
            }
        }
    }
    return COMPARE_ERROR;
}


int compare_arrays_1(int cnt, int array_1[], int *array_2)
{
    int i = 0;
    int *idx;
    
    idx = array_2;
    
    while(i < cnt)
    {
        if(array_1[i] == array_2[i])
        {
            if(i != (cnt -1))
            {
                i++;
                idx++;
            }
            else
            {
                return OK;
            }
        }
    }
    return COMPARE_ERROR;
}


void test_mySort()
{

    printf("TESTS FOR mysort: \n\n" 
    "Test №1: \n"
    "array = {1, 1, 1, -1, 1} \n"
    "result = {-1, 1, 1, 1, 1} \n"
    "Check: ");
    
    
    int arr_t_1[5] = {1, 1, 1, -1, 1};
    int arr_r_1[5] = {-1, 1, 1, 1, 1};
    
    mysort(arr_t_1, 5, sizeof(int), compareFunc);
    
    if (compare_arrays(5, arr_t_1, arr_r_1) == OK)
        printf("Passed\n");
    else
        printf("Failed\n");
    
    printf("TESTS FOR mysort: \n\n" 
    "Test №2: \n"
    "Array = {1} \n"
    "Result = {1} \n"
    "Check:: ");
    
    int arr_t_2[1] = {0};
    int arr_r_2[1] = {0};
    
    mysort(arr_t_2, 1, sizeof(int), compareFunc);
    
    if (compare_arrays(1, arr_t_2, arr_r_2) == OK)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("TESTS FOR mysort: \n\n" 
    "Test №3: \n"
    "Array = {17 -256  -68  455   98 -155   11  243  -70  111 17 -256  -68  455   98 -155   11  243  -70  111} \n"
    "Result = {-256 -256 -155 -155  -70  -70  -68  -68   11   11   17   17   98   98  111  111  243  243  455  455} \n"
    "Check:: ");
    
    int arr_t_3[20] = {17, -256,  -68,  455,   98, -155,   11,  243,  -70,  111, 17, -256,  -68,  455,   98, -155,   11,  243,  -70,  111};
    int arr_r_3[20] = {-256,-256, -155, -155,  -70,  -70,  -68,  -68,   11,   11,   17,   17,   98,   98,  111,  111,  243,  243,  455,  455};
    
    mysort(arr_t_3, 20, sizeof(int), compareFunc);
    
    if (compare_arrays(20, arr_t_3, arr_r_3) == OK)
        printf("Passed\n");
    else
        printf("Failed\n");
}

void test_key()
{
    int cnt_1 = 5;
    int cnt_2 = 5;
    int cnt_3 = 5;
    int cnt_4 = 5;


    int arr_test_1 [5] = {-12, -3, 7, 5, -1};
    int arr_result_1 [5] = {-12, -3, 7, 5, -1};
    
    int arr_test_2 [5] = {-12, 3, 7, 5, 1};
    int arr_result_2 [1] = {-12};
    
    int arr_test_3 [5] = {12, 3, -7, 5, 1};
    int arr_result_3 [5] = {12, 3, -7};
    
    int arr_test_4 [5] = {12, 3, 7, 5, 1};
    int arr_result_4 [5] = {12, 3, 7, 5, 1};
    
    int *end_arr_1 = arr_test_1 + cnt_1;
    int *start_arr_1, *en_arr_1;
    
    int *end_arr_2 = arr_test_2 + cnt_2;
    int *start_arr_2, *en_arr_2;
    
    int *end_arr_3 = arr_test_3 + cnt_3;
    int *start_arr_3, *en_arr_3;
    
    int *end_arr_4 = arr_test_4 + cnt_4;
    int *start_arr_4, *en_arr_4;
    

    printf("TESTS FOR KEY: \n\n"
    "Test №1: \n"
    "array = {-12, -3, 7, 5, -1} \n"
    "result = {-12, -3, 7, 5, -1} \n"
    "Check: ");
    
    key(arr_test_1, end_arr_1, &start_arr_1, &en_arr_1);

    if (memcmp (start_arr_1, arr_result_1, 5*sizeof(int)) == 0)
        printf("Passed \n\n");
    else
        printf("Failed \n\n");
        
    printf("TESTS FOR KEY: \n\n"
    "Test №2: \n"
    "array = {-12, 3, 7, 5, 1} \n"
    "result = {-12} \n"
    "Check: ");
    
    key(arr_test_2, end_arr_2, &start_arr_2, &en_arr_2);
    

    if (memcmp (start_arr_2, arr_result_2, 5*sizeof(int)) != 0)
        printf("Passed \n\n");
    else
        printf("Failed \n\n");
        
    printf("TESTS FOR KEY: \n\n"
    "Test №3: \n"
    "array = {12, 3, -7, 5, 1} \n"
    "result = {12, 3, -7} \n"
    "Check: ");
    
    key(arr_test_3, end_arr_3, &start_arr_3, &en_arr_3);

    if (memcmp (start_arr_3, arr_result_3, 5*sizeof(int)) == 0)
        printf("Passed \n\n");
    else
        printf("Failed \n\n");
        
    printf("TESTS FOR KEY: \n\n"
    "Test №4: \n"
    "array = {12, 3, 7, 5, 1} \n"
    "result = {12, 3, 7, 5, 1} \n"
    "Check: ");
    
    key(arr_test_4, end_arr_4, &start_arr_4, &en_arr_4);

    if (memcmp (start_arr_4, arr_result_4, 5*sizeof(int)) == 0)
        printf("Passed \n\n");
    else
        printf("Failed \n\n");
        
    
}



void test_cnt_file_data()
{

    int cntElem, retVal, cntElem_1, retVal_1, cntElem_2, retVal_2;
    FILE *file, *file1, *file2;
    int test_cntElem = 10, test_retVal_1 = -3, test_retVal_2 = -2;
    file = fopen("in_1.txt","r");
    
    file1 = fopen("in_8.txt", "r");
    file2 = fopen("in_7.txt", "r");
    
    retVal = countFileData(file, &cntElem);
    printf("TESTS FOR countFileData: \n\n" 
    "Test №1: \n"
    "File  = {17 -256  -68  455   98 -155   11  243  -70  111} \n"
    "Result = {10} \n"
    "Check:: ");
    
    if((cntElem == test_cntElem) && (retVal == OK))
    {
        printf("Passed\n");
    }
    else
    {
        printf("Failed\n");
    }
    
    printf("TESTS FOR countFileData: \n\n" 
    "Test №2: \n"
    "File  = {} \n"
    "Result = {Empty file} \n"
    "Check:: ");
    
    retVal_1 = countFileData(file1, &cntElem_1);
    
    if(retVal_1 == test_retVal_1)
    {
        printf("Passed\n");
    }
    else
    {
        printf("Failed\n");
    }
    
    
    printf("TESTS FOR countFileData: \n\n" 
    "Test №3: \n"
    "File  = {a 1 24 443 12 4234 123} \n"
    "Result = {ERROR_FILE_DATA_STRUCTURE} \n"
    "Check:: ");
    
    retVal_2 = countFileData(file2, &cntElem_2);
    
    if(retVal_2 == test_retVal_2)
    {
        printf("Passed\n");
    }
    else
    {
        printf("Failed\n");
    }
    fclose(file1);
    fclose(file);
    fclose(file2);
}


void test_load_file_data()
{
    
    FILE *file, *file1, *file2;
    int *arrInp, *arrInp1, *arrInp2;
    
    
    file = fopen("in_1.txt","r");
    file1 = fopen("in_2.txt", "r");
    file2 = fopen("in_3.txt", "r");
    
    
    int arr_t_1[5] = {1, 1, 1, -1, 1};
    int arr_t_3[20] = {17, -256,  -68,  455,   98, -155,   11,  243,  -70,  111, 17, -256,  -68,  455,   98, -155,   11,  243,  -70,  111};
    int arr_t_2[2] = {-3, -1};
    int retVal;
    
    arrInp = (int*)malloc(5 * sizeof(int));
    arrInp1 = (int*)malloc(2 * sizeof(int));
    arrInp2 = (int*)malloc(20 * sizeof(int));
    
    retVal = loadFileData(file, arrInp, 5);
    printf("TESTS FOR loadFileData: \n\n" 
    "Test №1: \n"
    "File  = {1, 1, 1, -1, 1} \n"
    "Result = {1, 1, 1, -1, 1} \n"
    "Check:: ");
    
    
    
    if ((compare_arrays_1(5, arr_t_1, arrInp) == OK) && (retVal == OK))
        printf("Passed\n");
    else
        printf("Failed\n");
    

    
    printf("TESTS FOR loadFileData: \n\n" 
    "Test №2: \n"
    "File  = {-3 -1} \n"
    "Result = {-3 -1} \n"
    "Check:: ");
    

    
    retVal = loadFileData(file1, arrInp1, 2);
    
    
    if ((compare_arrays_1(2, arr_t_2, arrInp1) == OK) && (retVal == OK))
        printf("Passed\n");
    else
        printf("Failed\n");
    
    
    
    printf("TESTS FOR loadFileData: \n\n" 
    "Test №3: \n"
    "File  = {17 -256  -68  455   98 -155   11  243  -70  111 17 -256  -68  455   98 -155   11  243  -70  111} \n"
    "Result = {17 -256  -68  455   98 -155   11  243  -70  111 17 -256  -68  455   98 -155   11  243  -70  111} \n"
    "Check:: ");
    
    retVal = loadFileData(file2, arrInp2, 20);
    
    if ((compare_arrays_1(20, arr_t_3, arrInp2) == OK) && (retVal == OK))
        printf("Passed\n");
    else
        printf("Failed\n");
        
    free(arrInp);
    free(arrInp1);
    free(arrInp2);
    
    fclose(file);
    fclose(file1);
    fclose(file2);
}



int main(void)
{
    test_mySort();
    test_cnt_file_data();
    test_load_file_data();
    test_key();
    
    return 0;
}
