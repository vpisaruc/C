#include "functions.h"


// return count first symbols from string *p where not exists in string *q 
size_t my_strcspn(const char *str, const char *sym)
{
    int cnt = 0, signExists = 0;
    char *pidx = (char*)str, *qidx;

    while (*pidx)
    {
        qidx = (char*)sym;
        while (*qidx)
        {
            if (*qidx == *pidx)
            {
                signExists = 1;
                break;
            }
            qidx++;
        }
        if (signExists == 1)
            break;

        cnt++;
        pidx++;
    }

    return (size_t)cnt;
}


// return new string with n first symbols or full str copy
char *my_strndup(const char *str, size_t n)
{
    char *retStr, *strIdx, *retStrIdx;
    int strLength = 0;

    // ���������� ����� ������
    strIdx = (char*)str;
    while (*strIdx)
    {
        strLength++;
        strIdx++;
    }

    if (strLength > (int)n)
        strLength = (int)n;

    // �������� ������
    retStr = (char*) malloc((strLength + 1) * sizeof(char));

    // ���������� ������
    strIdx = (char*)str;
    retStrIdx = retStr;
    for (int i = 0; i < strLength; i++)
    {
        *retStrIdx = *strIdx;
        retStrIdx++;
        strIdx++;
    }
    *retStrIdx = 0;

    return retStr;
}


size_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t retStrSize = 0;
    char str[128];
    char *retStr, *strIdx, *retStrIdx;

    if (fgets(str, sizeof(str), stream) == NULL)
    {
        // EOF find
        return FGETS_EOF;
    }

    // ���������� ����� ������
    strIdx = str;
    while (*strIdx)
    {
        retStrSize++;
        strIdx++;
    }

    // �������� ������
    retStr = (char*)malloc((retStrSize + 1) * sizeof(char));

    // ���������� ������
    strIdx = (char*)str;
    retStrIdx = retStr;
    for (int i = 0; i < (int)retStrSize; i++)
    {
        *retStrIdx++ = *strIdx++;
    }
    *retStrIdx = 0;

    // ������������ ��������
    *n = retStrSize;
    *lineptr = retStr;

    return retStrSize;
}



char*my_str_replace(const char *source, const char *search, const char *replace)
{
    int retStrSize = 0, searchLength = 0, replaceLength = 0, delta, signEqual, cnt = 0;
    char *retStr, *strIdx, *strIdxMark, *retStrIdx, *replaceIdx, *searchIdx;

    // ���������� ����� ������
    strIdx = (char*)source;
    while (*strIdx)
    {
        retStrSize++;
        strIdx++;
    }
    // ���������� ����� ������ ��� ������
    searchIdx = (char*)search;
    while (*searchIdx)
    {
        searchLength++;
        searchIdx++;
    }
    // ���������� ����� ������ ��� ������
    replaceIdx = (char*)replace;
    while (*replaceIdx)
    {
        replaceLength++;
        replaceIdx++;
    }
    // ������� � ����� �����
    delta = replaceLength - searchLength;

    // �������� ������
    retStr = (char*)malloc((retStrSize + 1) * sizeof(char));

    // ���������� ������
    strIdx = (char*)source;
    searchIdx = (char*)search;
    retStrIdx = retStr;
    while (*strIdx)
    {
        if (*strIdx == *searchIdx)
        {
            signEqual = 1;
            strIdxMark = strIdx;
            for (int i = 1; i < searchLength; i++)
            {
                strIdxMark++;
                searchIdx++;
                if (*strIdxMark != *searchIdx)
                {
                    signEqual = 0;
                    break;
                }
            }
            if (signEqual == 1)
            {
                // ��������� �������� ������
                retStrSize = retStrSize + delta;
                retStr = (char*)realloc(retStr, (retStrSize + 1) * sizeof(char));
                retStrIdx = retStr + cnt;
                strIdx = strIdx + searchLength;

                // ������ replace ������
                replaceIdx = (char*)replace;
                for (int i = 0; i < replaceLength; i++)
                {
                    *retStrIdx++ = *replaceIdx++;
                    cnt++;
                }
            }
            else
            {
                // ���������� ������� (����� ������ �� ����� ������ ������)
                *retStrIdx++ = *strIdx++;
                cnt++;
            }
            // ������ �� ������ ������ ������
            searchIdx = (char*)search;
        }
        else
        {
            // ���������� �������
            *retStrIdx++ = *strIdx++;
            cnt++;
        }
    }
    *retStrIdx = 0;

    return retStr;
}