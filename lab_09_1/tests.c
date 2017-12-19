#include "functions.h"



int main(void)
{
    char *str1, *str2;
    //int retVal;
    size_t cnt;
    size_t retStrLength;
    FILE * f1, * f2;
    char *strSearch = "Structures";
    char *strReplace = "st";

    f1 = fopen("in_1.txt", "r");
    f2 = fopen("in_2.txt", "r");

    str1 = "123456";
    str2 = "56";

    printf("\nTest my_strcspn №1\n");
    printf("str1 = 123456 str2 = 56\n");
    cnt = my_strcspn(str1, str2);
    if ((int)cnt == 4)
        printf("Passed\n");
    else
        printf("Failed\n");

    str1 = "123456";
    str2 = "";

    printf("\nTest my_strcspn №2\n");
    printf("str1 = 123456 str2 = \n");
    cnt = my_strcspn(str1, str2);

    if ((int)cnt == 6)
        printf("Passed\n");
    else
        printf("Failed\n");

    str1 = "";
    str2 = "";

    printf("\nTest my_strcspn №3\n");
    printf("str1 =  str2 = \n");
    cnt = my_strcspn(str1, str2);

    if ((int)cnt == 0)
        printf("Passed\n");
    else
        printf("Failed\n");


    str1 = "123456";
    

    printf("\nTest my_strndup №1\n");
    printf("str1 = 123456 n = 3\n");
    str2 = my_strndup(str1, 3);

    if (strcmp("123", str2) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");
    

    printf("\nTest my_strndup №2\n");
    printf("str1 = 123456 n = 7\n");
    str2 = my_strndup(str1, 7);

    if (strcmp("123456", str2) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");


    str1 = "";
    printf("\nTest my_strndup №3\n");
    printf("str1 =  n = 1\n");
    str2 = my_strndup(str1, 7);

    if (strcmp("", str2) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");


    char **lineptr = (char**)malloc(sizeof(char));
    printf("\nTest my_getline №1\n");
    printf("File: Empty\n");
    cnt = my_getline(lineptr, &retStrLength, f2);

    if ((int)cnt == FGETS_EOF)
        printf("Passed\n");
    else
        printf("Failed\n");
    fclose(f2);

    printf("\nTest my_getline №2\n");
    printf("File: Not Empty\n");
    cnt = my_getline(lineptr, &retStrLength, f1);
    if ((int)cnt != FGETS_EOF)
        printf("Passed\n");
    else
        printf("Failed\n");
    fclose(f1);


    printf("\nTest my_str_replace №1\n");
    printf("String: \n");
    *lineptr = my_str_replace(*lineptr, strSearch, strReplace);

    if (strcmp("st str ml st", *lineptr) != 0)
        printf("Passed\n");
    else
        printf("Failed\n");


    return OK;
}