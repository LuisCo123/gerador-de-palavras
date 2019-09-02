#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
        int num;
        struct lista *prox;

}lista;

lista* li;
lista* li0;


lista* inicia_lista();
void soma_lista(lista* li, lista* li0);
int insere(lista* li);

int main()
{
    int op = 0;

    li = inicia_lista();
    li0= inicia_lista();
    printf("digite [1] pra colocar na primeira lista\n");
    printf("digite [2] pra colocar na segunda lista\n");
    printf("digite [0] pra sair\n");
    do{
        scanf("%d", &op);
        switch(op){
                case 1 :insere(li);
                    break;
                case 2 :insere(li0);
                    break;
        }
    }while(op != 0);

    soma_lista(li, li0);


    return 0;
}

lista* inicia_lista(){

    lista* liz =(lista*) malloc(sizeof(lista));

    if(liz != NULL)
        liz->prox = NULL;

    return liz;
}

int insere(lista* li){

    lista* no =(lista*) malloc(sizeof(lista));

    if(no != NULL){
        printf("digite um numero");
        scanf("%d", &no->num);
        no->prox=NULL;

        if(li->prox == NULL)
            li->prox = no;
        else{
            lista* aux = li->prox;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = no;
        }
    }
}

void soma_lista(lista *li, lista* li0){

    lista* aux = li->prox;
    lista* aux2 = li0->prox;
    int soma = 0;
    do{
        soma = 0;
        soma = aux->num + aux2->num;
        printf("[%d]\n",soma);
        aux = aux->prox;
        aux2= aux2->prox;
    }while(aux != NULL || aux2 != NULL);

    if(aux2 == NULL)
        do{
            printf("[%d]\n", aux->num);
            aux = aux -> prox;
        }while(aux->prox != NULL);

    if(aux == NULL)
        do{
            printf("[%d]\n", aux2->num);
            aux2 = aux2 -> prox;
        }while(aux->prox != NULL);









}
