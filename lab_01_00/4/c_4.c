#include <stdio.h>

#define BOTLE_COUNT(a) ((a - 20) / 25) 

int main(void)
{
    int a;
    printf("Enter how much coins do you have: ");
    scanf("%d", &a);
    printf("\n\nYou can buy %d botles\n", BOTLE_COUNT(a));
    return 0; 
}
