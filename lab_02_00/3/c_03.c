#include <stdio.h>
#include <math.h>
#define WRONG_INPUT_1 -1 
#define WRONG_INPUT_2 -2
#define OK 0
#define NEGATIVE_EPS -3



float sum(int x,  float eps)
{
    float s,z;
    int i = 1;
    
    s = 1;
    z = 1;
    
    while (z > eps)
    {
        z = z * x/i;
        s += z;
        i += 1;
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
    if (eps <= 0)
    {
        printf("Eps could't be 0 or negative");
        return NEGATIVE_EPS;
    }
    printf("\n\nSumma reada s tocinostiu %f ravna %f", eps, sum(x,eps));	
    printf("\n\ne ^ x = %f ", exp(x));
    ab = fabs(exp(x) - sum(x,eps));
    otn = fabs((exp(x) - sum(x,eps))/exp(x));
    printf("\n\nAbsoliutnaia oshibka: %f", ab);
    printf("\n\nOtnositelinaia oshibka: %f", otn);
    printf("\n\n");	

    return OK;

}