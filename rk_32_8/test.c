#include "functions.h"


void test_readFile(void)
{
	node_t *studentList = NULL;
	int retVal;
	FILE *file;
	printf("Testing for func readFile\n");
	printf("file = 4 Pisaruc 4 3 4  Popov 3 1 5 4 Tiupov 5 5 5 5 Morokov 3 3 2 5\n");
	printf("Result = Pisaruc 4 3 4  Popov 3 1 5 4 Tiupov 5 5 5 5 Morokov 3 3 2 5\n");
	
	file = fopen("in_1.txt", "r");
	retVal = readFile(file, &studentList);
	
	if(retVal == OK)
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}
	

	printf("Testing for func readFile\n");
	printf("file = 4 Pisaruc 4 3 4  Popov 3 1 5 4 Tiupov 5 5 5 5 Morokov 3 3 2 5\n");
	printf("Result = Pisaruc 4 3 4  Popov 3 1 5 4 Tiupov 5 5 5 5 Morokov 3 3 2 5\n");
	
	file = fopen("in_2.txt", "r");
	retVal = readFile(file, &studentList);
	
	if(retVal == IO_ERROR)
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}	
}

int main(void)
{
	test_readFile();
	
}