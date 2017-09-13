#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "functions.h"


#define INPUT_ERROR 1

double f1(double x)
{
    return 3 * x + 2;
}


double f2(double x)
{
    return exp(x);
}


double f3(double x)
{
    return exp( -x + 2);
}



int main(void)
{
    double eps, a, b, root, per1, per2, per3;


    printf("Vvedite intervali integrirovaniia: ");
    if (scanf("%lf %lf", &a, &b) != 2)
    {
        printf("Vvedite dva chisla ");
        return INPUT_ERROR;
    }

    else
    {
        printf("Vvedite tocinosti: ");
        if (scanf("%lf", &eps) != 1)
        {
            printf("Vvedite chislo ");
            return INPUT_ERROR;
        }
        else
        {
            per1 = tochkki_peresech(a, b, eps, f1, f3);
            per3 = tochkki_peresech(a, b, eps, f2, f3);
            per2 = tochkki_peresech(a, b, eps, f1, f2);
            
            root = integral(per1, per2, eps, trapezium, f1) - integral(per1, per3, eps, trapezium, f3) + integral(per2, per3, eps, trapezium, f2);

            printf("%lf", root);
            return 0;
        }
    }
}
