#include <stdarg.h>
#include "functions.h"


// analyze input char; if != % or % is not format return 0; else return number of skip characters 
int getFormatData(char *inputStr, int *paramType, int *strLength, int *signRightFormat)
{
    char *tmpStr;
    int retValue = 0;

    // start of testing characters
    tmpStr = inputStr;
    
    if (*tmpStr == '%')
    {
        retValue = 1;

        *strLength = 0;
        // right formatting
        *signRightFormat = 1;

        // next character
        tmpStr++;
        
        if (*tmpStr == '-')
        {
            // left formatting
            *signRightFormat = 0;
            tmpStr++;
            retValue++;
        }

        // get format type
        if (*tmpStr == 'd')
        {
            // integer format
            // skip 2 characters for resultStr
            retValue++;
            *paramType = PARAM_INT;
        }
        else if (*tmpStr == 's')
        {
            // string format
            // skip 2 characters for resultStr
            retValue++;
            *paramType = PARAM_STRING;
        }
        else if (*tmpStr == 'o')
        {
            // octal format
            // skip 2 characters for resultStr
            retValue++;
            *paramType = PARAM_OCTAL;
        }
        else if ((*tmpStr == 'h') && (*(tmpStr + 1) == 'd'))
        {
            // short format
            // skip 2 characters for resultStr
            retValue++;
            retValue++;
            *paramType = PARAM_SHORT;
        }
        else if ((*tmpStr >= '0') && (*tmpStr <= '9'))
        {
            // calculating length of returning string
            while ((*tmpStr >= '0') && (*tmpStr <= '9'))
            {
                *strLength = *strLength * 10 + *tmpStr - 48;
                retValue++;
                tmpStr++;
            }
            // get format type
            if (*tmpStr == 'd')
            {
                // integer format
                // skip 2 characters for resultStr
                retValue++;
                *paramType = PARAM_INT;
            }
            else if (*tmpStr == 's')
            {
                // string format
                // skip 2 characters for resultStr
                retValue++;
                *paramType = PARAM_STRING;
            }
            else if (*tmpStr == 'o')
            {
                // octal format
                // skip 2 characters for resultStr
                retValue++;
                *paramType = PARAM_OCTAL;
            }
            else if ((*tmpStr == 'h') && (*(tmpStr + 1) == 'd'))
            {
                // short format
                // skip 2 characters for resultStr
                retValue++;
                retValue++;
                *paramType = PARAM_SHORT;
            }
            else
            {
                // % not is not existing format
                retValue = 0;
            }
        }
        else
        {
            // % not is not existing format
            retValue = 0;
        }
    }

    return retValue;
}


// my snprintf function
int my_sprintf(char *s, size_t n, const char *format, ...)
{
    char *formatStr = NULL, *outputStr = NULL, *valueString = NULL, *argValueStr = NULL, *valueStringIdx = NULL;
    int strLength = 0, signRightFormat = 0, retVal = 0, paramType = 0, argValueInt, returnCount = 0, skipCount = 0;
    va_list argptr;

    // initialization list of parameters for formatting string
    va_start(argptr, format);

    // begin input format string
    formatStr = (char*)format;
    outputStr = (char*)s;
    
    // memory for valueString
    valueString = (char*)malloc(1024 * sizeof(char));
    if (valueString == NULL)
    {
        return MEMMORY_ERROR;
    }

    // format string
    while (*formatStr != 0)
    {
        // initial values
        strLength = 0;
        signRightFormat = 0;
        paramType = 0;
        
        // checking parameter type
        retVal = getFormatData(formatStr, &paramType, &strLength, &signRightFormat);
        if (retVal == 0)
        {
            // copy char from format string to output string
            returnCount++;
            if (returnCount < (int)n)
            {
                // outpet only if length < max
                *outputStr++ = *formatStr++;
            }
        }
        else
        {
            skipCount = retVal;
            switch (paramType)
            {
                case PARAM_SHORT:
                    argValueInt = va_arg(argptr, int);
                    argValueInt = (short)argValueInt;
                    retVal = intToStringFormat(valueString, n, strLength, 10, signRightFormat, argValueInt);
                    break;
                case PARAM_INT:
                    argValueInt = va_arg(argptr, int);
                    retVal = intToStringFormat(valueString, n, strLength, 10, signRightFormat, argValueInt);
                    break;
                case PARAM_OCTAL:
                    argValueInt = va_arg(argptr, int);
                    retVal = intToStringFormat(valueString, n, strLength, 8, signRightFormat, argValueInt);
                    break;
                case PARAM_STRING:
                    argValueStr = va_arg(argptr, char*);
                    retVal = stringFormat(valueString, strLength, n, signRightFormat, argValueStr);
                    break;
                default:
                    retVal = SIZE_ERROR;
                    break;
            }
            if (retVal < 0)
            {
                // error during getting formatted string
                returnCount = SIZE_ERROR;
                break;
            }
            // change index for format string
            formatStr = formatStr + skipCount;

            // output formatted string
            valueStringIdx = valueString;
            for (int i = 0; i < retVal; i++)
            {
                returnCount++;
                if (returnCount < (int)n)
                {
                    // outpet only if length < max
                    *outputStr++ = *valueStringIdx++;
                }
            }
        }
    }
    if (n > 0)
    {
        // end of string
        *outputStr++ = 0;
    }

    // free for malloc
    free(valueString);
    // close list of parameters
    va_end(argptr);

    return returnCount;
}


