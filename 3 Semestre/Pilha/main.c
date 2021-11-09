/* 
 * File:   main2.c
 * Author: Edson
 *
 * Created on 29 de Abril de 2019, 21:28
 */

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 1000

typedef struct {
    int chave;
} TipoDado;

typedef struct _RegPilha{
 int topo;
 TipoDado array[TAM_MAX];
} RegPilha;
typedef RegPilha* Pilha;

void LiberaPilha(Pilha p){
 free(p);
}

Pilha CriaPilha(){
 Pilha p;
 p = (Pilha)calloc(1, sizeof(RegPilha));
 if(p==NULL) exit(-1);
 p->topo = 0;
 return p;
}

int PilhaVazia(Pilha p){
 return (p->topo==0);
}

void In2Pos(char expr[]){
  Pilha p;
  int i = 0;
  char c,t;
 
  p = CriaPilha();
  Empilha(p, '(');
 
  do{
    c = expr[i];
    i++;
    if(c >= 'a' && c <= 'z'){
      printf("%c", c);
    }
    else if(c == '('){
      Empilha(p, '(');
    }
    else if(c == ')' || c == '\0'){
      do{
        t = Desempilha(p);
        if(t != '(')
          printf("%c", t);
      }while(t != '(');
    }
    else if(c == '+' || c == '-' || 
            c == '*' || c == '/' ||
            c == '^' ){
      while(1){
        t = Desempilha(p);
        if(Prioridade(c,t)){
          Empilha(p, t);
          Empilha(p, c);
          break;
        }
        else{
          printf("%c", t);
        }
      }
    }
  }while(c != '\0');
  printf("\n");
  LiberaPilha(p);
}
void Empilha(Pilha p, TipoDado x){
 if(p->topo==TAM_MAX) exit(-1);
 p->array[p->topo] = x;
 p->topo++;
}

int Prioridade(char c, char t){
  int pc,pt;
 
  if(c == '^')
    pc = 4;
  else if(c == '*' || c == '/')
    pc = 2;
  else if(c == '+' || c == '-')
    pc = 1;
  else if(c == '(')
    pc = 4;
 
  if(t == '^')
    pt = 3;
  else if(t == '*' || t == '/')
    pt = 2;
  else if(t == '+' || t == '-')
    pt = 1;
  else if(t == '(')
    pt = 0;
 
  return (pc > pt);
}

TipoDado Desempilha(Pilha p){
 if(p->topo==0) exit(-1);
 p->topo--;
 return (p->array[p->topo]);
}

int main(int argc, char** argv) {
  char expr[] = "a*b+c*d^e/f-g*h";
  
  In2Pos(expr);
    return (EXIT_SUCCESS);
}

