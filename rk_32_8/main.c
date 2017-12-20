#include "functions.h"

int main(int argc, char **argv)
{
	FILE *file;
	int out;
	
	file = fopen(argv[1], "r");
	
	if(!file)
	{
		printf("\nFile not found\n");
		out = FILE_NOT_FOUND;
	}
	else
	{
		node_t *studentList = NULL;
		out = readFile(file, &studentList);
		if(out == MEMORY_ERROR)
		{
			deleteList(&studentList);
			printf("\nMemory Error\n");
		}
		else if (out == IO_ERROR)
		{
			deleteList(&studentList);
			printf("IO_ERROR");
		}
		else
		{
			printf("\nList of students before checking\n");
			print_node(studentList);
			checkStudents(&studentList);

			printf("\nList of students after checking\n");
			print_node(studentList);
			deleteList(&studentList);
		}
		
	}
	return out;
}