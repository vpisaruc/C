#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

#define COMPARE_ERROR -1
#define OK 0

int compare_arrays(int row, int column, double **array_1, double array_2[][column])
{
    for(int i = 0; i < row; i++ )
    {
        for(int j = 0; j < column; j++)
        {
            if(array_1[i][j] != array_2[i][j])
            {
                return COMPARE_ERROR;
            }
        }
    }
    return OK;
}


double **fill_matr(int row, int column, double matr_2[][column])
{
    double **matr_1;
    matr_1 = allocate_matrix_solid(row, column);
    matr_1 = init(matr_1, row, column);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            matr_1[i][j] = matr_2[i][j];
        }
    }
    return matr_1;
}


void test_fill_matrix()
{
    printf("TESTS FOR fill_matrix: \n\n" 
    "Test №1: \n"
    "file = 2 3 1 2 3 1 2 3 \n"
    "result = {{1, 2, 3}, {3, 2, 1}} \n"
    "Check: ");
    FILE *file;
    file = fopen("in_1.txt", "r");
    double arr_r_1[2][3] = {{1, 2, 3}, 
                            {3, 2, 1}};
    double **arr_t_1;
    int row, column;

    arr_t_1 = fill_matrix(file, &row, &column);

    if(compare_arrays(row, column, arr_t_1, arr_r_1) == OK)
    {
        printf("Passed\n");
        free(arr_t_1);
    }
    else
    {
        printf("Failed\n");
        free(arr_t_1);
    }

    printf("TESTS FOR fill_matrix: \n\n" 
    "Test №2: \n"
    "file = 3 3 \n"
    "result = ERROR \n"
    "Check: ");
    FILE *file1;
    file1 = fopen("in_6.txt", "r");
    double **arr_t_2;

    arr_t_2 = fill_matrix(file1, &row, &column);

    if(arr_t_2 == NULL)
    {
        printf("Passed\n");
        free(arr_t_2);
    }
    else
    {
        printf("Failed\n");
        free(arr_t_2);
    }

    printf("TESTS FOR fill_matrix: \n\n" 
    "Test №3: \n"
    "file = 2 2 1 a 1 2 \n"
    "result = ERROR \n"
    "Check: ");
    FILE *file2;
    file2 = fopen("in_3.txt", "r");
    double **arr_t_3;

    arr_t_3 = fill_matrix(file2, &row, &column);

    if(arr_t_3 == NULL)
    {
        printf("Passed\n");
        free(arr_t_3);
    }
    else
    {
        printf("Failed\n");
        free(arr_t_3);
    }

    printf("TESTS FOR fill_matrix: \n\n" 
    "Test №4: \n"
    "file = 3 a 1 2 3 1 2 3 1 2 3 \n"
    "result = ERROR \n"
    "Check: ");
    FILE *file3;
    file3 = fopen("in_7.txt", "r");
    double **arr_t_4;

    arr_t_4 = fill_matrix(file3, &row, &column);

    if(arr_t_4 == NULL)
    {
        printf("Passed\n");
        free(arr_t_4);
    }
    else
    {
        printf("Failed\n");
        free(arr_t_4);
    }

    printf("TESTS FOR fill_matrix: \n\n" 
    "Test №5: \n"
    "file = a 3 1 2 3 1 2 3 1 2 3 \n"
    "result = ERROR \n"
    "Check: ");
    FILE *file4;
    file4 = fopen("in_5.txt", "r");
    double **arr_t_5;

    arr_t_5 = fill_matrix(file4, &row, &column);

    if(arr_t_5 == NULL)
    {
        printf("Passed\n");
        free(arr_t_5);
    }
    else
    {
        printf("Failed\n");
        free(arr_t_5);
    }

    fclose(file);
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(file4);
}


