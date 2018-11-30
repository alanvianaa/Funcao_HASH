#include <stdio.h>
#define TAMANHO 100

int vetor[TAMANHO];
int vagas = TAMANHO;


int hash(int chave){
    
    int vetor[8];
    
    for(int i=0;i<8;i++){
        vetor[7-i] = chave%10;
        chave= chave/10;
    }

    vetor[4] = (vetor[3]+vetor[4])%10;
    vetor[5] = (vetor[2]+vetor[5])%10;
    vetor[6] = (vetor[1]+vetor[6])%10;
    vetor[7] = (vetor[0]+vetor[7])%10;

    vetor[6] = (vetor[6]+vetor[5])%10;
    vetor[7] = (vetor[7]+vetor[4])%10;
    
    return chave = (vetor[6]*10)+vetor[7];
}

int hash2(int chave){
    return chave%TAMANHO;
}

void inserir(int chave, int posicao){
    if(vagas==0) return;
    if(posicao==100) posicao = 0;
    if(vetor[posicao] != NULL) inserir(chave,hash2(chave));
    else vetor[posicao] = chave;
    return;
}

int main()
{
    
    for(int i=0;i<TAMANHO;i++){
        vetor[i]=NULL;
    }
    
    inserir(71348790,hash(71348790));
    inserir(71348790,hash(71348790));
    inserir(71345790,hash(71345790));
    
    for(int i=0;i<TAMANHO;i++){
    printf("CHAVE%d: %d Posição VETOR[%d]\n",i,vetor[i],i);
    }
    return 0;
    
    
}