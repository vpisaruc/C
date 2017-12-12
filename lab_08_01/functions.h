#include <stdio.h>

#define OK 0
#define FILE_ERROR -1
#define INPUT_ERROR -2
#define SUMM_ERROR -3
#define MULTIPLY_ERROR -4
#define COMMAND_LINE_ERROR -5
#define ACTION_ERROR -6
#define GAUS_ERROR -7


double**allocate_matrix_solid(int n, int m);
double**fill_matrix(FILE *file, int *size1, int *size2);
void print_matrix(double **matrix, int n, int m, int argc);
double **init(double **matrix, int n, int m);
double**matrixSumm(int row_1, int column_1, int row_2, int column_2, double **matrix_1, double **matrix_2);
double**matrixMult (int row_1, int column_1, int row_2, int column_2, double **matrix_1, double **matrix_2);
int gausMethod(int row, int column, double **matrix, FILE *file);
