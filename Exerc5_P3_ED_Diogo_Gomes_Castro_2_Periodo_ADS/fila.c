#include <stdio.h>
#include <stdlib.h>

#include "fila.h"


void create_fila(fila *f){
 f->inicio = NULL;
 f->fim = NULL;
}

int fila_vazia(fila *f){

 if(f->inicio ==NULL){
    return 1;
 }else{
    return 0;
 }
}

void inserir_fila(fila *f, int valor){

  //criar novo no
  no2 *novo=(no2*)malloc(sizeof(no2));
  novo->dado = valor;
  novo->prox = novo;
  novo->ant = novo;

  if(f->inicio == NULL){ //Primeira vez na fila
   f->inicio = novo;
   f->fim = novo;
   f->fim->prox = NULL;

  }else{

    f->fim->prox = novo;
    novo->ant = f->fim;
    f->fim = novo; //ajusta o ponteiro fim
    f->fim->prox = NULL;

  }

}


void mostra_fila(fila *f){

  no2 *aux=malloc(sizeof(no2));
  aux=f->inicio;

  if (fila_vazia(f)){
   printf("Fila vazia!!!");

  }else{

    do{
        printf("| %d",aux->dado);
        aux=aux->prox;
    }while(aux!=NULL);
  }

}





