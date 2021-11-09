#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;

    printf("Digite um Numero: ");
    scanf("%d", &numero);
    printf("%d E maior que 10? %d\n", numero, numero > 10);
    printf("%d E menor que 10? %d\n", numero, numero < 10);
    printf("%d E igual a 10? %d\n", numero, numero == 10);
    printf("%d E maior ou igual a 10? %d\n", numero, numero >= 10);
    printf("%d E Diferente de 10? %d", numero, numero != 10);
    return 0;
}
