#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define OK 0
#define GAUS_ERROR -1






//Allocation of dynamic memory to a matrix

double **allocate_matrix_solid(int n, int m)
{
    double **data = malloc(n * sizeof(double *) + n * m * sizeof(double));
    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
        data[i] = (double *)((char *)data + n * sizeof(double *) + i * m * sizeof(double));
    return data;
}


//Initialization of matrix
double **init(double **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Обращение к элементу i, j
            matrix[i][j] = 0.0;
        }
    }
    return matrix;
}

//Filling matrix

double **fill_matrix(FILE *file, int *size1, int *size2, int argc, double **matrix)
{
    int n, m;

    if (fscanf(file, "%d", size1) == 1)
    {
        n = *size1;
        if (fscanf(file, "%d", size2) == 1)
        {
            if (argc == 5)
            {
                m = *size2;
            }
            else
            {
                m = *size2;
                m++;
            }
            matrix = allocate_matrix_solid(n, m);
            matrix = init(matrix, n, m);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (fscanf(file, "%lf", &matrix[i][j]) == 1)
                    {
                        printf(" ");
                    }
                    else
                    {
                        free(matrix);
                        return NULL;
                    }
                }
            }
            printf("\n\n");
            return matrix;
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}


//Print matrix

void print_matrix(double **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%lf ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}



//Function that Summ 2 matrix

double **MatrixSumm(int row_1, int column_1, int row_2, int column_2, double **matrix_1, double **matrix_2, double **matrix_3)
{
    if (row_1 == row_2 && column_1 == column_2)
    {
        matrix_3 = allocate_matrix_solid(row_1, column_1);
        matrix_3 = init(matrix_3, row_1, column_1);
        for (int i = 0; i < row_1; i++)
        {
            for (int j = 0; j < column_1; j++)
            {
                matrix_3[i][j] = matrix_1[i][j] + matrix_2[i][j];
            }
        }
        return matrix_3;
    }
    return NULL;
}


//Function that Multiply 2 matrix
double **MatrixMult(int row_1, int column_1, int row_2, int column_2, double **matrix_1, double **matrix_2, double **matrix_3)
{
    if (column_1 == row_2)
    {
        matrix_3 = allocate_matrix_solid(row_1, column_2);
        matrix_3 = init(matrix_3, row_1, column_2);
        for (int i = 0; i < row_1; i++)
        {
            for (int j = 0; j < column_2; j++)
            {
                matrix_3[i][j] = 0;
                for (int k = 0; k < row_2; k++)
                {
                    matrix_3[i][j] += matrix_1[i][k] * matrix_2[k][j];
                }
            }
        }
        return matrix_3;
    }
    return NULL;
}


//Function that contain Gaus Method
int GausMethod(int row, int column, double **matrix, FILE *file)
{
    if(row == column)
    {
        int n = row;
        int L = 0;
        double max_el = 0.0;
        
        double tmpf = 0.0, tmpf2 = 0.0, t3 = 0.0;
        for(int j = 0; j < n; j++)
        {
            for(int h = 0; h < n; h++)
            {
                if(fabs(matrix[h][j]) > max_el)
                {
                    max_el  = fabs(matrix[h][j]);
                }
            }
            for(int k = 1 + L; k < n; k++)
            {
                tmpf = matrix[k][j] / matrix[L][j];
                for (int i = 0; i <= n; i++)
                {
                    if (fabs(tmpf) == 0)
                    {
                        break;
                    }
                    tmpf2 = (matrix[L][i] * tmpf);
                    t3 = matrix[k][i] - tmpf2;
                    matrix[k][i] = t3;
                }
            }
            L++;
        }
        
        double x[row];
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            double s = 0;
            for(int j = n - 1; j > i; j--)
            {
                s += x[j] * matrix[i][j];
            }
            x[i] = (matrix[i][n] - s) / matrix[i][i];
            if (x[i] == 0)
            {
                x[i] = fabs(x[i]);
            }
            cnt++;
        }

        fprintf(file,"%d ", 1);
        fprintf(file, "%d\n", cnt);
        for(int i = 0; i < row; i++)
        {
            fprintf(file,"%lf\n", x[i]);
        }
        return OK;
    }
    else
    {
        return GAUS_ERROR;
    }
}

