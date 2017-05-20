#include <stdio.h>
#include <stdbool.h>


#define INPUT_ERROR -1
#define NON_NEGATIVE -2
#define EMPTY -3
#define OK 0




int maxfind(FILE*f, int *mx)
{
    bool flag_1 = false, flag_2 = false;
    int number;
    if (fscanf(f,"%d",mx) == 1)
    {
        while (fscanf(f,"%d",&number) == 1)
        {
            if (number < 0)
            {
                flag_1 = true;
            }
            if (number > *mx)
            {
                *mx = number;
            }
        }
        if (flag_1 ==true)
        {
            return OK;
        }
        elses
        {
            return NON_NEGATIVE;
        }
    }
    return INPUT_ERROR;
}



int main(void)

{
    int mx;
    if (maxfind(stdin, &mx) != OK)
    {
        printf("File is empty or there are not enought information  \n\n");
        return EMPTY;
    }
    else 
    {
        printf("Maximum after minus number is %d \n\n", mx);
    }
    return OK;
}