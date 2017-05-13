#include <stdio.h>
#include <math.h>


#define ERROR_CODE -1
#define WRONG_INPUT_1 -2
#define WRONG_INPUT_2 -3
#define WRONG_INPUT_3 -4
#define RECTAGULAR 1
#define ACUTE 2
#define OBTUSE 3
#define OK 0

float triangle(float x_a, float x_b, float x_c, float y_a, float y_b, float y_c)
{
    float s1, s2, s3, s1_2, s2_2, s3_2;
    int n;
    //Находим квадраты сторон	
	s1_2 = pow((x_a - x_b), 2) + pow((y_a - y_b), 2);
	s2_2 = pow((x_b - x_c), 2) + pow((y_b - y_c), 2);
	s3_2 = pow((x_c - x_a), 2) + pow((y_c - y_a), 2);

    //Находим стороны
    s1 = sqrt(s1_2);
    s2 = sqrt(s2_2);
    s3 = sqrt(s3_2);

    //Проверка на существование треугольника	
    if (((s1_2 + s2_2) > s3_2) || ((s1_2 + s3_2) > s2_2) || ((s2_2 + s3_2) > s1_2))
    
    {
        //Проверка является ли треугольник прямоугольным
        if ((s3_2 == s1_2 + s2_2) || (s2_2 == s1_2 + s3_2) || (s1_2 == s3_2 + s2_2))
        {
            return RECTAGULAR;
        }
        //Проверка является ли треугольник остроугольным
        else if (((s1_2 + s2_2 - s3_2)/(2*s1*s2) > 0) && ((s3_2 + s2_2 - s1_2)/(2*s3*s2)>0) && ((s1_2 + s3_2 - s2_2)/(2*s1*s3)>0))
        {
            return ACUTE;
        }
        //Проверка является ли треугольник тупоугольным
        else
        {
            return OBTUSE;
        }
    }
    else
    {
	    printf("This is not triangle \n\n");
		return ERROR_CODE;
    }
    return OK;
}

int main(void)
{
    float x_a, x_b, x_c, y_a, y_b, y_c;
    int n;
    //Ввод координат вершин
    printf("Pervuiu vershinu treugolinika: \n");
    if(scanf("%f %f", &x_a, &y_a) == 2)
	{	
		printf("Vtoruiu vershinu treugolinika: \n");
        if (scanf("%f %f", &x_b, &y_b) == 2)
		{
			printf("Tretiu vershinu treugolinika: \n");
            if(scanf("%f %f", &x_c, &y_c) == 2)
			{
				n = triangle(x_a, x_b, x_c, y_a, y_b, y_c);
                if (n == 1)
                {
                    printf("This is rectagular triangle \n");
                }
                if (n == 2)
                {
                    printf("This is acute triangle \n");
                }
                if (n == 3)
                {
                    printf("This is obtuse triangle \n");
                }
			}
			else
			{
				printf("I/O error\n");
				return WRONG_INPUT_1;
			}
		}
		else
		{
			printf("I/O error\n");
			return WRONG_INPUT_2;
		}
	}

    else
	{
			printf("I/O error\n");
			return WRONG_INPUT_3;
	}


}