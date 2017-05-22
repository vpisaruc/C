#include <stdio.h>
#include <stdbool.h>


#define INPUT_ERROR -1
#define NON_NEGATIVE -2
#define EMPTY -3
#define OK 0




int maxfind(FILE*f, int *mx)
{
    bool flag_1 = false, flag_2 = false;
    int number,  number_old = -1;
	
    
	while (fscanf(f,"%d",&number) == 1)
	{
		if (number < 0)
		{
			if (flag_1)
			{
				// Вывод результата
				printf("\n%d\n",number_old);
			}
			else
			{
				flag_1 = true;
			}
			number_old = -1;
		}
		else
	    {
			if (number > number_old && flag_1)
			{
				number_old = number;
			}
		}
	}
	
	// последний результат
	if (number_old != -1)
	{
		// Вывод результата
		printf("\n%d\n",number_old);		
		
		return OK;
	}
	else
	{
		if (flag_1) 
		{
			return NON_NEGATIVE;
		}
		else
		{
			return INPUT_ERROR;		
		}
	}
   
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