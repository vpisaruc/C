#include "functions.h"


int main(int argc, char **argv)
{
    char *fileNameInp, *errMsg, searchStr[14];
    node_t *listOfStudents = NULL, *listOfStudentsWork = NULL, *findNode = NULL, *newNode = NULL;
    int retVal = OK;

    fileNameInp = argv[1];

    // Input parameters
    printf("\nInput student name for search\n");
    scanf("%s", searchStr);
    newNode = getInsertNode();

    // load data from input file
    retVal = loadFileData(fileNameInp, &listOfStudents);
    errMsg = getErrorMessage(retVal);

    // Print and copy input ddata
    if (retVal == OK)
    {
        // print input list
        printListOfStudents("Input data", listOfStudents);

        // copy input list
        retVal = copy(listOfStudents, &listOfStudentsWork);
        if (retVal == OK)
        {
            // print input list
            printListOfStudents("Copy data", listOfStudentsWork);
        }
    }

    // Search and print data
    if (retVal == OK)
    {
        findNode = find(listOfStudentsWork, searchStr, compareStringData);
        if (!findNode)
        {
            printf("Student not found");
        }
        else
        {
            printf("Search student - %s", searchStr);
            printNodeData((student_t*)findNode->data);
            printf("\n\n");
        }

        // insert new student before find
        insert(&listOfStudentsWork, newNode, findNode);

        // print input list with insert
        printListOfStudents("Input data with insert", listOfStudentsWork);

        // sorting list using function sorted_insert
        listOfStudentsWork = sort(listOfStudentsWork, compareStringData);

        // print sorted list
        printListOfStudents("Sorted list", listOfStudentsWork);
    }

    //Print error message
    printf("%s", errMsg);

    return retVal;
}

