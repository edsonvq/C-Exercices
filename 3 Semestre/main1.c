#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cell {
    int codigo;
    char nome[10];
    struct cell *next;
    struct cell *back;
}no;

struct cell *topo = NULL, *aux = NULL, *anterior = NULL, *posterior = NULL;
int op = 0, c = 0;

int push() {
    if (topo == NULL) {
        topo = (no*) malloc(sizeof (no));
        topo->next = NULL;
        topo->back = NULL;
        aux = topo;
        c++;
    } else {
        if (c >= 10) {
            printf("Stack overflow...");
            system("pause");
        } else {
            topo = (no*) malloc(sizeof (no));
            aux->next = topo;
            topo->back = aux;
            aux = topo;
            topo->next = NULL;
            c++;
        }
    }
}

//int top() {
//    if (top == null) {
//        printf("Stack overflow");
//        system("pause"");
//    } else {
//        printf("%d", topo->codigo);
//        printf("%s", topo->nome);
//    }
//}

int pop() {
    if (topo == NULL) {
        printf("Stack overflow...");
        system("pause");
    }
    else if(topo->next == NULL && topo->back == NULL) {
        printf("Removendo o ultimo registro da lista...");
        system("pause");
        topo = NULL;
        c = 0;
        free(topo);
    } else {
        topo = topo->back;
        printf("Removendo um elemento na pilha...");
        system("pause");
        free(aux);
        topo->next = NULL;
        c--;
    }
}

int main() {

}

