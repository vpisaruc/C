#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define OK                           0
#define ERROR_FILE_NOT_EXISTS       -1
#define ERROR_FILE_DATA_STRUCTURE   -2
#define ERROR_FILE_EMPTY            -3
#define INCORRECT_PARAM             -4
#define NONE_ELEMENTS               -5
#define MEMMORY_ERROR               -6
#define SIZE_ERROR                  -7


// structure of list node
typedef struct node node_t;
struct node
{
    void *data;
    node_t *next;
};

//structure of student data 
typedef struct student_data student_t;
struct student_data
{
    char *family, *group;
    int examListId, examMark1, examMark2, examMark3;
};

// Functions declaration
// get error message
char* getErrorMessage(const int errId);

// load file data
int loadFileData(const char *fileName, node_t **listOfStudents);

// print node data 
void printNodeData(const student_t *studentData);

// print list of students data
void printListOfStudents(const char *headerStr, const node_t *listOfStudents);

// find student by family
node_t* find(node_t *head, const void *data, int(*comparator)(const void*, const void*));

// copy list of students
int copy(node_t *head, node_t **new_head);

// compare string
int compareStringData(const void* first, const void* second);

// insert node before
void insert(node_t **head, node_t *elem, node_t *before);

// setup insert node
node_t* getInsertNode();

// sorted insert into sorted list
void sorted_insert(node_t **head, node_t *element, int(*comparator)(const void *, const void *));

// sorting list using function sorted_insert
node_t* sort(node_t *head, int(*comparator)(const void *, const void *));