#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;

    printf("Informe o valor do lado A: ");
    scanf("%d", &a);
    printf("Informe o valor do lado B: ");
    scanf("%d", &b);
    printf("Informe o valor do lado C: ");
    scanf("%d", &c);

    if((a == b) && (b == c))
    {
        printf("O Triangulo � Equilatero");
    }
    else if ((a != b) && (b != c) && (a != c))
    {
        printf("O Triangulo � Escaleno");
    }
    else
    {
        printf("O Triangulo � Isoceles");
    }


    return 0;
}
