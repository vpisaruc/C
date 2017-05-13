#include <stdio.h>
#include <stdlib.h>


#define WRONG_INPUT_1 -1 
#define WRONG_INPUT_2 -1 


int step(int a, int n) {
    if(n == 0) 
    {
        return 1;
    }
    return a * step(a, n - 1);
 }
 
int main(void) {
    int a,n;
    printf("Введите число a и степень n: \n");
    if(scanf ("%d %d", &a, &n) != 2)
	{
		printf("I/O error\n\n");
		return WRONG_INPUT_2;
	}
    if(n<0)
    {
        printf("Введите положительную степень \n");
		return WRONG_INPUT_1;
    }
    printf("%d\n", step (a, n));
}