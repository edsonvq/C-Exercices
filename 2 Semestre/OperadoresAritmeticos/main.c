#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;

    printf("Digite o valor do Primeiro numero: ");
    scanf("%d", &numero1);
    printf("Digite o valor do Segundo numero: ");
    scanf("%d", &numero2);
    printf("%d + %d = %d\n", numero1, numero2, numero1 + numero2);
    printf("%d - %d = %d\n", numero1, numero2, numero1 - numero2);
    printf("%d x %d = %d\n", numero1, numero2, numero1 * numero2);
    printf("%d / %d = %d\n", numero1, numero2, numero1 / numero2);
    printf("O resto da Divisao de %d dividido por  %d = %d\n ", numero1, numero2, numero1 % numero2);
    return 0;
}
