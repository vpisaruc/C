#include <stdio.h>
#include <malloc.h>
#include <string.h>


#define OK 0
#define IO_ERROR -1
#define FILE_NOT_FOUND -2
#define MEMORY_ERROR -3 

typedef struct student
{
	char *name;
	int mark1, mark2, mark3, mark4;
} student_t;

typedef struct Node
{
	student_t *data;
	struct Node *next;
} node_t;


int readFile(FILE *file, node_t **studentList);
void print_node(node_t *studentList);
void checkStudents(node_t **studentList);