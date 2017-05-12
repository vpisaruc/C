#include <stdio.h>
#include <math.h>


#define OK 0
#define WRONG_INPUT_1 -1
#define WRONG_INPUT_2 -2
#define FILE_ERROR -3
#define EMPTY_FILE -4


float average_value(FILE *file, float *middle)
{
    float num_1,s,k;
    k = 0;
    
    if (fscanf(file, "%f", middle) == 1)
    {
        while (fscanf(file, "%f", &num_1) == 1)
        {
            s += num_1;
            k += 1;
            
        }



        *middle = s/k;

        return OK;
    
    }
    return WRONG_INPUT_1;
}



float number_near_middle(FILE *file, float *true_number, float *md )
{
    float minus_1, minus_2, num_2;
    //int num_2;



    if (fscanf(file, "%f", true_number) == 1)
    {
        minus_1 = fabs(*true_number - *md);
        while (fscanf(file, "%f", &num_2) == 1)
        {
            minus_2 = fabs(num_2 - *md);
            if (minus_1 > minus_2)
            {
                *true_number = num_2;
                minus_1 = minus_2;
            }

        }
        return OK;
    }
    return WRONG_INPUT_2;
}



int main(int argc, char **argv)
{
    FILE *file;
    float md, middle,true_number;
    //int true_number;

    file = fopen(argv[argc-1], "r");


    if (file == NULL)
    {
        printf("I/O error\n");
        return FILE_ERROR;
    }





    if (average_value(file, &middle) == 0)
    {

        md = middle;
        printf("Average value is %f\n", md);
        rewind(file);
        if ((number_near_middle(file, &true_number, &md)) == 0)
        {
            printf("The nearest number to the average value is %f\n",true_number);
            fclose(file);
            return OK;
        }
    }
    else
    {
        printf("There are not enough data or file is empty.\n");
        return EMPTY_FILE;
    }
}
