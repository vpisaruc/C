#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "defines.h"
#include "str.h"

int main(void)
{

    char str[] = "   .,. Victor    ! adfg cfg && zxcg  .";
    int n = count_words(str);
    if (n == 0)
    {
        
        printf("Пустая строка");
        return NO_WORDS;
    }
    else
    {
        char **words = malloc(n*sizeof(char*));
        if (words != NULL)
        {
            split_words(str,words);

        }
        
        printf("\nВывод первоначальной строки:\n");
        print_words(words, &n);
        printf("\n");
        sort_str(words, &n);
        printf("\nВывод отсортированной строки:\n");
        print_words(words, &n);
        free(words);
    }
    return OK;
}