void test_matrix_summ()
{
    printf("TESTS FOR matrix_summ: \n\n" 
    "Test №1: \n"
    "matr_1 = {{1 2 3}, {3 2 1}} \n"
    "matr_2 = {{1 2 3}, {3 2 1}} \n"
    "result = {{2, 4, 6}, {6, 4, 2}} \n"
    "Check: \n");

    double arr_matrix_1[2][3] = {{1, 2, 3}, 
                                {3, 2, 1}};
    double arr_matrix_2[2][3] = {{1, 2, 3}, 
                                {3, 2, 1}};
    double **arr_m_1, **arr_m_2, **arr_m_3;

    double arr_t_1[2][3] = {{2, 4, 6}, {6, 4, 2}};

    arr_m_1 = fill_matr(2, 3, arr_matrix_1);
    arr_m_2 = fill_matr(2, 3, arr_matrix_2);

    arr_m_3 = MatrixSumm(2, 3, 2, 3, arr_m_1, arr_m_2);

    if(compare_arrays(2, 3, arr_m_3, arr_t_1) == OK)
    {
        printf("Passed\n");
        free(arr_m_1);
        free(arr_m_2);
        free(arr_m_3);
    }
    else
    {
        printf("Failed\n");
        free(arr_m_1);
        free(arr_m_2);
        free(arr_m_3);
    }


    printf("TESTS FOR matrix_summ: \n\n" 
    "Test №2: \n"
    "matr_1 = {{1 2 3}, {3, 2, 1}, {1, 2, 3}} \n"
    "matr_2 = {{1, 2, 3}, {3 2 1}, {1, 2, 3}} \n"
    "result = {{2, 4, 6}, {6, 4, 2}, {2, 4, 6}} \n"
    "Check: \n");

    double arr_matrix_1_1[3][3] = {{1, 2, 3}, 
                                {3, 2, 1}, {1, 2, 3}};
    double arr_matrix_2_1[3][3] = {{1, 2, 3}, 
                                {3, 2, 1}, {1, 2, 3}};
    double **arr_m_1_1, **arr_m_2_1, **arr_m_3_1;

    double arr_t_1_1[3][3] = {{2, 4, 6}, {6, 4, 2}, {2, 4, 6}};

    arr_m_1_1 = fill_matr(3, 3, arr_matrix_1_1);
    arr_m_2_1 = fill_matr(3, 3, arr_matrix_2_1);

    arr_m_3_1 = MatrixSumm(3, 3, 3, 3, arr_m_1_1, arr_m_2_1);

    if(compare_arrays(3, 3, arr_m_3_1, arr_t_1_1) == OK)
    {
        printf("Passed\n");
        free(arr_m_1_1);
        free(arr_m_2_1);
        free(arr_m_3_1);
    }
    else
    {
        printf("Failed\n");
        free(arr_m_1_1);
        free(arr_m_2_1);
        free(arr_m_3_1);
    }

    printf("TESTS FOR matrix_summ: \n\n" 
    "Test №3: \n"
    "matr_1 = {{3, 2, 1}, {1, 2, 3}} \n"
    "matr_2 = {{1, 2, 3}, {3 2 1}, {1, 2, 3}} \n"
    "result = NULL \n"
    "Check: \n");

    double arr_matrix_1_2[2][3] = {{3, 2, 1}, {1, 2, 3}};
    double arr_matrix_2_2[3][3] = {{1, 2, 3}, {3, 2, 1}, {1, 2, 3}};
    double **arr_m_1_2, **arr_m_2_2, **arr_m_3_2;


    arr_m_1_2 = fill_matr(2, 3, arr_matrix_1_2);
    arr_m_2_2 = fill_matr(3, 3, arr_matrix_2_2);

    arr_m_3_2 = MatrixSumm(2, 3, 3, 3, arr_m_1_2, arr_m_2_2);

    if(!arr_m_3_2)
    {
        printf("Passed\n");
        free(arr_m_1_2);
        free(arr_m_2_2);
        free(arr_m_3_2);
    }
    else
    {
        printf("Failed\n");
        free(arr_m_1_2);
        free(arr_m_2_2);
        free(arr_m_3_2);
    }

    printf("TESTS FOR matrix_summ: \n\n" 
    "Test №4: \n"
    "matr_1 = {{3, 2, 1}, {1, 2, 3}, {1, 2, 3}} \n"
    "matr_2 = {{1, 2, 3}, {3, 2, 1}} \n"
    "result = NULL \n"
    "Check: \n");

    double arr_matrix_2_3[2][3] = {{3, 2, 1}, {1, 2, 3}};
    double arr_matrix_1_3[3][3] = {{1, 2, 3}, {3, 2, 1}, {1, 2, 3}};
    double **arr_m_1_3, **arr_m_2_3, **arr_m_3_3;


    arr_m_1_3 = fill_matr(3, 3, arr_matrix_1_3);
    arr_m_2_3 = fill_matr(2, 3, arr_matrix_2_3);

    arr_m_3_3 = MatrixSumm(3, 3, 2, 3, arr_m_1_3, arr_m_2_3);

    if(!arr_m_3_3)
    {
        printf("Passed\n");
        free(arr_m_1_3);
        free(arr_m_2_3);
        free(arr_m_3_3);
    }
    else
    {
        printf("Failed\n");
        free(arr_m_1_3);
        free(arr_m_2_3);
        free(arr_m_3_3);
    }

    printf("TESTS FOR matrix_summ: \n\n" 
    "Test №5: \n"
    "matr_1 = {{3, 1}, {1, 3}, {1, 3}} \n"
    "matr_2 = {{1, 2, 3}, {3, 2, 1}, {1, 2, 3}} \n"
    "result = NULL \n"
    "Check: \n");

    double arr_matrix_2_4[3][2] = {{3, 1}, {1, 3}, {1, 3}};
    double arr_matrix_1_4[3][3] = {{1, 2, 3}, {3, 2, 1}, {1, 2, 3}};
    double **arr_m_1_4, **arr_m_2_4, **arr_m_3_4;


    arr_m_1_4 = fill_matr(3, 2, arr_matrix_1_4);
    arr_m_2_4 = fill_matr(3, 3, arr_matrix_2_4);

    arr_m_3_4 = MatrixSumm(3, 2, 2, 3, arr_m_1_4, arr_m_2_4);

    if(!arr_m_3_4)
    {
        printf("Passed\n");
        free(arr_m_1_4);
        free(arr_m_2_4);
        free(arr_m_3_4);
    }
    else
    {
        printf("Failed\n");
        free(arr_m_1_4);
        free(arr_m_2_4);
        free(arr_m_3_4);
    }

}


