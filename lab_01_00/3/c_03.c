//Определить нормальный вес человека и индекс массы его тела по формулам: h * t / 240 и m / h 2, где h – рост человека (измеряемый в сантиметрах в первой формуле и в метрах –во второй); t – длина окружности грудной клетки (в сантиметрах); m – вес (вкилограммах).

#include <stdio.h>

int main(void)
{
    float h, m, t, f, g;
    printf("Enter height,weight and length chest: ");
    scanf("%f%f%f", &h, &m, &t);
    f=(h * t) / 240;
    g=m / (h * h);
    printf("Normal weight: %f \n", f );
    printf("Weight index: %f \n", g);

    return 0; 
    
}
