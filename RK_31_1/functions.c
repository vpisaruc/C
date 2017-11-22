#include <stdio.h>
#include <malloc.h>
#include "functions.h"
#include <math.h>

double **allocate_matrix(int n, int m)
{
	double **data = malloc(n * sizeof(double*) + n * m * sizeof(double));
	
	if(!data)
	{
		return NULL;
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			data[i] = (double *)((char*)data + n * sizeof(double*) + m * i * sizeof(double)); 
		}
		return data;
	}
}

double **init_matrix(double **matrix, int n, int m)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			matrix[i][j] = 0.0;
		}
	}
	return matrix;
}

double **fill_matrix(FILE *file, double **matrix, int *row, int *column)
{
	int n, m;
	if(fscanf(file, "%d", row) == 1)
	{
		n = *row;
		if(fscanf(file, "%d", column) == 1)
		{
			m = *column;
			matrix = allocate_matrix(n,m);
			matrix = init_matrix(matrix, n, m);
			
			if(matrix != NULL)
			{
				for(int i = 0; i < n; i++)
				{
					for(int j = 0; j < m; j++)
					{
						if(fscanf(file, "%lf", &matrix[i][j]) == 1)
						{
							printf(" ");
						}
						else
						{
							return NULL;
						}
					}
				}
				return matrix;
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}


void print_matrix(double **matrix, int n, int m)
{
	printf("\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			printf("%6lf ", matrix[i][j]);
		}
		printf("\n");
	}
}

void sr_element(double **matrix, int n, int m)
{
	double arr[n];
	double arr2[n][m];
	
	double summ = 0;
	double min_el;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			summ += matrix[i][j]; 
		}
		
		arr[i] = summ / n;
		summ = 0;
	}
/*
	for(int i = 0; i < n; i++)
	{
		printf("%lf ", arr[i]);
	}
*/	
	
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			arr2[i][j] = fabs(arr[i] - matrix[i][j]);
		}
	}
	
	
	printf("\n\n");


	
	printf("\nNaibolee blizkie k sr arif znacheniiu:\n\n");
	for(int i =0; i < n; i++)
	{
		min_el = arr2[i][0];
		for(int j =0; j< m; j++)
		{
			if(min_el > arr2[i][j])
			{
				min_el = arr2[i][j];
			}
		}
		arr[i] = min_el;

	}
	
	
	for(int i = 0; i < n; i++)
	{
		printf("%lf ", arr[i]);
	}

	

}