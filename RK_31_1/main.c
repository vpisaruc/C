#include <stdio.h>
#include <malloc.h>
#include "functions.h"


int main(int argc, char** argv)
{
	FILE *file, *file2;
	int row, column;
	double **matrix;
	
	if (argc == 2)
	{
		file = fopen(argv[argc - 1], "r");

		if(file != NULL)
		{
			
			matrix = fill_matrix(file, matrix, &row, &column);
			print_matrix(matrix, row, column);
			
			if(matrix != NULL)
			{
				sr_element(matrix, row, column);
			}
		}
		else
		{
			printf("\nCant find this file\n");
			return FILE_NOT_FOUND;
		}
	}
	else
	{
		printf("\nCommand line must have only 2 arguments\n");
		return COMMAND_LINE_ERROR;
	}
}