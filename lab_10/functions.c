#include <stdlib.h>
#include <stdio.h>

#include "functions.h"


// Functions
char* getErrorMessage(const int errId)
{
    char *errMessage;
    switch (errId)
    {
    case OK:
        errMessage = "Normal Exit";
        break;
    case ERROR_FILE_NOT_EXISTS:
        errMessage = "File not exists";
        break;
    case ERROR_FILE_DATA_STRUCTURE:
        errMessage = "Error file data structure";
        break;
    case ERROR_FILE_EMPTY:
        errMessage = "Input file is empty";
        break;
    case INCORRECT_PARAM:
        errMessage = "Incorrect param for function";
        break;
    case NONE_ELEMENTS:
        errMessage = "List of data is empty";
        break;
    case MEMORY_ERROR:
        errMessage = "Memory initialization error";
        break;
    case SIZE_ERROR:
        errMessage = "Size error";
        break;
    case ERROR_FILES_NOT_EQUAL:
        errMessage = "Files are not Equal";
        break;
    case DATA_NOT_FOUND:
        errMessage = "Student data not found";
        break;
    case DATA_NOT_EQUAL:
        errMessage = "Students data are not Equal";
        break;
    default:
        errMessage = "Unknown error";
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
                free(family);
                free(group);
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
                retVal = MEMORY_ERROR;
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
                retVal = MEMORY_ERROR;
                break;
            }
            newNode->data = studentData;
            newNode->next = NULL;

            if (!lastAdded)
            {
                // first node
                *listOfStudents = newNode;
                lastAdded = newNode;
            }
            else
            {
                lastAdded->next = newNode;
                lastAdded = newNode;
            }

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
    printf("%s\n", headerStr);
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
                retVal = MEMORY_ERROR;
                break;
            }
            newNode->data = tmpNode->data;
            newNode->next = NULL;

            if (!lastAdded)
            {
                // first node
                *new_head = newNode;
                lastAdded = newNode;
            }
            else
            {
                lastAdded->next = newNode;
                lastAdded = newNode;
            }

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


// load file data
int writeFileData(const char *fileName, node_t *listOfStudents)
{
    FILE *file;
    node_t *tmpNode;
    int retVal = OK;

    // open input file
    file = fopen(fileName, "w");
    if (file == NULL)
    {
        retVal = ERROR_FILE_NOT_EXISTS;
    }

    if (retVal == OK)
    {
        tmpNode = listOfStudents;
        if (!tmpNode)
        {
            retVal = NONE_ELEMENTS;
        }

        if (retVal == OK)
        {
            while (1 != 0)
            {
                // output
                fprintf(file, "%2d  %-10s%-14s%d%3d%3d\n", ((student_t*)tmpNode->data)->examListId,
                                                            ((student_t*)tmpNode->data)->group,
                                                            ((student_t*)tmpNode->data)->family,
                                                            ((student_t*)tmpNode->data)->examMark1,
                                                            ((student_t*)tmpNode->data)->examMark2,
                                                            ((student_t*)tmpNode->data)->examMark3);

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
    }

    if (retVal != ERROR_FILE_NOT_EXISTS)
    {
        fclose(file);
    }

    return retVal;
}

// setup insert node
node_t* setNodeTest(const int examListId, const char * family, const char * group, const int examMark1, const int examMark2, const int examMark3)
{
    node_t *newNode = NULL;
    student_t *studentData = NULL;
    char *familyPtr = NULL, *groupPtr = NULL, *familyStr = NULL, *grouoStr = NULL;

    //New student_data
    studentData = (student_t*)malloc(sizeof(student_t));
    if (!studentData)
    {
        return newNode;
    }

    familyStr = (char*)malloc(14 * sizeof(char));
    grouoStr = (char*)malloc(10 * sizeof(char));

    familyPtr = strcpy(familyStr, family);
    groupPtr = strcpy(grouoStr, group);

    studentData->examListId = examListId;
    studentData->family = familyPtr;
    studentData->group = groupPtr;
    studentData->examMark1 = examMark1;
    studentData->examMark2 = examMark2;
    studentData->examMark3 = examMark3;

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

// full compare student_data
int compareStudentData(const void* first, const void* second)
{
    if (
        (((student_t*)first)->examListId == ((student_t*)second)->examListId) &&
        (strcmp(((student_t*)first)->family, ((student_t*)second)->family) == 0) &&
        (strcmp(((student_t*)first)->group, ((student_t*)second)->group) == 0) &&
        (((student_t*)first)->examMark1 == ((student_t*)second)->examMark1) &&
        (((student_t*)first)->examMark2 == ((student_t*)second)->examMark2) &&
        (((student_t*)first)->examMark3 == ((student_t*)second)->examMark3)
        )
    {
        return OK;
    }
    else
    {
        return 1;
    }
}


// compare 2 text file data
int compareFileData(const char *fileName1, const char *fileName2)
{
    FILE *file1, *file2;
    char *linePtr1, *linePtr2;
    char line1[500], line2[500];
    int retVal = OK;

    // open files file
    file1 = fopen(fileName1, "r");
    if (file1 == NULL)
    {
        return ERROR_FILE_NOT_EXISTS;
    }
    // open files file
    file2 = fopen(fileName2, "r");
    if (file2 == NULL)
    {
        // file1 is already open
        fclose(file1);
        return ERROR_FILE_NOT_EXISTS;
    }

    while (1 != 0)
    {
        linePtr1 = fgets(line1, 500, file1);
        linePtr2 = fgets(line2, 500, file2);
        if ((linePtr1 == NULL) || (linePtr2 == NULL))
        {
            if ((linePtr1 != NULL) || (linePtr2 != NULL))
            {
                // files not equal - different number of lines
                retVal = ERROR_FILES_NOT_EQUAL;
            }
            break;
        }
        if (strcmp(line1, line2) != 0)
        {
            // one of lines not equal
            retVal = ERROR_FILES_NOT_EQUAL;
            break;
        }
    }

    fclose(file1);
    fclose(file2);

    return retVal;
}




// delete list 
void deleteList(node_t **head, const int signFreeData)
{
    node_t *prevNode = NULL, *listNodes = NULL;
    // head node of list
    listNodes = *head;
    
    // delete list
    while (listNodes)
    {

        prevNode = listNodes;
        listNodes = prevNode->next;

        if (signFreeData == 1)
        {
            free(((student_t*)prevNode->data)->family);
            free(((student_t*)prevNode->data)->group);
            free(prevNode->data);
        }
        prevNode->data = NULL;
        prevNode->next = NULL;
        free(prevNode);

        prevNode = NULL;
    }
    // set null to poiner of list
    *head = NULL;
}



