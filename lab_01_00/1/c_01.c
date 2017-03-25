//Даны основания и высота равнобедренной трапеции. Найти периметр трапеции

#include <stdio.h>
#include <math.h>


#define SUM(a, b) (a + b)

int main(void)
{
    //Определяю тип переменных 
    float a, b, c, p;

    // Ввожу переменные 
    printf("Enter lenghts of the base and hight of the trapezoid: ");
    scanf("%f%f%f", &a, &b, &c);
    
    p = 2 * sqrt(pow(((a - b) / 2), 2) + pow(c, 2));

    //Вывожу результат
    printf("Perimeter of trapezoid is : %f \n", p + SUM(a, b));

    return 0; 
}


