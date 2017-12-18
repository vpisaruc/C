#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


#define OK                           0
#define FGETS_EOF                   -1
#define ERROR_FILE_DATA_STRUCTURE   -2
#define ERROR_FILE_EMPTY            -3
#define ERROR_FILE_OPEN_WRITE       -10
#define ERROR_FILE_NOT_EXISTS       -11


// return count first symbols from string *p where not exists in string *q 
size_t my_strcspn(const char *str, const char *sym);

// return new string with n first symbols or full str copy
char *my_strndup(const char *str, size_t n);

size_t my_getline(char **lineptr, size_t *n, FILE *stream);

char* my_str_replace(const char *source, const char *search, const char *replace);