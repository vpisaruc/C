#include <stdlib.h>
#include <stdio.h>

#include "functions.h"


// Functions
char*getErrorMessage(const int errId)
{
    char *errMessage;
    switch (errId)
    {
        case OK:
            errMessage = "Normal Exit\n";
            break;
        case ERROR_FILE_NOT_EXISTS:
            errMessage = "File not exists\n";
            break;
        case ERROR_FILE_DATA_STRUCTURE:
            errMessage = "Error file data structure\n";
            break;
        case ERROR_FILE_EMPTY:
            errMessage = "Input file is empty\n";
            break;
        case INCORRECT_PARAM:
            errMessage = "Incorrect param for function\n";
            break;
        case NONE_ELEMENTS:
            errMessage = "List of data is empty\n";
            break;
        case MEMMORY_ERROR:
            errMessage = "Memory initialization error\n";
            break;
        case SIZE_ERROR:
            errMessage = "Size error\n";
            break;
        default:
            errMessage = "Unknown error\n";
            break;
    }
    return errMessage;
}

// load file data
int loadFileData(const char *fileName, node_t **listOfStudents)
{
    FILE *file;
    node_t *newNode = NULL, *lastAdded = NULL;
    student_t *studentData = NULL;
    int retVal = OK, cntNodes = 0, retReadFile;
    char *family, *group;
    int examListId, examMark1, examMark2, examMark3;

    // open input file
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        retVal = ERROR_FILE_NOT_EXISTS;
    }

    if (retVal == OK)
    {
        // initialization
        lastAdded = *listOfStudents;

        // read file data
        while (1 != 0)
        {
            // read formatted line from file
            family = (char*)malloc(14 * sizeof(char));
            group = (char*)malloc(10 * sizeof(char));
            retReadFile = fscanf(file, "%4d%10s%14s%3d%3d%d", &examListId, group, family, &examMark1, &examMark2, &examMark3);
            if (retReadFile == EOF)
            {
                // end of file
                break;
            }
            if (retReadFile != 6)
            {
                // error reading file (format error)
                retVal = ERROR_FILE_DATA_STRUCTURE;
                break;
            }

            //New student_data
            studentData = (student_t*)malloc(sizeof(student_t));
            if (!studentData)
            {
                retVal = MEMMORY_ERROR;
                break;
            }
            studentData->examListId = examListId;
            studentData->family = family;
            studentData->group = group;
            studentData->examMark1 = examMark1;
            studentData->examMark2 = examMark2;
            studentData->examMark3 = examMark3;

            // New node of list
            newNode = (node_t*)malloc(sizeof(node_t));
            if (!newNode)
            {
                retVal = MEMMORY_ERROR;
                break;
            }
            newNode->data = studentData;
            newNode->next = NULL;

            if (!lastAdded)
            {
                // first node
                *listOfStudents = newNode;
            }
            else
            {
                lastAdded->next = newNode;
            }
            lastAdded = newNode;
            
            cntNodes++;
        }

        if (retVal == OK && cntNodes == 0)
        {
            retVal = ERROR_FILE_EMPTY;
        }
    }

    if (retVal != ERROR_FILE_NOT_EXISTS)
    {
        fclose(file);
    }

    return retVal;
}

// print node data 
void printNodeData(const student_t* studentData)
{
    printf("%2d  %-10s%-14s%3d%3d%3d\n", studentData->examListId, studentData->group, studentData->family, studentData->examMark1, studentData->examMark2, studentData->examMark3);
}

// print list of students data
void printListOfStudents(const char *headerStr, const node_t *listOfStudents)
{
    node_t *tmpNode = NULL;

    tmpNode = (node_t*)listOfStudents;
    if (!tmpNode)
    {
        return;
    }
    // header
    printf("\n%s\n", headerStr);
    while (1 != 0)
    {
        printNodeData((student_t*)tmpNode->data);
        if (tmpNode->next == NULL)
        {
            break;
        }
        tmpNode = tmpNode->next;
    }
    printf("\n\n");
}

// find sudent by family
node_t* find(node_t *head, const void *data, int(*comparator)(const void*, const void*))
{
    node_t *tmpNode = NULL, *retNode = NULL;

    tmpNode = head;
    if (tmpNode)
    {
        while (1 != 0)
        {
            // next element of list
            if (comparator((char*)data, ((student_t*)tmpNode->data)->family) == 0)
            {
                retNode = tmpNode;
                break;
            }
            if (tmpNode->next == NULL)
            {
                break;
            }
            else
            {
                tmpNode = tmpNode->next;
            }
        }
    }

    return retNode;
}


