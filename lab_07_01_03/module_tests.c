#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "functions.h"

int compare_int(const void *i, const void *j)
{
    return *(int*)i - *(int*)j;
}

int compare_char(const void *i, const void *j)
{
    return *(char*)i - *(char*)j;
}
int main(void)
{
    unsigned long long tb, te;
    FILE * f1;
    FILE * f2;
    FILE * f3;
    FILE * f4;
    int ko = OK, *lastPrint = NULL;

    tb = tick();

    f1 = fopen("in_1.txt", "r");
    f2 = fopen("in_2.txt", "r");
    f3 = fopen("in_3.txt", "r");
    f4 = fopen("in_4.txt", "r");

    if (f1 == NULL)
    {
        printf("1st File does not exist");
        ko = ERROR_FILE_NOT_EXISTS;
    }
    else if (f2 == NULL)
    {
        printf("2nd File does not exist");
        ko = ERROR_FILE_NOT_EXISTS;
    }
    else if (f3 == NULL)
    {
        printf("3rd File does not exist");
        ko = ERROR_FILE_NOT_EXISTS;
    }
    else if (f4 == NULL)
    {
        printf("4th File does not exist");
        ko = ERROR_FILE_NOT_EXISTS;
    }
    else
    {
        printf("                    1st file | 2nd file | 3rd file | 4th file\n");
        int m = 0;
        ko = countFileData(f1, &m);
        printf("seekquantity()       ");
        if (m == 8 && ko == OK)
        {
            printf(" Right     ");
        }
        else
        {
            printf(" ERROR     ");
        }
        m = 0;
        ko = countFileData(f2, &m);
        if (m == 0 && ko == ERROR_FILE_EMPTY)
        {
            printf(" Right     ");
        }
        else
        {
            printf(" ERROR     ");
        }
        m = 0;
        ko = countFileData(f3, &m);
        if (m == 7 && ko == OK)
        {
            printf(" Right     ");
        }
        else
        {
            printf(" ERROR     ");
        }
        m = 0;
        ko = countFileData(f4, &m);
        if (m == 0 && ko == ERROR_FILE_NOT_EXISTS)
        {
            printf(" Right     ");
        }
        else
        {
            printf(" ERROR     ");
        }

        printf("\nwritearray()         ");
        int *arr_1;
        int *pointer_on_last_arr_1;

        int arr_true_1[] = { 1, 2, 3, 4, -5, 3, 2, 1 };
        arr_1 = (int*)malloc(8 * sizeof(int));
        pointer_on_last_arr_1 = arr_1 + 8;
        rewind(f1);
        ko = loadFileData(f1, arr_1, pointer_on_last_arr_1);
        if (ko == OK)
        {
            for (int i = 0; i < 8; i++)
            {
                if (arr_1[i] != arr_true_1[i])
                {
                    printf(" ERROR     ");
                    ko = ERR_TEST;
                    break;
                }
            }
        }
        if (ko != ERR_TEST)
        {
            printf(" Right     ");
        }
        free(arr_1);

        printf(" -----     ");
        printf(" -----     ");

        arr_1 = (int*)malloc(5 * sizeof(int));
        pointer_on_last_arr_1 = arr_1 + 5;
        rewind(f4);
        ko = loadFileData(f4, arr_1, pointer_on_last_arr_1);
        if (ko == ERROR_FILE_DATA_STRUCTURE)
        {
            printf(" Right     ");
        }
        else
        {
            printf(" ERROR     ");
        }
        free(arr_1);

        printf("\nkey()                ");
        ko = OK;
        int arr_2[] = { 1, 2, 3, 4, -5, 3, 2, 1 };
        int *pointer_on_last_arr_2 = arr_2 + 8;
        int arr_true_2[] = { 1, 2, 3, 4 };
        int *arr_filtered_2;
        int *pointer_on_last_filter_2;
        const int *arr_c_2 = arr_2;
        const int *pointer_on_last_arr_c_2 = pointer_on_last_arr_2;
        ko = key(arr_c_2, pointer_on_last_arr_c_2, &arr_filtered_2, &pointer_on_last_filter_2);
        if (ko == OK)
        {
            int i = 0;
            while (i < 4)
            {
                if (arr_filtered_2[i] != arr_true_2[i])
                {
                    printf(" ERROR     ");
                    ko = ERR_TEST;
                    break;
                }
                i++;
            }
        }
        if (ko != ERR_TEST)
        {
            printf(" Right     ");
        }

        printf(" -----     ");

        ko = OK;
        int arr_3[] = { 5, 4, 4, 3, 2, 1, 0 };
        int *pointer_on_last_arr_3 = arr_3 + 7;
        int arr_true_3[] = { 5, 4, 4, 3, 2, 1, 0 };
        int *arr_filtered_3;
        int *pointer_on_last_filter_3;
        const int *arr_c_3 = arr_3;
        const int *pointer_on_last_arr_c_3 = pointer_on_last_arr_3;
        ko = key(arr_c_3, pointer_on_last_arr_c_3, &arr_filtered_3, &pointer_on_last_filter_3);
        if (ko == OK)
        {
            int i = 0;
            while (i < 7)
            {
                if (arr_filtered_3[i] != arr_true_3[i])
                {
                    printf(" ERROR     ");
                    ko = ERR_TEST;
                    break;
                }
                i++;
            }
        }
        if (ko != ERR_TEST)
        {
            printf(" Right     ");
        }


        ko = OK;
        int arr_4[] = { -1, 1, 2, 3, -4, 5 };
        int *pointer_on_last_arr_4 = arr_4 + 6;
        int *arr_filtered_4;
        int *pointer_on_last_filter_4;
        const int *arr_c_4 = arr_4;
        const int *pointer_on_last_arr_c_4 = pointer_on_last_arr_4;
        ko = key(arr_c_4, pointer_on_last_arr_c_4, &arr_filtered_4, &pointer_on_last_filter_4);
        if (ko == NONE_ELEMENTS)
        {
            printf(" Right     ");
        }
        else
        {
            printf(" ERROR     ");
        }

        FILE *file1;
        
        file1 = fopen("out_1.txt", "w");

        printf("\nmysort()             ");
        ko = OK;
        arr_filtered_2 = arr_2;
        tick();
        pointer_on_last_filter_2 = arr_filtered_2 + 8;
        mysort(arr_filtered_2, fabs((size_t)(pointer_on_last_filter_2 - arr_filtered_2)),
            sizeof (int), compare_int);
        int arr_true_2_s[] = { -5, 1, 1, 2, 2, 3, 3, 4 };
        int i = 0;
        lastPrint = arr_true_2_s + 7;
        write_file(file1, arr_filtered_2, lastPrint);
        printArray("Input Array", arr_true_2_s, lastPrint);
        fclose(file1);
        while (i < 8)
        {
            if (arr_filtered_2[i] != arr_true_2_s[i])
            {
                printf(" ERROR     ");
                ko = ERR_TEST;
                break;
            }
            i++;
        }
        if (ko != ERR_TEST)
        {
            printf(" Right     ");
        }
        //

        printf(" -----     ");

        ko = OK;
        arr_filtered_3 = arr_3;
        pointer_on_last_filter_3 = arr_filtered_3 + 7;
        mysort(arr_filtered_3, fabs((size_t)(pointer_on_last_filter_3 - arr_filtered_3)),
            sizeof (int), compare_int);
        int arr_true_3_s[] = { 0, 1, 2, 3, 4, 4, 5 };
        i = 0;
        while (i < 7)
        {
            if (arr_filtered_3[i] != arr_true_3_s[i])
            {
                printf(" ERROR     ");
                ko = ERR_TEST;
                break;
            }
            i++;
        }
        if (ko != ERR_TEST)
        {
            printf(" Right     ");
        }
        //free(arr_filtered_3);


        ko = OK;
        char arr_filtered_5[] = { 'c', 'b', 'd', 'a', 'g', 'f','1', 'e', 'a' };
        //double arr_filtered_5[] = {5 , 3.55, 5.23, -5.544, 2.6};
        char *pointer_on_last_filter_5 = arr_filtered_5;
        //double *pointer_on_last_filter_5 = arr_filtered_5;
        pointer_on_last_filter_5 += 9;
        mysort(arr_filtered_5, fabs((size_t)(pointer_on_last_filter_5 - arr_filtered_5)),
            sizeof(char), compare_char);
        char arr_true_5_s[] = { '1','a','a', 'b', 'c', 'd', 'e', 'f', 'g' };
        //double arr_true_5_s[] = {-5.544, 2.6, 3.55, 5, 5.23};
        i = 0;
        while (i < 9)
        {
            //printf("%c ", arr_filtered_5[i]);
            if (arr_filtered_5[i] != arr_true_5_s[i])
            {
                printf(" ERROR     ");
                ko = ERR_TEST;
                break;
            }
            i++;
        }
        if (ko != ERR_TEST)
        {
            printf(" Right     ");
        }

    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);

    printf("\nko = %i", ko);
    te = tick();
    printf("Time tests: %llu\n", (te - tb) / 100);
    return ko;
}
