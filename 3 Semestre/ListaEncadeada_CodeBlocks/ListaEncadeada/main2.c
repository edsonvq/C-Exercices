#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct cell {
    int codigo;
    char nome[10];
    struct cell *proximo;
}no;

struct cell *inicial = NULL, *novo = NULL, *aux = NULL, *anterior = NULL, *posterior = NULL;
int op = 0, achou = 0, input;




int main() {
    setlocale(LC_ALL,"");
    void insert();
    void list();
    void search();

    for (;;) {

        system("clear");
        printf("\n1 - Inserir : ");
        printf("\n2 - Listar: ");
        printf("\n3 - Localizar");

        printf("\n4 - Alterar");
        printf("\n5 - Remover");

        printf("\n0 - Sair\n");


        scanf("%d", &op);
        fflush(stdin);
        system("clear");


        switch (op) {
            case 1:
                insert();
                break;
            case 2:
                list();
                break;
            case 3:
                search();
                break;
            case 0:
                exit(0);
                break;
        }
	getchar();

    }
    return 0;
}

void insert() {

    printf("Informe o c�digo:");
    scanf("%d", &input);

    //primeiro elemento da lista
    if (inicial == NULL) {
        inicial = (no*) malloc(sizeof(no));
        inicial->codigo = input;

        printf("Informe um nome:");
        scanf("%s", &inicial->nome);
        fflush(stdin);

        inicial->proximo = NULL;
        printf("\n#");
        printf("\nC�digo : %d", inicial->codigo);
        printf("\nNome : %s", inicial->nome);
        printf("\nEndere�o atual: %p", inicial);
        printf("\nProximo endere�o: %p", inicial->proximo);
        printf("\n#");

    } else {
        //Inserir no inicio
        aux = (no*) malloc(sizeof (no));
        aux->codigo = input;

        printf("Informe um nome:");
        scanf("%s", &aux->nome);
        fflush(stdin);

        aux->proximo = inicial; //seta o proximo do aux para o inicial
        inicial = aux; //seta o inicial como o novo(aux)
        printf("\n#");
        printf("\nC�digo : %d", aux->codigo);
        printf("\nNome : %s", aux->nome);
        printf("\nEndere�o atual: %p", aux);
        printf("\nProximo endere�o: %p", aux->proximo);
        printf("\n#");

    }
}

void list() {
    if (inicial == NULL) {
        printf("\nA lista est� vazia");
    } else {
        aux = inicial;
        printf("\n[--------- Lista Encadeada ---------]");
        while (aux != NULL) {
            printf("\n#");
            printf("\nC�digo : %d", aux->codigo);
            printf("\nNome : %s", aux->nome);
            printf("\nEndere�o atual: %p", aux);
            printf("\nProximo endere�o: %p", aux->proximo);
            printf("\n#");
            aux = aux->proximo;
        }
        printf("\n[--------- --------------- ---------]");
    }
getchar();

}

void search(){
    if (inicial == NULL) {
        printf("\nA lista est� vazia");
    }else{
        achou = 0;
        aux = inicial;
        printf("\nDigite o c�digo a ser localizado: ");
        scanf("%d", &input);

        while((aux != NULL) && (achou == 0)){
            if(aux->codigo == input){
                achou = 1;
                posterior = aux;
            }else{
                aux = aux->proximo;
            }
        }
    }
    if(achou == 1){
        system("clear");
        printf("\n-------=C�digo localizado=---------");
        printf("\n#");
        printf("\nC�digo : %d", aux->codigo);
        printf("\nNome : %s", aux->nome);
        printf("\nEndere�o atual: %p", aux);
        printf("\nProximo endere�o: %p", aux->proximo);
        printf("\n#");
    }else{
        printf("\nC�digo n�o localizado :(");
    }
    exit(0);
}
