#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

typedef enum {FALSE, TRUE} BOOL;

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO a[MAX];
    int topo;
} PILHA;

int main()
{
    char expr[60];

    fgets(expr, 60, stdin);
    inpos(expr);

    return 0;
}


REGISTRO criarReg(TIPOCHAVE chave) {
    REGISTRO reg;
    reg.chave = chave;
    return reg;
}

void inicializar(PILHA *pilha) {
    pilha->topo = 0;
}

int vazia(PILHA *pilha) {
    return pilha->topo == 0;
}

int cheia(PILHA *pilha) {
    return pilha->topo == MAX;
}

void exibir(PILHA *pilha) {
    int i = 0;
    printf("Pilha: [");
    for (i=0; i<pilha->topo; i++) {
        printf("%d", pilha->a[i].chave);
        if (i < pilha->topo-1)
            printf(", ");
    }
    printf("] <-- topo\n");
}

int empilha(REGISTRO elem, PILHA *pilha) {
    if (cheia(pilha)) {
        return FALSE;
    }
    pilha->a[pilha->topo] = elem;
    pilha->topo++;
    printf("empilha %c\n", elem.chave);
    return TRUE;
}

int desempilha(PILHA *pilha, REGISTRO *elem) {
    if (vazia(pilha))
        return FALSE;
    *elem = pilha->a[pilha->topo-1];
    pilha->topo--;
    printf("desempilha %c\n", elem->chave);
    return TRUE;
}

void esvaziar(PILHA *pilha) {
    pilha->topo = 0;
}

int topo(PILHA *pilha, REGISTRO *elem) {
    if (vazia(pilha))
        return FALSE;
    *elem = pilha->a[pilha->topo-1];
        return TRUE;
}


//função para checar se o caractere da string é um operando
int operando(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

//função que determina a prioridade de cada operador
//valor retornado maior é igual a operador de prioridade maior
int prioridade(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return 0;
}

//função que converte de infixa para posfixa
int inpos(char expr[])
{

    PILHA pilha;
    inicializar(&pilha);

    int i, aux;
    REGISTRO elem;

    for (i = 0, aux = -1; expr[i]; ++i)
    {
        if (operando(expr[i]))
            expr[++aux] = expr[i];

        else if (expr[i] == '(')
            empilha(criarReg(expr[i]), &pilha);

        else if (expr[i] == ')')
        {
            while (!vazia(&pilha) && topo(&pilha, &elem) != '(')
            {
                desempilha(&pilha, &elem);
                expr[++aux] = elem.chave;
            }

                if (!vazia(&pilha) && topo(&pilha, &elem) != '(')
                    return 0;
                else
                    desempilha(&pilha, &elem);

        }

        else
        {
            while (!vazia(&pilha) && prioridade(expr[i]) <= prioridade(topo(&pilha, &elem)))
            {
                desempilha(&pilha, &elem);
                expr[++aux] = elem.chave;
            }
            empilha(criarReg(expr[i]), &pilha);
        }
    }
    //desempilha todos os elementos da pilha
    while (!vazia(&pilha))
    {
        desempilha(&pilha, &elem);
        expr[++aux] = elem.chave;
    }
    expr[++aux] = '\0';
    printf("%s", expr);
}