// string from int with formatting
int intToStringFormat(char *outStr, const int maxLen, const int strLength, const int div_10_8, const int signRightFormat, int intValue)
{
    int cnt = 0, cntSign = 0, afterDiv, spacesBefore = 0, spacesAfter = 0, retValue = 0, tmpValue;
    char tmpStr[50];
    char *tmpStrIdx, *outStrIdx;

    tmpStrIdx = tmpStr;
    outStrIdx = outStr;
    tmpValue = intValue;

    if (tmpValue < 0)
    {
        cntSign = 1;
        tmpValue = -tmpValue;
    }

    if (tmpValue == 0)
    {
        cnt = 1;
        *tmpStrIdx++ = '0';
    }
    else
    {
        // inversion 
        while (tmpValue != 0)
        {
            afterDiv = tmpValue / div_10_8;
            *tmpStrIdx++ = tmpValue - afterDiv * div_10_8 + 48;
            cnt++;
            tmpValue = tmpValue / div_10_8;
        }
    }

    // calculating spaces
    if ((strLength > 0) && ((cnt + cntSign) < strLength))
    {
        if (signRightFormat == 1)
        {
            spacesBefore = strLength - cnt - cntSign;
        }
        else
        {
            spacesAfter = strLength - cnt - cntSign;
        }
    }

    // normal return
    // Spaces before string
    for (int i = 1; i <= spacesBefore; i++)
    {
        *outStrIdx++ = ' ';
    }
    // sign of value
    if (cntSign == 1)
    {
        *outStrIdx++ = '-';
    }
    // temp string in inverse order
    while (tmpStrIdx > tmpStr)
    {
        tmpStrIdx--;
        *outStrIdx++ = *tmpStrIdx;
    }
    // Spaces after string
    for (int i = 1; i <= spacesAfter; i++)
    {
        *outStrIdx++ = ' ';
    }
    //End of string(0) 
    *outStrIdx++ = 0;

    retValue = (cnt + cntSign + spacesBefore + spacesAfter);
    
    return retValue;
}


// string with formatting
int stringFormat(char *outStr, const int strLength, const int maxLen, const int signRightFormat, const char *strValue)
{
    int cnt = 0, spacesBefore = 0, spacesAfter = 0, retValue = 0;
    char *tmpStrIdx, *outStrIdx;

    tmpStrIdx = (char*)strValue;
    outStrIdx = outStr;

    // Length of input String
    while (*tmpStrIdx != 0)
    {
        cnt++;
        tmpStrIdx++;
    }

    // calculating spaces
    if ((strLength > 0) && (cnt < strLength))
    {
        if (signRightFormat == 1)
        {
            spacesBefore = strLength - cnt;
        }
        else
        {
            spacesAfter = strLength - cnt;
        }
    }

    // normal return
    // Spaces before string
    for (int i = 1; i <= spacesBefore; i++)
    {
        *outStrIdx++ = ' ';
    }
    // Out string
    tmpStrIdx = (char*)strValue;
    while (*tmpStrIdx != 0)
    {
        *outStrIdx++ = *tmpStrIdx++;
    }

    // Spaces after string
    for (int i = 1; i <= spacesAfter; i++)
    {
        *outStrIdx++ = ' ';
    }
    //End of string(0) 
    *outStrIdx++ = 0;
    
    retValue = cnt + spacesBefore + spacesAfter;

    return retValue;
}


