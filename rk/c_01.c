
#include <stdio.h>
#include <assert.h>

#define OK 0
#define FILE_ERROR -1
#define ZERO_ELEMESTS -2




int fill_arrays(FILE *file,int *size, int *array)
{
    int s;
    int i = 0 ;

    if (fscanf(file, "%d", size) == 1)
    {
        s = *size;
        assert(s < 100);
        while (fscanf(file, "%d", &array[i]) == 1)
        {
            i++;
        }
        if (s > 0)
        {
            return s;
        }
        else
        {
            return ZERO_ELEMESTS;
        }
    }
return FILE_ERROR;
}



int check_array(int *a, int size_a, int *b, int size_b, int *cntEqual)
{
    int i1 = 0, i2 = 0, cnt = 0;
    if(size_a != 0)
    {
        if(size_b!= 0)
        {
            while (i1 < size_a && i2 < size_b)
            {
                if (a[i1] < b[i2])
                {
                    i1++;
                }
                else if (a[i1] == b[i2])
                {
                    cnt++;
                    i1++;
                    i2++;
                }
                else if (a[i1] > b[i2])
                {
                    i2++;
                }
                
            }
        *cntEqual = cnt;
        return OK;
        }
    return ZERO_ELEMESTS;
    }
return ZERO_ELEMESTS;

}



void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%4d", array[i]);
    }

    printf("\n\n");
}





int main(int argc, char **argv)
{
    int a[100], b[100];
    int size_a = 0;
    int retVal;
    int size_b = 0; 
    int cntEqual = 0;
    FILE *file;
    FILE *file1;
    file = fopen(argv[argc - 1], "r");  
    file1 = fopen(argv[argc - 2], "r"); 
    size_a = fill_arrays(file,&size_a,a);
    if (argc == 3)
    {
        if (size_a == ZERO_ELEMESTS)
        {
            printf("\nArray is empty\n");
        }
        if (size_a == FILE_ERROR)
        {
            printf("\nWrong data in file\n");
        }
        else
        {
            size_b = fill_arrays(file1,&size_b,b);
            if (size_b == ZERO_ELEMESTS)
            {
                printf("\nArray is empty\n");
            }
            if (size_b == FILE_ERROR)
            {
                printf("\nWrong data in file\n");
            }
            else
            {
                retVal = check_array(a, size_a, b, size_b, &cntEqual);
                if (retVal == 0)
                {
                    printf("\nArray x: \n");
                    print_array(a, size_a);
                    printf("\nArray y: \n");
                    print_array(b, size_b);
                    printf("\nCount of numbers in both arrays = %d\n", cntEqual);
                }
                else
                {
                    printf("Size of one array == 0");
                }
            }
            
        }
    }
    else
    {
        printf("Print only 2 filese and exe file");
    }
}

