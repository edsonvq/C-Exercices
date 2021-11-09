#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero =0;

    printf("Digite um numero de 0 a 10: ");
    scanf("%d", &numero);

    for(int i = 0; i <= 10; i++)
    {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
    return 0;
}
