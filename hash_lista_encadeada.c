#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10

typedef struct no{
    int chave;
    struct lista *prox;
}NO;

NO *lista[TAMANHO];


int hash(int chave){
    return chave%TAMANHO;
}

void colidiu(NO *posicao, NO *no){
    
    if(posicao->prox != NULL){
        colidiu(posicao->prox,no);
    }else{
        posicao->prox = no;
    }
}

void imprime(NO *p){
    
    printf("- %d ",p->chave);
    if(p->prox != NULL) imprime(p->prox);
    
}

void inserir(int chave, int posicao){
    if(lista[posicao]==NULL){
        
        lista[posicao] = (NO*) malloc(sizeof(NO));
        lista[posicao]->chave = chave;
    }else{
        
        NO *p = (NO*) malloc(sizeof(NO));
        p->chave = chave;
        p->prox = NULL;
        
        colidiu(lista[posicao],p);
    }
    
    return;
    
}

int main()
{
    for(int i=0;i<TAMANHO;i++){
        lista[i] = NULL;
    }
    
    inserir(532,hash(532)); 
    inserir(574,hash(574));
    inserir(831,hash(831)); 
    inserir(899,hash(899)); 
    inserir(990,hash(990));
    inserir(379,hash(379));
    inserir(583,hash(583));
    inserir(779,hash(779));
    inserir(710,hash(710));
    
    for(int i=0;i<TAMANHO;i++){
        if(lista[i]!=NULL){
            printf("Posição[%d] ",i);
            imprime(lista[i]);
            printf("\n");
            
            
        }else{
            printf("Posição[%d]: *********\n",i);
        }
        
    }
    return 0;
}

