#include <stdio.h>
#include <math.h>

float main(void)
{
	float x_a, x_b, x_c, y_a, y_b, y_c, s1, s2, s3;
	printf("Pervuiu vershinu treugolinika: ");
	scanf("%f%f", &x_a, &y_a);
	printf("Vtoruiu vershinu treugolinika: ");
	scanf("%f%f", &x_b, &y_b);
	printf("Tretiu vershinu treugolinika: ");
	scanf("%f%f", &x_c, &y_c);
	
	s1 = fabsf(sqrt(pow((x_b - x_a),2)) + sqrt(pow((y_b - y_a), 2) ));
	s2 = fabsf(sqrt(pow((x_c - x_a),2)) + sqrt(pow((y_c - y_a), 2) ));
	s3 = fabsf(sqrt(pow((x_c - x_b),2)) + sqrt(pow((y_c - y_b), 2) ));
	
	if ((s1 + s2) <= s3){
		printf("It's not triangle.\n\n");
	}
	else if (s3 = sqrt(pow(s1, 2) + pow(s2, 2))){
		printf("This is rectangular triangle\n\n");
	}
	else if ((pow(s1, 2) + pow(s2, 2) - pow(s3, 2))/(2*s1*s2)>0){
		printf("This is acute triangle\n\n");
	}
	else{
		printf("This is obtuse triangle\n\n");
	}
	return 0;

}
