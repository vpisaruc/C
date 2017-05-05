#include <stdio.h>


float average_value(FILE *f, int *sr)
{
    int num,s,k;
    s = 0;
    k = 0;
    if (fscanf(f, "%d", sr) == 1)
    {
        while (fscanf(f, "%d", &num) == 1)
        {
            s += num;
            k += 1;
            return 0;
        }
    *sr = s/k;
    }
 return -1;
}



int main(void)
{
    FILE *f;
    float sr;

    f = fopen("test.txt", "r");
    if (f == NULL)
    {
    printf("I/O error\n");
    return -1;
    }
    if (average_value(f,&sr) == 0)
        printf("Average value is %f\n", sr);
    else
        printf("There are not enough data or file is empty.\n");
    fclose(f);
    return 0;
}
