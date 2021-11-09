/**
* @author Edson Queiroz
* lista simplesmente encadeada
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct cell {
    int codigo;
    char nome[10];
    struct cell *proximo;
}no;

no *inicial = NULL, *novo = NULL, *aux = NULL, *anterior = NULL, *posterior = NULL;
int op = 0, achou = 0, input;




int main() {
    setlocale(LC_ALL,"");

    void insert();
    void list();
    void search();
    void update();
    void remove_();

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
            case 4:
                update();
                break;
            case 5:
                remove_();
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

    printf("Informe o codigo:");
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
        printf("\nCodigo : %d", inicial->codigo);
        printf("\nNome : %s", inicial->nome);
        printf("\nEndereco atual: %p", inicial);
        printf("\nProximo endereco: %p", inicial->proximo);
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
        printf("\nCodigo : %d", aux->codigo);
        printf("\nNome : %s", aux->nome);
        printf("\nEndereco atual: %p", aux);
        printf("\nProximo endereco: %p", aux->proximo);
        printf("\n#");

    }
}

void list() {
    if (inicial == NULL) {
        printf("\nA lista está vazia");
    } else {
        aux = inicial;
        printf("\n[--------- Lista Encadeada ---------]");
        while (aux != NULL) {
            printf("\n#");
            printf("\nCodigo : %d", aux->codigo);
            printf("\nNome : %s", aux->nome);
            printf("\nEndereco atual: %p", aux);
            printf("\nProximo endereco: %p", aux->proximo);
            printf("\n#");
            aux = aux->proximo;
        }
        printf("\n[--------- --------------- ---------]");
    }
getchar();

}

void search(){
    if (inicial == NULL) {
        printf("\nA lista está vazia");
    }else{
        achou = 0;
        aux = inicial;
        printf("\nDigite o codigo a ser localizado: ");
        scanf("%d", &input);

        while((aux != NULL) && (achou == 0)){
            if(aux->codigo == input){
                achou = 1;
            }else{
                aux = aux->proximo;
            }
        }
    }
    if(achou == 1){
        system("clear");
        printf("\n-------=Codigo localizado=---------");
        printf("\n#");
        printf("\nCodigo : %d", aux->codigo);
        printf("\nNome : %s", aux->nome);
        printf("\nEndereco atual: %p", aux);
        printf("\nProximo endereco: %p", aux->proximo);
        printf("\n#");
    }else{
        printf("\nCodigo nao localizado :(");
    }
    getchar();
}

void update(){
    if (inicial == NULL) {
        printf("\nA lista está vazia");
    }else{
        achou = 0;
        aux = inicial;
        printf("\nDigite o codigo a ser atualizado: ");
        scanf("%d", &input);

        while((aux != NULL) && (achou == 0)){
            if(aux->codigo == input){
                achou = 1;

                printf("Informe um novo codigo:");
                scanf("%d", &aux->codigo);
                fflush(stdin);

                printf("Informe um novo nome:");
                scanf("%s", &aux->nome);
                fflush(stdin);

            }else{
                aux = aux->proximo;
            }
        }
    }
    if(achou == 1){
        system("clear");
        printf("\n-------=Elemento atualizado=---------");
    }else{
        printf("\nCodigo nao localizado :(");
    }
    getchar();
}

void remove_(){

    if (inicial == NULL) {
        printf("\nA lista está vazia");
    }else{
      achou = 0;
      aux = inicial;
      posterior = inicial;

      printf("\nDigite o codigo a ser deletado: ");
      scanf("%d", &input);
      fflush(stdin);

      while ((aux !=NULL)  && (achou == 0))
      {
         if (aux->codigo == input) // achou !!
         {
            if (aux == inicial) // se esta removendo o primeiro da lista
            {
               inicial = inicial->proximo;

               free(aux);

               achou = 1; // removeu !!
            }
            else  // esta removendo do meio da lista
            {
              posterior->proximo = aux->proximo;  // Refaz o encadeamento
              free(aux);                // Libera a area do nodo
              achou =  1;   // removeu !!
            }
         }
         else  // continua procurando no prox. nodo
         {
            posterior = aux;
            aux = aux->proximo;
         }
      }
    }
    if(achou == 1){
        system("clear");
        printf("\n-------=Elemento Removido=---------");
    }else{
        printf("\nCodigo nao localizado :(");
    }
    getchar();
}
