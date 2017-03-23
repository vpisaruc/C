#include <stdio.h>
#include <math.h>

float main(void)
{
    float x_a, x_b, x_c, y_a, y_b, y_c, s1, s2, s3, s1_2, s2_2, s3_2;
    //Ввод координат вершин
    printf("Pervuiu vershinu treugolinika: ");
    scanf("%f%f", &x_a, &y_a);
    printf("Vtoruiu vershinu treugolinika: ");
    scanf("%f%f", &x_b, &y_b);
    printf("Tretiu vershinu treugolinika: ");
    scanf("%f%f", &x_c, &y_c);

    //Находим квадраты сторон	
    s1_2 = pow((x_a - x_b), 2) + pow((y_a - y_b), 2);
    s2_2 = pow((x_b - x_c), 2) + pow((y_b - y_c), 2);
    s3_2 = pow((x_c - x_a), 2) + pow((y_c - y_a), 2);
    s1 = sqrt(s1_2);
    s2 = sqrt(s2_2);
    s3 = sqrt(s3_2);
    printf("s1 = %f\ns2 = %f\ns3 = %f\n", s1_2 ,s2_2 ,s3_2);

	
    //Проверка на существование треугольника	
    if (((s1 + s2) <= s3) || ((s1 + s3) <= s2) || ((s2 + s3) <= s1))
    {

	printf("\n\nIt's not triangle.\n\n");
    }
    //Проверка является ли треугольник прямоугольным
    else if ((s3_2 == s1_2 + s2_2) || (s2_2 == s1_2 + s3_2) || (s1_2 == s3_2 + s2_2))
    {
	printf("This is rectangular triangle\n\n");
    }
    //Проверка является ли треугольник остроугольным
    else if (((s1_2 + s2_2 - s3_2)/(2*s1*s2) > 0) && ((s3_2 + s2_2 - s1_2)/(2*s3*s2)>0) && ((s1_2 + s3_2 - s2_2)/(2*s1*s3)>0))
    {
        printf("This is acute triangle\n\n");
    }
    //Проверка является ли треугольник тупоугольным
    else{
	printf("This is obtuse triangle\n\n");
    }
    return 0;

}
