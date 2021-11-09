#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256


typedef enum {FALSE, TRUE} BOOL;

typedef struct {
    char a[MAX];
    int topo;
} PILHA;

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
        printf("%d", pilha->a[i]);
        if (i < pilha->topo-1)
            printf(", ");
    }
    printf("] <-- topo\n");
}

int empilhaa(char elem, PILHA *pilha) {
    if (cheia(pilha)) {
        return FALSE;
    }
    pilha->a[pilha->topo] = elem;
    pilha->topo++;
    printf("Empilha: %c\n", elem);
    return TRUE;
}

int desempilhaa(PILHA *pilha, char *elem) {
    if (vazia(pilha))
        return FALSE;
    
    *elem = pilha->a[pilha->topo-1];
    pilha->topo--;
    
    printf("Desempilha: %c\n", elem);
    return TRUE;
}

void esvaziar(PILHA *pilha) {
    pilha->topo = 0;
}

int topo(PILHA *pilha, char *elem) {
    if (vazia(pilha))
        return FALSE;
    
    *elem = pilha->a[pilha->topo-1];
    return TRUE;
}


//função para checar se o caractere da string é um operando
int operando(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

//função que determina a prioridade de cada operador
//valor retornado maior é igual a operador de prioridade maior
int prioridadea(char ch)
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
int inpos(char expr[], PILHA *pilha)
{
    pilha->topo = 0;

    int i, aux;
    char *elem;

    for (i = 0, aux = -1; expr[i]; ++i)
    {

        if (operando(expr[i])){
            expr[++aux] = expr[i];
            printf("----> Var %c\n", expr[i]);
        }
        else if (expr[i] == '('){
            //empilha(expr[i], &pilha);
            printf("----> Abriu (\n");
        }
        else if (expr[i] == ')'){
            while (!vazia(&pilha) && topo(&pilha, &elem) != '('){
                desempilha(&pilha, &elem);
                expr[++aux] = elem;
            }

            if (!vazia(&pilha) && topo(&pilha, &elem) != '('){
                return 0;}
            else{
                desempilha(&pilha, &elem);
            }
            
            printf("----> Fechou )\n");
        }
        else{
            
            while (!vazia(&pilha) && prioridade(expr[i]) <= prioridade(topo(&pilha, &elem)))
            {
                desempilha(&pilha, &elem);
                expr[++aux] = elem;
            }
            empilha(expr[i], &pilha);
            
            printf("----> Sem parenteses\n");
        }

        //printf("----> %c\n", expr[i]);
    }
    //desempilha todos os elementos da pilha
    while (!vazia(&pilha))
    {
        desempilha(&pilha, &elem);
        expr[++aux] = elem;
    }
    expr[++aux] = '\0';
    printf("%s", expr);
}

int mainA()
{
    PILHA *pilha;
    char expr[60];
    
    fgets(expr, 60, stdin);
    inpos(expr, &pilha);
    return 0;
}