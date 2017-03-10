#include <stdio.h>
#include <math.h>

int main(void)
{
    int a;
    printf("Enter how much coins do you have: ");
    scanf("%d",&a);
    int p;
    p = ((a - 20) / 25);
    printf("You can buy %d botles\n",p);
    return 0; 
}
