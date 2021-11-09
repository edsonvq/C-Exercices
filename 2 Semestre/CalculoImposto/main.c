#include <stdio.h>
#include <stdlib.h>

int main()
{
    float areaTotal, areaConstruida = 0;

    printf("Informe a area do Terreno: ");
    scanf("%f", &areaTotal);
    printf("Informe a area Construida: ");
    scanf("%f", &areaConstruida);

    float areaNaoConstruida = areaTotal - areaConstruida;
    float impostoAreaConstruida = 5 * areaConstruida;
    float impostoAreaNaoConstruida = 3.8 * areaNaoConstruida;
    float impostoTotal = impostoAreaConstruida + impostoAreaNaoConstruida;

    printf("Total do Imposto: %f", impostoTotal);

    return 0;
}
