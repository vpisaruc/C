#include <stdio.h>

#include "functions.h"



int main(void)
{
    char strReturn[1024];
    int retVal;

    strcpy(strReturn, "Initial String for testing");
    retVal = snprintf(strReturn, 100, "d=%-10d hd=%-10hd o=%-10o s=%-15s;\n", 123456, 123456, 123456, "9876543210");
    if (retVal < 0)
    {
        printf("standard--- error=%d\n", retVal);
    }
    {
        printf("standard--- %d;  %s\n", retVal, strReturn);
    }

    strcpy(strReturn, "Initial String for testing");
    retVal = my_snprintf(strReturn, 100, "d=%-10d hd=%-10hd o=%-10o s=%-15s;\n", 123456, 123456, 123456, "9876543210");
    if (retVal < 0)
    {
        printf("my funct--- error=%d\n\n", retVal);
    }
    {
        printf("my funct--- %d;  %s\n\n", retVal, strReturn);
    }

    strcpy(strReturn, "Initial String for testing");
    retVal = snprintf(strReturn, 10, "%s", "9876543210");
    if (retVal < 0)
    {
        printf("standard--- error=%d\n", retVal);
    }
    {
        printf("standard--- %d;  %s\n", retVal, strReturn);
    }

    strcpy(strReturn, "Initial String for testing");
    retVal = my_snprintf(strReturn, 10, "%s", "9876543210");
    if (retVal < 0)
    {
        printf("my funct--- error=%d\n\n", retVal);
    }
    {
        printf("my funct--- %d;  %s\n\n", retVal, strReturn);
    }

    strcpy(strReturn, "Initial String for testing");
    retVal = snprintf(strReturn, 0, "%s", "9876543210");
    if (retVal < 0)
    {
        printf("standard--- error=%d\n", retVal);
    }
    {
        printf("standard--- %d;  %s\n", retVal, strReturn);
    }

    strcpy(strReturn, "Initial String for testing");
    retVal = my_snprintf(strReturn, 0, "%s", "9876543210");
    if (retVal < 0)
    {
        printf("my funct--- error=%d\n\n", retVal);
    }
    {
        printf("my funct--- %d;  %s\n\n", retVal, strReturn);
    }


    return 0;
}


