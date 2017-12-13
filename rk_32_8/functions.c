#include "functions.h"

int readFile(FILE *file, node_t **studentList)
{
	node_t *lastAdded = NULL, *newNode = NULL;
	student_t *studentData = NULL;
	int cnt;
	char *name;
	int mark1, mark2, mark3, mark4;
	
	if(fscanf(file, "%d", &cnt) == 1)
	{
		lastAdded = *studentList;
		for(int i = 0; i < cnt; i++)
		{
			name = (char*)malloc(70 * sizeof(char));
			if(!name)
			{
				printf("Memmory error");
				return MEMORY_ERROR;
			}
			if(fscanf(file, "%20s%4d%4d%4d%4d", name, &mark1, &mark2, &mark3, &mark4) != 5)
			{
				return IO_ERROR;
			}
			else
			{
				studentData = (student_t*)malloc(sizeof(student_t));
				if(!studentData)
				{
					return MEMORY_ERROR;
				}
				
				studentData->name = name;
				studentData->mark1 = mark1;
				studentData->mark2 = mark2;
				studentData->mark3 = mark3;
				studentData->mark4 = mark4;
				
				newNode = (node_t*)malloc(sizeof(node_t));
				
				if(!newNode)
				{
					return MEMORY_ERROR;
				}
				
				newNode->data = studentData;
				newNode->next = NULL;
				
				if(!lastAdded)
				{
					*studentList = newNode;
				}
				else
				{
					lastAdded->next = newNode;
				}
				lastAdded = newNode;
			}
		}
		return OK;
	}
	return IO_ERROR;
}

void print_node(node_t *studentList)
{
	node_t *tmpList = studentList;
	while(1 != 0)
	{
		printf("%20s%4d%4d%4d%4d", tmpList->data->name, tmpList->data->mark1, tmpList->data->mark2, tmpList->data->mark3, tmpList->data->mark4);
		
		if(tmpList->next == NULL)
		{
			break;
		}
		else
		{
			tmpList = tmpList->next;
		}
		printf("\n\n");
	}
}

nade_t *get_last(node_t *studentList)


void checkStudents(node_t **studentList)
{
	node_t *tmpNode = NULL;
	tmpNode = *studentList;
	
	while(1 != 0)
	{
		if(tmpNode->data->mark1 < 3 || tmpNode->data->mark2 < 3 || tmpNode->data->mark3 < 3 || tmpNode->data->mark4 < 3)
		{
			printf("\n+\n");
			
		}
		if(tmpNode->next == NULL)
		{
			break;
		}
		else
		{
			tmpNode = tmpNode->next;
		}
	}
}



