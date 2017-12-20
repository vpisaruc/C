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


node_t *get_last(node_t *studentList)
{
	node_t *tmpNode = NULL;
	
  // start list of students
  tmpNode = studentList;
  
	while(1 != 0)
	{
		if(tmpNode->next == NULL)
		{
      // last element with NULL next
			return tmpNode;
		}
		else
		{
			tmpNode = tmpNode->next;
		}
	}
}



void checkStudents(node_t **studentList)
{
	node_t *tmpNode = NULL, *lastNode = NULL, *lastNodeNew = NULL, *prevNode = NULL;
	
	// start list node
  tmpNode = *studentList;
  // last node of initial list(fixing)
  lastNode = get_last(tmpNode);
  // last node new - changed after moving element
  lastNodeNew = lastNode;
	
	printf("\nSpisok neuspevaiushih: \n");
	while(1 != 0)
	{
		
		if(tmpNode->data->mark1 < 3 || tmpNode->data->mark2 < 3 || tmpNode->data->mark3 < 3 || tmpNode->data->mark4 < 3)
		{
			printf("%20s%4d%4d%4d%4d", tmpNode->data->name, tmpNode->data->mark1, tmpNode->data->mark2, tmpNode->data->mark3, tmpNode->data->mark4);
			printf("\n\n");
      
      if (tmpNode == lastNode)
      {
        // lst element of list (not moved) - after him only moved neuspevaiushie
        break;
      }
      
      // move to the end of list
      lastNodeNew->next = tmpNode;
      lastNodeNew = tmpNode;
      if (prevNode == NULL)
      {
         // izmeniaem nachalo spiska ya sleduiushii element
         *studentList = tmpNode->next;
      }
      else
      {
         // change next for previous element
         prevNode->next = tmpNode->next;
      }
      // next element
      tmpNode = lastNodeNew->next;
      // new last element
      lastNodeNew->next = NULL;      
		}
    else
    {
      if (tmpNode == lastNode)
      {
        // end of initial list of students
        break;
      }
  	  prevNode = tmpNode;
      tmpNode = tmpNode->next;
    }
	}
}


void deleteList(node_t **studentList) 
{
    node_t* prev = NULL;
	char *prevData = NULL; 
    while ((*studentList)->next) 
	{
        prev = (*studentList);
		prevData = ((*studentList)->data->name);
        (*studentList) = (*studentList)->next;
		free(prevData);
        free(prev);
    }
    free(*studentList);
}