// copy list of students
int copy(node_t *head, node_t **new_head)
{
    node_t *tmpNode = NULL, *newNode = NULL, *lastAdded = NULL;
    int retVal = OK;

    lastAdded = *new_head;
    tmpNode = head;
    if (!tmpNode)
    {
        retVal = NONE_ELEMENTS;
    }

    if (retVal == OK)
    {
        while (1 != 0)
        {
            // copy 1 node
            newNode = (node_t*)malloc(sizeof(node_t));
            if (!newNode)
            {
                retVal = MEMMORY_ERROR;
                break;
            }
            newNode->data = tmpNode->data;
            newNode->next = NULL;

            if (!lastAdded)
            {
                // first node
                *new_head = newNode;
            }
            else
            {
                lastAdded->next = newNode;
            }
            lastAdded = newNode;
            
            // next element of list
            if (tmpNode->next == NULL)
            {
                break;
            }
            else
            {
                tmpNode = tmpNode->next;
            }
        }
    }

    return retVal;
}


// compare string
int compareStringData(const void* first, const void* second)
{
    return strcmp((char*)first, (char*)second);
}


// insert node before
void insert(node_t **head, node_t *elem, node_t *before)
{
    node_t *tmpNode = NULL;

    // link to next element
    elem->next = before;

    if (before == *head)
    {
        // insert before first element
        *head = elem;
    }
    else
    {
        tmpNode = *head;
        if (tmpNode)
        {
            while (1 != 0)
            {
                // next element of list
                if (tmpNode->next == before)
                {
                    // change link to elem from before
                    tmpNode->next = elem;
                    break;
                }
                if (tmpNode->next == NULL)
                {
                    break;
                }
                else
                {
                    tmpNode = tmpNode->next;
                }
            }
        }
    }
}

// setup insert node
node_t* getInsertNode()
{
    node_t *newNode = NULL;
    student_t *studentData = NULL;
    char *family, *group;

    //New student_data
    studentData = (student_t*)malloc(sizeof(student_t));
    if (!studentData)
    {
        return newNode;
    }

    family = (char*)malloc(14 * sizeof(char));
    group = (char*)malloc(10 * sizeof(char));
    printf("\nInput data for inserting new student: \n");
    printf("Input student ID:\n");
    scanf("%d", &studentData->examListId);
    printf("Input student last name:\n");
    scanf("%s", family);
    studentData->family = family;
    printf("Input student group:\n");
    scanf("%s", group);
    studentData->group = group;
    printf("Input examen mark 1:\n");
    scanf("%d", &studentData->examMark1);
    printf("Input examen mark 2:\n");
    scanf("%d", &studentData->examMark2);
    printf("Input examen mark 3:\n");
    scanf("%d", &studentData->examMark3);

    // New node of list
    newNode = (node_t*)malloc(sizeof(node_t));
    if (!newNode)
    {
        return newNode;
    }

    newNode->data = studentData;
    newNode->next = NULL;

    return newNode;
}


// sorted insert into sorted list
void sorted_insert(node_t **head, node_t *element, int(*comparator)(const void *, const void *))
{
    node_t *tmpNode = NULL, *tmpBefore = NULL;

    tmpNode = *head;

    if (tmpNode)
    {
        while (1 != 0)
        {
            if (comparator(((student_t*)element->data)->family, ((student_t*)tmpNode->data)->family)<0)
            {
                element->next = tmpNode;
                if (tmpNode == *head)
                {
                    *head = element;
                }
                else
                {
                    tmpBefore->next = element;
                }
                break;
            }

            // next element of list
            if (tmpNode->next == NULL)
            {
                // insert after last element
                tmpNode->next = element;
                element->next = NULL;
                break;
            }
            else
            {
                tmpBefore = tmpNode;
                tmpNode = tmpNode->next;
            }
        }
    }
    else
    {
        element->next = NULL;
        *head = element;
    }
}


// sorting list using function sorted_insert
node_t* sort(node_t *head, int(*comparator)(const void *, const void *))
{
    node_t *tmpNode = NULL, *tmpListNodes = NULL, *newNode = NULL;

    tmpNode = head;
    if (tmpNode)
    {
        while (1 != 0)
        {
            // Sorted insert into new sorted list
            // New node of list
            newNode = (node_t*)malloc(sizeof(node_t));
            if (!newNode)
            {
                return newNode;
            }
            newNode->data = tmpNode->data;
            sorted_insert(&tmpListNodes, newNode, comparator);

            // next element of list
            if (tmpNode->next == NULL)
            {
                break;
            }
            else
            {
                tmpNode = tmpNode->next;
            }
        }
    }

    return tmpListNodes;
}
