#include <stdio.h>
#include <assert.h>
#include <math.h>

typedef double (*func_t)(double);


typedef double (*method_t)(double, double, int, func_t);


double integral(double a, double b, double eps, method_t meth, func_t func)
{
    assert(a < b);
    assert(0 < eps && eps < 1);
    assert(meth);
    assert(func);

    int n = 10;
    double prev, cur = meth(a, b, n, func);

    do
    {
        prev = cur;

        n *= 2;
        cur = meth(a, b, n, func);
    }
    while (fabs((cur - prev) / cur) > eps);

    printf("%d\n", n);

    return cur;
}


// n - number of points
double trapezium(double a, double b, int n, func_t func)
{
    assert(a < b);
    assert(n > 1);
    assert(func);

    double h = (b - a) / (n - 1);
    double 
    x = a + h;
    double s = (func(a) + func(b)) / 2.0;

    for (int i = 1; i < n - 1; i++)
    {
        s += func(x);
        x += h;
    }

    return s * h;
}


double FindRoot(double a,double b,double eps, func_t func)
{
    double c;
    while((b-a)/2>eps)
    {
        c=(a+b)/2;
        if((f(a)*f(c))>0) a=c;
        else b=c;
    }
    return c;
}
