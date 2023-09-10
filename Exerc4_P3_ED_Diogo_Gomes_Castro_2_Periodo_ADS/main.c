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
///==================================================================

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
///==================================================================

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

///===========================================================
///===========================================================

int igual(no *a, no *b, int *flag)
{
    if((a != NULL && b == NULL) || (b != NULL && a == NULL))
    {
        *flag = 0;
    }
    else
        if(a->valor == b->valor)
        {
            if(a->esq != NULL || b->esq != NULL)
            {
                igual(a->esq, b->esq, flag);
            }
            else
            {
                if(a->dir != NULL || b->dir != NULL)
                {
                    igual(a->dir, b->dir, flag);
                }
                else
                {
                    printf("\n\n As Arvores sao iguais!");
                    *flag = 1;
                }
            }
        }
    return 0;
}

void menu(){
 no *raiz1=malloc(sizeof(no));
 raiz1=NULL;

 no *raiz2=malloc(sizeof(no));
 raiz2=NULL;


 int op;  //opção recursiva


 do{
     system("cls");
     printf("\n======== ARVORE A ======== \n");
     desenhar(raiz1);
     printf("\n\n======== ARVORE B ======== \n");
     desenhar(raiz2);
     printf("\n\n========== MENU ========== \n\n");
     printf("1 - Inserir na Arvore A \n");
     printf("2 - Inserir na Arvore B \n");
     printf("3 - Comparar Arvores \n");
     printf("4 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

     case 1:{

       int x;
       printf("\n Informe o valor: >_");
       scanf("%d",&x);

       raiz1 = inserir(raiz1,x);


       break;

     }

     case 2:{

       int x;
       printf("\n Informe o valor: >_");
       scanf("%d",&x);

       raiz2 = inserir(raiz2,x);
       break;

     }

    case 3:
    {
        int flag=0;

        if(raiz1 == NULL && raiz2 == NULL) //ARVORES VAZIAS
        {
            printf("\n\n As Arvores sao iguais!");
            flag = 1;
        }
        else
            igual(raiz1, raiz2, &flag);

        if(flag == 0)
        {
            printf("\n\n As Arvores NAO sao iguais!");
        }

        printf("\n\n\n Pressione qualquer tecla para voltar ao menu \n\n");
        getch();
        break;
    }

     case 4:
        op=4;
        exit(1);
     }

  }while(op != 4);
}



int main()
{
    menu();

    printf("\n\n");
    return 0;
}
