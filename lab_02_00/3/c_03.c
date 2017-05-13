#include <stdio.h>
#include <math.h>
#define WRONG_INPUT_1 -1 
#define WRONG_INPUT_2 -2
#define OK 0


float step(float a, float n) 
{
    if(n == 0) 
    {
        return 1;
    }
    return a * step(a, n - 1);
}

int fac(int n) 
{
   return n<=1 ? 1 : n * fac(n-1);
}

float sum(int x,float eps)
{
    float s,z,k;
    s = 1;
    z = x;
    k = 1;
    while (fabs(z) > eps)
    {
	    z = step(x, k)/fac(k);
	    s += z;
	    k += 1;
    }
    return s;
}





int main(void)
{
    float x, eps, ab, otn;
    printf("\n\nInput X: ");
    if(scanf("%f", &x) !=1)
	{
		printf("I/O error\n");
		return WRONG_INPUT_1;
	}
    printf("\n\nInput epsilion: ");
    if(scanf("%f", &eps) != 1)
	{
		printf("I/O error\n");
		return WRONG_INPUT_2;
	}
    printf("\n\nSumma reada s tocinostiu %f ravna %f", eps, sum(x,eps));	
    printf("\n\ne ^ x = %f ", ex(x));
    ab = fabs(exp(x) - sum(x,eps));
    otn = fabs((exp(x) - sum(x,eps))/exp(x));
    printf("\n\nAbsoliutnaia oshibka: %f", ab);
    printf("\n\nOtnositelinaia oshibka: %f", otn);
    printf("\n\n");	
	
    return OK;

}