//Определить нормальный вес человека и индекс массы его тела по формулам: h * t / 240 и m / h 2, где h – рост человека (измеряемый в сантиметрах в первой формуле и в метрах –во второй); t – длина окружности грудной клетки (в сантиметрах); m – вес (вкилограммах).

#include <stdio.h>
#include <math.h>

int main(void)
{
    float h, m, t, f, g, h1;
    printf("Enter height(in centimeters ),weight and length chest: ");
    scanf("%f%f%f", &h, &m, &t);
	h1 = h / 100;
    f=(h * t) / 240;
    g= m / pow(h1, 2);
    printf("\n\nNormal weight: %f \n", f );
    printf("\n\nWeight index: %f \n", g);

    return 0; 
    
}
