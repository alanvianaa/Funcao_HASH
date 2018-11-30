#include <stdio.h>
#define TAMANHO 11

int vetor[TAMANHO];
int vagas = TAMANHO;


int hash(int k){
    return k%TAMANHO;
}

int hash2(int k, int i){
    return (k+(i*(hash3(k))))%TAMANHO;
}

int hash3(int k){
    return 1+(k%(TAMANHO*1));
}

void inserir(int chave, int posicao){
    if(vagas==0) return;
    if(vetor[posicao] != NULL){
        if(posicao > 0) 
        inserir(chave,hash2(chave,posicao)); 
    } 
    else vetor[posicao] = chave;
    return;
}

int main()
{
    for(int i=0;i<TAMANHO;i++){
        vetor[i]=NULL;
    }
    
    inserir(10,hash(10)); printf("10 %% 11 = %d \n",hash(10));
    inserir(22,hash(22)); printf("22 %% 11 = %d \n",hash(22));
    inserir(31,hash(31)); printf("31 %% 11 = %d \n",hash(31));
    inserir(4,hash(4)); printf("4 %% 11 = %d \n",hash(4));
    inserir(15,hash(15)); printf("15 %% 11 = %d \n",hash(15));
    inserir(28,hash(28)); printf("28 %% 11 = %d \n",hash(28));
    inserir(17,hash(17)); printf("17 %% 11 = %d \n",hash(17));
    inserir(88,hash(88)); printf("88 %% 11 = %d \n",hash(88));
    inserir(59,hash(59)); printf("59 %% 11 = %d \n",hash(59));
    
    
    for(int i=0;i<TAMANHO;i++){
    printf("CHAVE%d: %d Posição VETOR[%d]\n",i,vetor[i],i);
    }
    return 0;
}