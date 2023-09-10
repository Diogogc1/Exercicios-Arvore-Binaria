#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define espaco 5

//arvore binária de busca ABB
typedef struct no{
  int valor;
  struct no *esq;
  struct no *dir;
}no;


// raiz esq dir
void pre_ordem(no *raiz){

 if(raiz!=NULL){
    printf("%d \n",raiz->valor);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
 }
 return;
}

// esq raiz dir
void em_ordem(no *raiz){
 if(raiz!=NULL){

    em_ordem(raiz->esq);
    printf("%d \n",raiz->valor);
    em_ordem(raiz->dir);

 }
 return;

}

// esq dir raiz
void pos_ordem(no *raiz){
 if(raiz!=NULL){
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d \n",raiz->valor);
 }
 return;
}


void inserir_na_raiz(no *raiz,int valor){

    no *novo =malloc(sizeof(no));
    no *atual=malloc(sizeof(no));
    no *ant  =malloc(sizeof(no));

    novo->valor=valor;
    novo->dir =NULL;
    novo->esq =NULL;

    if(raiz == NULL)
        raiz=novo;
    else
    {
        atual=raiz;
        ant=NULL;
        while(atual!=NULL)
        {
            ant=atual;

            if(valor > atual->valor)
                atual=atual->dir;
            else
                atual=atual->esq;
        }

        if(valor > ant->valor)
            ant->dir = novo;
        else
            ant->esq = novo;
        return;
    }
}


void mostrar(no *mt)
{
    if(mt != NULL)
    {
        mostrar(mt->esq);
        printf("%i ", mt->valor);
        mostrar(mt->dir);
    }
    return;
}


///=====================================================================
void desenha_raiz_horiz(no *raiz, int profundidade, char *mapa, int dir)
{
    if (raiz== NULL)
        return;

    profundidade++;

    desenha_raiz_horiz(raiz->dir, profundidade, mapa, 1);

    mapa[profundidade-2] = 0;

    if(dir)
        mapa[profundidade-2] = 1;

    if(raiz->esq)
        mapa[profundidade-1] = 1;

    printf("\n");

    for(int i=0; i<profundidade-1; i++)
    {
        if(i == profundidade-2)
            printf("+");
        else if(mapa[i])
            printf("|");
        else
            printf(" ");

        for(int j=1; j<espaco; j++)
            if(i < profundidade-2)
                printf(" ");
            else
                printf("-");
    }

    printf("%d\n", raiz->valor);

    for(int i=0; i<profundidade; i++)
    {
        if(mapa[i])
            printf("|");
        else
            printf(" ");
        for(int j=1; j<espaco; j++)
            printf(" ");
    }
    desenha_raiz_horiz(raiz->esq, profundidade, mapa, 0);
}

void desenhar(no *raiz)
{
    char mapa[255] = {};
    desenha_raiz_horiz(raiz, 0, mapa, 0);
}
///==================================================================


void exibir_no(no* no_atual) {
    // Aqui você pode personalizar a exibição do nó
    printf("Visitando no:%d\n", no_atual->valor);
}


int contagem_de_nos (no *raiz)
{
    if (raiz==NULL)
        return 0;

    exibir_no(raiz); // Exibir o nó visitado
    int nos_da_dir = contagem_de_nos(raiz->dir);
    int nos_da_esq = contagem_de_nos(raiz->esq);
    int total_de_nos = nos_da_dir + nos_da_esq + 1;

    //printf("\n\n");
    //exibir_no(raiz); // Exibir o nó visitado
    //printf("nos_da_direita  %d \n" ,nos_da_dir);
    //printf("nos_da_esquerda %d \n",nos_da_esq);

    return(total_de_nos);
}




int qnt_no_folhas(no *raiz){

 int qntd=0;


 if(raiz->esq!=NULL)
    qntd += qnt_no_folhas(raiz->esq);


 if(raiz->dir!=NULL)
    qntd += qnt_no_folhas(raiz->dir);

 if(raiz->esq ==NULL && raiz->dir == NULL)
   return 1;

  return qntd;
}



no* inserir(no *raiz,int valor){

 if(raiz == NULL){
   no *novo= malloc(sizeof(no));
   novo->valor = valor;
   novo->esq =NULL;
   novo->dir = NULL;
   raiz = novo;


 }else{

    if(valor == raiz->valor){ //se o valor já foi inserido
       printf("valor já inserido!!");

    }else if(valor > raiz->valor){//valores maiores sempre a dir
       raiz->dir =inserir(raiz->dir,valor);

    }else if(valor < raiz->valor){//valores menores sempre a esquer
       raiz->esq = inserir(raiz->esq,valor);

    }
 }

 return raiz;

}




///==================================================================



no* excluir(no *raiz, int num){

 if(raiz == NULL){ //raiz vazia
   return NULL;

 }else if (raiz->valor > num){
   raiz->esq = excluir(raiz->esq,num); //busca subarvore esq



 }else if(raiz->valor < num){
   raiz->dir = excluir(raiz->dir,num);



 }else{ //achou o valor ---- valor == raiz

       //elementos sem filhos - no folha
       if(raiz->esq == NULL && raiz->dir == NULL){
        free(raiz);
        raiz = NULL;
       }else if (raiz->esq == NULL){ //só tem filho a dir
         no* aux = raiz;
         raiz = raiz->dir;
         aux->dir =NULL;
         free(aux);
       }else if (raiz->dir==NULL){ //só tem filho a esq
         no* aux = raiz;
         raiz = raiz->esq;
         aux->esq =NULL;
         free(aux);

       }else{ //possui os dois filhos

         no* aux = raiz->esq; //aponta aux para subarvore esq

        while(aux->dir !=NULL){ //busca o maior valor na dir
           aux=aux->dir;
        }
         raiz->valor = aux->valor; //troca as informações
         aux->valor = num;
         raiz->esq = excluir(raiz->esq,num);


       }
 }
 return raiz;
}

//===========================================================
int buscar_menor(no *raiz, int x, int *quant)
{

    if(raiz != NULL)
    {
        if(raiz->valor < x)
        {
            (*quant)++;
        }

        buscar_menor(raiz->esq, x, quant);
        buscar_menor(raiz->dir, x, quant);
    }
    return quant;
}

//===========================================================

void menu(){
 no *raiz=malloc(sizeof(no));
 raiz=NULL;


 int op;  //opção recursiva


 do{
     system("cls");
     printf("\n ============== PROVA 3 - EXCERCICIO 3 ============== \n\n");
     desenhar(raiz);
     printf("\n\n MENU");
     printf("\n\n");
     printf("1 - Inserir Arvore \n");
     printf("2 - Quantidade de nos menores que um valor\n");
     printf("3 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

     case 1:{

       int x;
       printf("\n Informe o valor: >_");
       scanf("%d",&x);

       raiz = inserir(raiz,x);


       break;

     }

     case 2:{

       int x, quant=0;
       printf("\n Informe o valor: >_");
       fflush(stdin);
       scanf("%d",&x);
       buscar_menor(raiz, x, &quant);

       printf("\n\n Quantidade de elementos menores que %d: %d", x, quant);
       printf("\n\n\n Pressione qualquer tecla para voltar ao menu \n\n");
       getch();
       break;

     }

     case 3:
        op=3;
        exit(1);
     }

  }while(op != 8);
}



int main()
{


    menu();

    printf("\n\n");
    return 0;
}
