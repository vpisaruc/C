#include <stdio.h>
#include <math.h>


#define ERROR_CODE -1
#define WRONG_INPUT_1 -2
#define WRONG_INPUT_2 -3
#define WRONG_INPUT_3 -4
#define RECTAGULAR 1
#define ACUTE 2
#define OBTUSE 3
#define TRIANGLE_ERROR -5
#define OK 0

float triangle(float x_a, float x_b, float x_c, float y_a, float y_b, float y_c)
{
    float s1, s2, s3, s1_2, s2_2, s3_2;
    int n;
    //Находим квадраты сторон	
    s1_2 = pow((x_a - x_b), 2) + pow((y_a - y_b), 2);
	s2_2 = pow((x_b - x_c), 2) + pow((y_b - y_c), 2);
	s3_2 = pow((x_c - x_a), 2) + pow((y_c - y_a), 2);
	
	

    //Проверка на существование треугольника	
    if (((s1_2 + s2_2) > s3_2) || ((s1_2 + s3_2) > s2_2) || ((s2_2 + s3_2) > s1_2))
    {
        //Проверка является ли треугольник прямоугольным
        if ((s3_2 == s1_2 + s2_2) || (s2_2 == s1_2 + s3_2) || (s1_2 == s3_2 + s2_2))
        {
            return RECTAGULAR;
        }
        //Проверка является ли треугольник остроугольным
        else if ((s1_2 + s2_2) > s3_2) || ((s1_2 + s3_2) > s2_2) || ((s3_2 + s2_2) > s1_2))
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
		return TRIANGLE_ERROR;
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
				if (n == TRIANGLE_ERROR)
                {
                    printf("This is not triangle \n");
                }
                if (n == RECTAGULAR)
                {
                    printf("This is rectagular triangle \n");
                }
                if (n == ACUTE)
                {
                    printf("This is acute triangle \n");
                }
                if (n == OBTUSE)
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