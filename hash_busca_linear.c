#include <stdio.h>
#define TAMANHO 10

int vetor[TAMANHO];
int vagas = TAMANHO;


int hash(int chave){
    return chave%TAMANHO;
}

void inserir(int chave, int posicao){
    if(vagas==0) return;
    if(posicao==10) posicao = 0;
    if(vetor[posicao] != NULL) inserir(chave,posicao+1);
    else vetor[posicao] = chave;
    return;
}

int main()
{
    for(int i=0;i<TAMANHO;i++){
        vetor[i]=NULL;
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
    printf("CHAVE%d: %d Posição VETOR[%d]\n",i,vetor[i],i);
    }
    return 0;
}
