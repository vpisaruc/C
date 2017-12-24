#include "functions.h"

int main(void)
{
    node_t *listOfStudents = NULL, *listOfStudentsWork = NULL, *findNode = NULL, *findNodeSample = NULL;
    int retVal = OK;

    // Test data
/*
Input data in file in_2.txt
 1  IU1-11    Antonov       5  5  4
 2  IU1-13    Pisaruc       4  5  4
 3  IU1-11    Samoilenko    3  4  4
 4  IU1-12    Kutepov       4  3  4
 5  IU1-11    Ianchik       5  4  5
 6  IU1-12    Prohorov      4  4  3
 7  IU1-13    Zaseev        3  3  4
 8  IU1-11    Erohin        5  5  5
 9  IU1-11    Kuzmin        5  4  4
10  IU1-13    Pinchuk       5  4  4
*/

    // load data from input file
    retVal = loadFileData("in_2.txt", &listOfStudents);
    if (retVal == OK)
    {
        // Test COPY COMMAND
/*
Data in file out_2_result.txt
 1  IU1-11    Antonov       5  5  4
 2  IU1-13    Pisaruc       4  5  4
 3  IU1-11    Samoilenko    3  4  4
 4  IU1-12    Kutepov       4  3  4
 5  IU1-11    Ianchik       5  4  5
 6  IU1-12    Prohorov      4  4  3
 7  IU1-13    Zaseev        3  3  4
 8  IU1-11    Erohin        5  5  5
 9  IU1-11    Kuzmin        5  4  4
10  IU1-13    Pinchuk       5  4  4
*/


        // Print and copy input ddata
        printf("Test 1 - function copy (list1 to list2)\n");
        // copy input list
        retVal = copy(listOfStudents, &listOfStudentsWork);
        if (retVal == OK)
        {
            // write result to out_2.txt
            retVal = writeFileData("out_2.txt", listOfStudentsWork);

            if (retVal == OK)
            {
                // compare files result copy (out_2.txt) and sample test data (out_2_result.txt)
                retVal = compareFileData("out_2.txt", "out_2_result.txt");
            }
        }
        if (retVal == OK)
        {
            printf("Test 1 - OK\n\n");
        }
        else
        {
            printf("Test 1 - Failed\n\n\n");
        }

        // Test 2 - find record
        printf("Test 2 - find data by Family (Pisaruc)\n");
/*
Search family
Pisaruc
Find data
 2  IU1-13    Pisaruc       4  5  4
*/
        // set Sample data
        findNodeSample = setNodeTest(2, "Pisaruc", "IU1-13", 4, 5, 4);
        findNode = find(listOfStudentsWork, "Pisaruc", compareStringData);
        if (!findNode)
        {
            retVal = DATA_NOT_FOUND;
        }
        else
        {
            if (compareStudentData((student_t*)findNodeSample->data, (student_t*)findNode->data) == OK)
            {
                printf("Sample data\n");
                printNodeData((student_t*)findNodeSample->data);
                printf("Search data\n");
                printNodeData((student_t*)findNode->data);
            }
            else
            {
                retVal = DATA_NOT_EQUAL;
            }
        }
        if (retVal == OK)
        {
            printf("Test 2 - OK\n\n\n");
        }
        else
        {
            printf("Test 2 - Failed\n\n\n");
        }


        // Test 3 - insert record before rows (not first) 
        retVal = OK;
        printf("Test 3 - Insert sample data before rows (not first) Pisaruc\n");
/*
Data in file out_3_result.txt
 1  IU1-11    Antonov       5  5  4
99  TestGrp   Test          3  4  5
 2  IU1-13    Pisaruc       4  5  4
 3  IU1-11    Samoilenko    3  4  4
 4  IU1-12    Kutepov       4  3  4
 5  IU1-11    Ianchik       5  4  5
 6  IU1-12    Prohorov      4  4  3
 7  IU1-13    Zaseev        3  3  4
 8  IU1-11    Erohin        5  5  5
 9  IU1-11    Kuzmin        5  4  4
10  IU1-13    Pinchuk       5  4  4
*/

        // set Sample data
        findNodeSample = setNodeTest(99, "Test", "TestGrp", 3, 4, 5);
        // insert node before
        insert(&listOfStudentsWork, findNodeSample, findNode);
        // write result to out_3.txt
        retVal = writeFileData("out_3.txt", listOfStudentsWork);
        if (retVal == OK)
        {
            // compare files result copy (out_3.txt) and sample test data (out_3_result.txt)
            retVal = compareFileData("out_3.txt", "out_3_result.txt");
        }
        if (retVal == OK)
        {
            printf("Test 3 - OK\n\n");
        }
        else
        {
            printf("Test 3 - Failed\n\n\n");
        }

        // Test 4 - insert record before first row 
        retVal = OK;
        printf("Test 4 - Insert sample data before first row Antonov\n");


        // set Sample data
        findNodeSample = setNodeTest(98, "TestFirst", "TestGrp", 4, 4, 3);
        findNode = find(listOfStudentsWork, "Antonov", compareStringData);
        if (!findNode)
        {
            retVal = DATA_NOT_FOUND;
        }
        else
        {
            // insert node before
            insert(&listOfStudentsWork, findNodeSample, findNode);
            // write result to out_4.txt
            retVal = writeFileData("out_4.txt", listOfStudentsWork);
            if (retVal == OK)
            {
                // compare files result copy (out_4.txt) and sample test data (out_4_result.txt)
                retVal = compareFileData("out_4.txt", "out_4_result.txt");
            }
        }
        if (retVal == OK)
        {
            printf("Test 4 - OK\n\n");
        }
        else
        {
            printf("Test 4 - Failed\n\n\n");
        }

        
        // Test 5 - find record
        retVal = OK;
        printf("Test 5 - sort list\n");
/*
Data in file out_5_result.txt
 1  IU1-11    Antonov       5  5  4
 8  IU1-11    Erohin        5  5  5
 5  IU1-11    Ianchik       5  4  5
 4  IU1-12    Kutepov       4  3  4
 9  IU1-11    Kuzmin        5  4  4
10  IU1-13    Pinchuk       5  4  4
 2  IU1-13    Pisaruc       4  5  4
 6  IU1-12    Prohorov      4  4  3
 3  IU1-11    Samoilenko    3  4  4
99  TestGrp   Test          3  4  5
98  TestGrp   TestFirst     4  4  3
 7  IU1-13    Zaseev        3  3  4
*/
        // sorting list using function sorted_insert
        listOfStudentsWork = sort(listOfStudentsWork, compareStringData);
        // write result to out_5.txt
        retVal = writeFileData("out_5.txt", listOfStudentsWork);
        if (retVal == OK)
        {
            // compare files result copy (out_5.txt) and sample test data (out_5_result.txt)
            retVal = compareFileData("out_5.txt", "out_5_result.txt");
        }
        if (retVal == OK)
        {
            printf("Test 5 - OK\n\n");
        }
        else
        {
            printf("Test 5 - Failed\n\n\n");
        }
    }


    //Print error message
    printf("Exit test");

    return retVal;

}