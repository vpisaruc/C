#include <stdio.h>

int main(void)
{
    int a, p;
    printf("Enter how much coins do you have: ");
    scanf("%d", &a);
    p = (a - 20) / 25;
    printf("You can buy %d botles\n", p);
    return 0; 
}
