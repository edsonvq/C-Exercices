#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quantidadeElementos = 0;

    printf("Digite o número de elementos da sequencia: ");
    scanf("%d", &quantidadeElementos);
    int numeroAtual = 1;
    printf("Sequencia gerada: \n");
    printf("%d ", numeroAtual);
    int numeroAnterior = 0;
    int temporario = 0;
    for(int i = 1; i < quantidadeElementos; i++)
    {
        temporario = numeroAtual;
        numeroAtual = numeroAtual + numeroAnterior;
        numeroAnterior = temporario;
        printf("%d ", numeroAtual);
    }
    return 0;
}
