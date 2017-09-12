#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"


#define INPUT_ERROR 1

double line(double x)
{
    return x;
}


double parabola(double x)
{
    return x * x;
}

double sq(double x)
{
    return sqrt(fabs(x));
} 


int main(void)
{
    double eps, a, b;

    printf("Vvedite tocinosti: ");
    if (scanf("%lf",eps) != 1)
    {
        printf("Vvedite chislo ");
        return INPUT_ERROR;
    }
    
    printf("Vvedite intervali integrirovaniia: ");
    if (scanf("%lf %lf",a, b) != 2)
    {
        printf("Vvedite dva chisla ");
        return INPUT_ERROR;
    }

    printf("line [0 - 1] %e\n", integral(0.0, 1.0, 0.001, trapezium, line));
    printf("parabola [0 - 1] %e\n", integral(0.0, 1.0, 0.001, trapezium, parabola));
    printf("parabola [-1 - 1] %e\n", integral(-1.0, 1.0, 0.001, trapezium, sq));
    return 0;
}

