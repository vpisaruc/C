#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"


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
    printf("line [0 - 1] %e\n", integral(0.0, 1.0, 0.001, trapezium, line));
    printf("parabola [0 - 1] %e\n", integral(0.0, 1.0, 0.001, trapezium, parabola));
    printf("parabola [-1 - 1] %e\n", integral(-1.0, 1.0, 0.001, trapezium, sq));
    return 0;
}

