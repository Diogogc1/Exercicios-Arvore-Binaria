#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct no2{
    int dado;
    struct no2 *prox; //ponteiro do próximo
    struct no2 *ant;  //ponteiro do anterior
}no2;

typedef struct fila{
 no2 *inicio;
 no2 *fim;
}fila;

void create_fila(fila *f);
int  fila_vazia(fila *f);
void inserir_fila(fila *f, int valor);
void mostra_fila(fila *f);

#endif // FILA_H_INCLUDED
