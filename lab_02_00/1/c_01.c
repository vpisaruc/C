//Дано целое число a и натуральное (целое неотрицательное) число n. Вычислить a n. 

#include <stdio.h>
#include <math.h>




float main(void)
{
	//Объявление переменных
	float a,res;
	int n;
	a = 15.5;
	n = 2;
	//Возвожу в степень 
	res = pow(a,n);
	//Вывожу результат
    printf("А в степени n  : %f \n",res);
}
    