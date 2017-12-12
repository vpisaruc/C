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

double **fill_matrix(FILE *file, int *size1, int *size2, double **matrix)
{
    int n, m;

    if (fscanf(file, "%d", size1) == 1)
    {
        n = *size1;
        if (fscanf(file, "%d", size2) == 1)
        {
            m = *size2;
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

void print_matrix(double **matrix, int n, int m, int argc)
{
    for (int i = 0; i < n; i++)
    {
        if (argc == 5)
        {
            for (int j = 0; j < m; j++)
                printf("%lf ", matrix[i][j]);
            printf("\n");
        }
        else
        {
            for (int j = 0; j < m - 1; j++)
                printf("%lf ", matrix[i][j]);
            printf("\n");
        }
    }
    printf("\n");
}



//Function that Summ 2 matrix

double **matrixSumm(int row_1, int column_1, int row_2, int column_2, double **matrix_1, double **matrix_2, double **matrix_3)
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
double **matrixMult(int row_1, int column_1, int row_2, int column_2, double **matrix_1, double **matrix_2, double **matrix_3)
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
int gausMethod(int row, int column, double **matrix, FILE *file)
{
    if (row == column - 1)
    {
        int n = row;
        int l = 0;
        double max_el = 0.0;
        int cnt1 = 0;
        
        double tmpf = 0.0, tmpf2 = 0.0, t3 = 0.0;
        for (int j = 0; j < n; j++)
        {
            for (int h = 0; h < n; h++)
            {
                if (fabs(matrix[h][j]) > max_el)
                {
                    max_el = fabs(matrix[h][j]);
                }
            }
            for (int k = 1 + l; k < n; k++)
            {
                if (matrix[l][j] == 0)
                {
                    return GAUS_ERROR;
                }
                tmpf = matrix[k][j] / matrix[l][j];
                for (int i = 0; i <= n; i++)
                {
                    if (fabs(tmpf) == 0)
                    {
                        return GAUS_ERROR;
                    }
                    tmpf2 = (matrix[l][i] * tmpf);
                    t3 = matrix[k][i] - tmpf2;
                    if (t3 == 0)
                    {
                        cnt1++;
                    }
                    
                    matrix[k][i] = t3;
                }
            }
            l++;
        }

        if (cnt1 == n + 1)
        {
            return GAUS_ERROR;
        }
        
        double x[row];
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            double s = 0;
            for (int j = n - 1; j > i; j--)
            {
                s += x[j] * matrix[i][j];
            }
            if (matrix[i][i] == 0)
            {
                return GAUS_ERROR;
            }
            x[i] = (matrix[i][n] - s) / matrix[i][i];
            if (x[i] == 0)
            {
                x[i] = fabs(x[i]);
            }
            cnt++;
        }

        fprintf(file, "%d ", 1);
        fprintf(file, "%d\n", cnt);
        for (int i = 0; i < row; i++)
        {
            fprintf(file, "%lf\n", x[i]);
        }
        return OK;
    }
    return GAUS_ERROR;
}

