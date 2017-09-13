#include <stdio.h>
#include <assert.h>
#include <math.h>

typedef double (*func_t)(double);


typedef double (*method_t)(double, double, int, func_t);



//Vichisl integral
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


//Nahodim ploshiadi
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





//Ishim tochkki peresech
double tochkki_peresech(double a, double b, double eps, func_t f1, func_t f2)
{
    double c;
    if (f1(a) == f2(a))
    {
        return a;
    }
    if (f1(b) == f2(b))
    {
        return b;
    }
    while ((b - a) > eps)
    {
        c = (b - a) / 2;
        printf("%e\n", c);
        if ((f1(a) > f2(a) && f1(c) < f2(c)) || (f1(a) < f2(a) && f1(c) > f2(c)))
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    return c;
}
