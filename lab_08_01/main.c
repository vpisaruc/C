#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"





int main(int argc, char **argv)
{
    //Create first file variable

    FILE *file1 = NULL;

    //Compare arguments of command line
    if(argc == 5)
    {
        // Open first file
        file1 = fopen(argv[argc - 3], "r");
        if (file1 != NULL)
        {
            //Create second file variable
            FILE *file2 = NULL;
            
            //Open second file2
            file2 = fopen(argv[argc - 2], "r");
            if (file2 != NULL)
            {
                //Create desired variables
                double **matrix_1 = NULL, **matrix_2 = NULL, **matrix_3 = NULL;
                int row_1, column_1, row_2, column_2;
                matrix_1 = fill_matrix(file1, &row_1, &column_1);
                //Analize errors
                if (matrix_1 == NULL)
                {
                    printf("\n\nInput error.\n\n");
                    return INPUT_ERROR;
                }

                else
                {

                    //Fill our matrix
                    matrix_2 = fill_matrix(file2, &row_2, &column_2);
                    
                    if (matrix_2 == NULL)
                    {
                        printf("Input error.");
                        free(matrix_1);
                        return INPUT_ERROR;
                    }
                    else
                    {
                        printf("\n\nFirst matrix: \n\n");
                        print_matrix(matrix_1, row_1, column_1, argc);
                        printf("\n\nSecond matrix: \n\n");
                        print_matrix(matrix_2, row_2, column_2, argc);
                        
                        //Compare action and choose one
                        if(strcmp(argv[argc - 4], "a") == 0)
                        {
                            FILE *file3;
                            file3 = fopen(argv[argc - 1], "w");

                            //Matrix_3 is summ of matrix_1 and matrix_2
                            matrix_3 = MatrixSumm(row_1, column_1, row_2, column_2, matrix_1, matrix_2);

                            //Error analization
                            if(matrix_3 == NULL)
                            {
                                printf("\n\nRows and colums of both matrix must be simmilar.\n\n");
                                free(matrix_1);
                                free(matrix_2);
                                free(matrix_3);
                                return SUMM_ERROR;
                            }
                            else
                            {
                                printf("\n\nSumm of matrix_1 and matrix_2\n\n");
                                print_matrix(matrix_3, row_1, column_1, argc);

                                fprintf(file3, "%d %d\n", row_1, column_1);
                                for (int i = 0; i < row_1; i++)
                                {
                                    for(int j = 0; j < column_1; j++)
                                    {
                                        fprintf(file3, "%lf  ", matrix_3[i][j]);
                                    }
                                    fprintf(file3, "\n");
                                }
                                free(matrix_1);
                                free(matrix_2);
                                free(matrix_3);
                                fclose(file1);
                                fclose(file2);
                                fclose(file3);
                                return OK;
                            }
                        }

                        //Compare action and choose one
                        else if(strcmp(argv[argc - 4], "m") == 0)
                        {
                            FILE *file3 = NULL;
                            file3 = fopen(argv[argc - 1], "w");
                            //Multiply of matrix_1 and matrix_2
                            matrix_3 = MatrixMult(row_1, column_1, row_2, column_2, matrix_1, matrix_2);

                            if(matrix_3 == NULL)
                            {
                                printf("\n\nCounts of colums of first matrix must be simmilar as counts of rows in second matrix.\n\n");
                                free(matrix_1);
                                free(matrix_2);
                                free(matrix_3);
                                return MULTIPLY_ERROR;
                            }
                            else
                            {
                                printf("\n\nMultiply of matrix_1 and matrix_2\n\n");
                                print_matrix(matrix_3, row_1, column_2, argc);

                                fprintf(file3, "%d %d\n", row_1, column_2);
                                for (int i = 0; i < row_1; i++)
                                {
                                    for(int j = 0; j < column_2; j++)
                                    {
                                        fprintf(file3, "%lf  ", matrix_3[i][j]);
                                    }
                                    fprintf(file3, "\n");
                                }
                                free(matrix_1);
                                free(matrix_2);
                                free(matrix_3);
                                fclose(file1);
                                fclose(file2);
                                fclose(file3);
                                return OK;
                            }
                        }
                        else
                        {
                            printf("\nInput 'm' or 'a' in action\n");
                            free(matrix_1);
                            free(matrix_2);
                            free(matrix_3);
                            return ACTION_ERROR;
                        }
                    }
                }
            }
            else
            {
                printf("\nCan't find second file.\n");
                return FILE_ERROR;
            }
        
        }
        else
        {
            printf("\nCan't find first file\n");
            return FILE_ERROR;
        }
    }
    //If command line have 3 arguments
    else if(argc == 4)  
    {

        file1 = fopen(argv[argc - 2], "r");
        if(file1 != NULL)
        {
            double **matrix_1 = NULL;
            int row_1, column_1, retVal;
            matrix_1 = fill_matrix(file1, &row_1, &column_1);
            if(matrix_1 == NULL)
            {
                printf("\nInput error\n");
                return INPUT_ERROR;
            }
            else
            {
                if(strcmp(argv[argc - 3], "o") == 0)
                {
                    FILE *file3 = NULL;
                    file3 = fopen(argv[argc - 1], "w");

                    printf("\n\nFirst matrix: \n\n");
                    print_matrix(matrix_1, row_1, column_1, argc);

                    //Gaus Method
                    
                    retVal = GausMethod(row_1, column_1, matrix_1, file3);
                    
                    fclose(file1);
                    fclose(file3);
                    free(matrix_1);
                    
                    if(retVal != 0)
                    {
                        printf("\nRows and colums of out matrix must be simmilar\n");
                        //free(matrix_1);
                        return GAUS_ERROR;
                    }
                }
                else
                {
                    printf("\nInput 'o' in action\n");
                    free(matrix_1);
                    return ACTION_ERROR;
                }
            }
        }
        else
        {
            printf("\nCan't find first file\n");
            return FILE_ERROR;
        }

    }
    else
    {
        printf("\nCommand line must have 3 or 4 arguments.\n");
        return COMMAND_LINE_ERROR;
    }

}