void test_matrix_mult()
{
    printf("TESTS FOR matrix_summ: \n\n" 
    "Test №1: \n"
    "matr_1 = {{1 2 3}, {3 2 1}} \n"
    "matr_2 = {{1 2 3}, {3 2 1}} \n"
    "result = {{2, 4, 6}, {6, 4, 2}} \n"
    "Check: \n");

    double arr_matrix_1[2][3] = {{1, 2, 3}, 
                                {3, 2, 1}};
    double arr_matrix_2[2][3] = {{1, 2, 3}, 
                                {3, 2, 1}};
    double **arr_m_1, **arr_m_2, **arr_m_3;


    arr_m_1 = fill_matr(2, 3, arr_matrix_1);
    arr_m_2 = fill_matr(2, 3, arr_matrix_2);

    arr_m_3 = MatrixMult(2, 3, 2, 3, arr_m_1, arr_m_2);

    if(!arr_m_3)
    {
        printf("Passed\n");
        free(arr_m_1);
        free(arr_m_2);
        free(arr_m_3);
    }
    else
    {
        printf("Failed\n");
        free(arr_m_1);
        free(arr_m_2);
        free(arr_m_3);
    }


    printf("TESTS FOR matrix_summ: \n\n" 
    "Test №2: \n"
    "matr_1 = {{1 2 3}, {3, 2, 1}, {1, 2, 3}} \n"
    "matr_2 = {{1, 2, 3}, {3 2 1}, {1, 2, 3}} \n"
    "result ={{10, 12, 14}, {10, 12, 14}, {10, 12, 14}} \n"
    "Check: \n");

    double arr_matrix_1_1[3][3] = {{1, 2, 3}, 
                                {3, 2, 1}, {1, 2, 3}};
    double arr_matrix_2_1[3][3] = {{1, 2, 3}, 
                                {3, 2, 1}, {1, 2, 3}};
    double **arr_m_1_1, **arr_m_2_1, **arr_m_3_1;

    double arr_t_1_1[3][3] = {{10, 12, 14}, {10, 12, 14}, {10, 12, 14}};

    arr_m_1_1 = fill_matr(3, 3, arr_matrix_1_1);
    arr_m_2_1 = fill_matr(3, 3, arr_matrix_2_1);

    arr_m_3_1 = MatrixMult(3, 3, 3, 3, arr_m_1_1, arr_m_2_1);

    if(compare_arrays(3, 3, arr_m_3_1, arr_t_1_1) == OK)
    {
        printf("Passed\n");
        free(arr_m_1_1);
        free(arr_m_2_1);
        free(arr_m_3_1);
    }
    else
    {
        printf("Failed\n");
        free(arr_m_1_1);
        free(arr_m_2_1);
        free(arr_m_3_1);
    }

    printf("TESTS FOR matrix_summ: \n\n" 
    "Test №3: \n"
    "matr_1 = {{3, 2, 1}, {1, 2, 3}} \n"
    "matr_2 = {{1, 2, 3}, {3 2 1}, {1, 2, 3}} \n"
    "result = {{10, 12, 14}, {10, 12, 14}}; \n"
    "Check: \n");

    double arr_matrix_1_2[2][3] = {{3, 2, 1}, {1, 2, 3}};
    double arr_matrix_2_2[3][3] = {{1, 2, 3}, {3, 2, 1}, {1, 2, 3}};
    double **arr_m_1_2, **arr_m_2_2, **arr_m_3_2;

    double arr_t_1_2[2][3] = {{10, 12, 14}, {10, 12, 14}};

    arr_m_1_2 = fill_matr(2, 3, arr_matrix_1_2);
    arr_m_2_2 = fill_matr(3, 3, arr_matrix_2_2);

    arr_m_3_2 = MatrixMult(2, 3, 3, 3, arr_m_1_2, arr_m_2_2);

    if(compare_arrays(2, 3, arr_m_3_2, arr_t_1_2) == OK)
    {
        printf("Passed\n");
        free(arr_m_1_2);
        free(arr_m_2_2);
        free(arr_m_3_2);
    }
    else
    {
        printf("Failed\n");
        free(arr_m_1_2);
        free(arr_m_2_2);
        free(arr_m_3_2);
    }
}




int main(void)
{
    test_fill_matrix();
    test_matrix_summ();
    test_matrix_mult();
    return OK;
}