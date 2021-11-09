#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numerosDigitados[10];

    for(int i = 0; i <= 9; i++)
    {
       printf("Digite um Numero: ");
       scanf("%d", &numerosDigitados[i]);
    }

    printf("Os numeros digitados foram \n");
    for(int i = 0; i <= 9; i++)
    {
        printf("%d\n", numerosDigitados[i]);
    }
    return 0;
}
