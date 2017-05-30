
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


int check_array(int *a, int size_a, int *b, int size_b, int *c)
{
	int size_c = 0, k;


	for (int i = 0; i < size_a; i++)
	{
		k = 0;
		for (int j = 0; j < size_b; j++)
		{
			if (b[j] == a[i])
			{
				k = 1;
				break;
			}
		}

		if (k == 0)
		{
			c[size_c] = a[i];
			size_c++;
		}
        
	}
    if (size_c == 0)
    {
        return ZERO_ELEMESTS;
    }
    else
    {
        return size_c;
    }
    assert(size_c <= size_a + size_b);
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
	int a[100], b[100], c[100];
	int size_a = 0; 
    int size_b = 0; 
    int size_c = 0;
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
                size_c = check_array(a, size_a, b, size_b, c);
                if (size_c ==ZERO_ELEMESTS)
                {
                    printf("\nZero elements array \n");
                }
                else
                {
                    printf("Array x: ");
	                print_array(a, size_a);
                    printf("Array y: ");
	                print_array(b, size_b);
                    printf("Array z: ");
	                print_array(c, size_c);
                }
            }
            
        }
    }
    else
    {
        printf("Print only 2 filese and exe file");
    }
	

}



