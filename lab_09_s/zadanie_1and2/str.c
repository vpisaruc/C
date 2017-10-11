#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"

int count_words(const char *str)
{
    int count = 0;
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        if(!strchr(DELIMS,str[i]))
        {
            if(i == 0 || strchr(DELIMS,str[i-1]))
            {
                count++;
            }
        }
    }
    return count;
}

void split_words(char *str, char *words[])
{
    int n = 0;
    int q = strlen(str);
    for(int i = 0; i < q; i++)
    {
        if (strchr(DELIMS,str[i]))
        {
            str[i] = '\0';
        }
        else if (i == 0 || str[i-1] == '\0')
        {
            words[n] = str+i;
            n++;
        }
    }
}

void print_words(char *words[], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        printf("[%s]\n",words[i]);
    }
}

void sort_str(char *words[], int *n)
{
    int i,j;

    for(i = 0 ; i < *n - 1; i++) 
    { 
       for(j = 0 ; j < *n - i - 1 ; j++) 
       {  
           if(*words[j] > *words[j+1]) 
           {           
              printf("\nWORDS[J] ==%s\n", words[j]);
              printf("\nWORDS[J+1] ==%s\n", words[j+1]);
              char tmp = *words[j];
              *words[j] = *words[j+1] ;
              *words[j+1] = tmp;
           }
        }
    }
}





