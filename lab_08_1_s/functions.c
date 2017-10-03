#include <stdio.h>


#define OK 0
#define ELEMENTS_ERROR -2 
#define FILE_ERROR -3

#define N 5
#define M 7


int fill_matrix(FILE *file,int *size1, int *size2 , int arr[N][M])
{
    int n, m;
    int i = 0, j = 0 ;

    if (fscanf(file, "%d", size1) == 1)  
    {
        n = *size1;
        //printf("\n%d \n", n);
        if ((n > 0) && (n < 6))
        {
            if (fscanf(file, "%d", size2) == 1)
            {
                m = *size2;
                //printf("\n%d\n", m);
                if ((m > 0) && (m < 8))
                {
                    while (fscanf(file, "%d", &arr[i][j]) == 1)
                    {
                        j++;
                        if(j == m)
                        {
                            i++;
                            j = 0;
                        }
                        
                        if(i == n)
                        {
                            return OK;
                            break;
                        }
                    }

                }
                else
                {
                    return ELEMENTS_ERROR;
                }
            }
        }
        
        else
        {
            return ELEMENTS_ERROR;
        }
    }
    return FILE_ERROR;
}



void print(int arr[][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    printf("\n");
}
