#include <stdio.h>
#include <math.h>

static float
factorial (int n)
{
    float r;
    for (r = 1; n > 1; r *= (n--));
    return r;
}
#include <stdio.h>
#include <math.h>

static float
factorial (int n)
{
  float r;
  for (r = 1; n > 1; r *= (n--));
  return r;
}



float main(void)
{
    float x, eps, s, z, k, f, ab, otn;
    printf("\n\nInput X: ");
    scanf("%f", &x);
    printf("\n\nInput epsilion: ");
    scanf("%f", &eps);
    s = 1;
    z = x;
    k = 1;
    while (z > eps)
    {
	z = pow(x, k)/factorial(k);
	s += z;
	k += 1;
    }

    printf("\n\nSumma reada s tocinostiu %f ravna %f", eps, s);	
    f = exp(x);
    printf("\n\ne ^ x = %f ", f);
    ab = fabs(f - s);
    otn = fabs((f - s)/f);
    printf("\n\nAbsoliutnaia oshibka: %f", ab);
    printf("\n\nOtnositelinaia oshibka: %f", otn);
    printf("\n\n");	
	
    return 0;

}


float main(void)
{
    float x, eps, s, z, k, f, ab, otn;
	printf("\n\nInput X: ");
	scanf("%f", &x);
	printf("\n\nInput epsilion: ");
	scanf("%f", &eps);
	s = 1;
	z = x;
	k = 1;
	while (z > eps){
	    z = pow(x, k)/factorial(k);
	    s += z;
	    k += 1;
	}
        printf("\n\nSumma reada s tocinostiu %f ravna %f", eps, s);	
	f = exp(x);
    printf("\n\ne ^ x = %f ", f);
	ab = fabs(f - s);
	otn = fabs((f - s)/f);
	printf("\n\nAbsoliutnaia oshibka: %f", ab);
	printf("\n\nOtnositelinaia oshibka: %f", otn);
	printf("\n\n");	
	
	return 0;

}
