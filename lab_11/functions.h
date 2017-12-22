#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define OK                           0

// formats
#define PARAM_SHORT                  1
#define PARAM_INT                    2
#define PARAM_OCTAL                  3
#define PARAM_STRING                 4

// error codes
#define SIZE_ERROR                  -1
#define INCORRECT_PARAM_TYPE        -4
#define MEMMORY_ERROR               -6


// analyze input char; if != % or % is not format return 0; else return format type
int getFormatData(char *inputStr, int *paramType, int *strLength, int *signRightFormat);

// my snprintf function
int my_snprintf(char *s, size_t n, const char *format, ...);

// string from int with formatting
int intToStringFormat(char *outStr, const int maxLen, const int strLength, const int div_10_8, const int signRightFormat, int intValue);

// string with formatting
int stringFormat(char *outStr, const int strLength, const int maxLen, const int signRightFormat, const char *strValue);

