#include <stdio.h>
#include <assert.h>
#define True 1
#define OK 1
#define ERROR_1 -1
#define OUT_1 2
#define in 0

int fill_arrays(FILE *file,int *size_a, int *a)
{
    int num_1,s,t;
    int i = 0 ;
    int j = 0;
    int k = 0;

    if (fscanf(file, "%d", size_a) == 1)
    {
        s = *size_a;
        while (fscanf(file, "%d", &a[i]) == 1)
        {
            i++;
        }
        printf("\n\n");
        printf("Ishodnii massiv: ");
        for (int i = 0; i < s; i++)
        {
            printf("%4d", a[i]);
        }
        return i;
    }

}


int check(int num, int *a, int size) 
{
    int numArray = OUT_1; 
    int *p = a;
    while (p - a < size)
    {
        if (*p == num)
        {
            numArray = in; 
            break;
        }
        p++;
    }
    return numArray;
}

int fill(FILE *file, int *a, int size)
{
    int func_state = OK;
    int *p = a;
    while (True)
        if ((fscanf(file, "%d", &*p)) == EOF)
        {
            func_state = ERROR_1;
            break;
        }
        else if (p - a < 100)
            p++;
    return func_state;
}

int max(int a, int b)
{
    int result;
    if (a >= b)
        result = a;
    else
        result = b;
    return result;
}



int main(int argc, char **argv) 
{
    FILE *file;
    FILE *file1;
    int a[100];
    int b[100];
    int size_a, size_b;
    file = fopen(argv[1], "r");  
    file1 = fopen(argv[2], "r");  
    size_a = fill_arrays(file,&size_a,a);
    size_b = fill_arrays(file1,&size_b,b);
    printf("\nsize a: %d \n size_b:  %d\n",size_a,size_b);
    int maxSize = max(size_a, size_b);
    printf("\nMax size: %d\n",maxSize);
    int differ[maxSize];
    int i = 0;
    int k = 0;
    for(i=0;i<size_a;i++)
    {
        if (check(a[i],b,size_b))
        {
            differ[k] = a[i];
            k++;
        }
    }
    i = 0;
    for(i=0;i<k;i++)
        printf("%d ",differ[i]);
    printf("\n\n");
    return 0;
}


