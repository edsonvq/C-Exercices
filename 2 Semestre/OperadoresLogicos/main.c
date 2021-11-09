#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2;
    printf("Digite o primeiro numero: ");
    scanf("%d", &numero1);
    printf("Digite o segundo numero: ");
    scanf("%d", &numero2);
    printf("%d > 10 && %d > 20? %d\n", numero1, numero2, numero1 > 10 && numero2 > 20);
    printf("%d > 50 OU %d > 60? %d\n", numero1, numero2, numero1 > 50 || numero2 > 60);
    printf("%d != 20? && %d != 30 %d\n", numero1, numero2, numero1 != 20 && numero2 != 30);
    printf("%d > 10 && %d > 20? %d\n", numero1, numero2, !(numero1 > 10 && numero2 > 20));
    return 0;
}
