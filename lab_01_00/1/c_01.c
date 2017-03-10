//Даны основания и высота равнобедренной трапеции. Найти периметр трапеции

#include <stdio.h>
#include <math.h>

//Вычисляю периметр трапеции
#define PER(a,b,c) (a + b + 2*sqrt(pow(((a-b)/2),2)+pow(c,2)))

int main(void)
{
    //Определяю тип переменных 
    float a,b,c;
    // Ввожу переменные 
    printf("Enter lenghts of the base and hight of the trapezoid: ");
    scanf("%f%f%f",&a,&b,&c);
    //Вывожу результат
    printf("Perimeter of trapezoid is : %f \n",PER(a,b,c));

    return 0; 
}
