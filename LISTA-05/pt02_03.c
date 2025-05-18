// Escreva um algoritmo que:
// (a) Crie um arranjo de 5 elementos inteiros e o preencha de números
// (b) Procure a posição do menor elemento deste arranjo
// (c) Troque o menor elemento com elemento da primeira posição
// (d) Imprima os elementos do arranjo

#include <stdio.h>
#include <time.h>

void preencher(int vetor[], int tamanho);
void procurar(int vetor[], int tamanho);
void trocar(int vetor[], int tamanho, int posicao);

int main(){
    int vetor[5];
    int lenght = sizeof(vetor) / sizeof(vetor[0]);

    preencher(vetor, lenght);

    return 0;
}

void preencher(int vetor[], int tamanho){

    srand(time(0));
    for(int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100;
    }

    printf("\nVETOR INICIAL\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }

    procurar(vetor, tamanho);
}

void procurar(int vetor[], int tamanho){
    int menor = vetor[0];
    int posicao = 0;
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] < menor){
            menor = vetor[i];
            posicao = i;
        }
    }

    trocar(vetor, tamanho, posicao);
}

void trocar(int vetor[], int tamanho, int posicao){
    int temp = vetor[0];
    vetor[0] = vetor[posicao];
    vetor[posicao] = temp;

    printf("\nVALORES TROCADOS\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
}