#include <stdio.h>

#define OK 0
#define FILE_ERROR -1
#define COMMAND_LINE_ERROR -2
#define FILE_NOT_FOUND -3


double** allocate_matrix(int n, int m);
double** init_matrix(double **matrix, int n, int m);
double** fill_matrix(FILE *file, double **matrix, int *row, int *column);
void print_matrix(double **matrix, int n, int m);
void sr_element(double **matrix, int n, int m);
