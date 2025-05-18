// Escreva um programa que preencha e imprima na tela um vetor de tamanho 50, cujos valores
// são dados pela seguinte fórmula: vet[i] = (i + (3 x i)) % (i+1)
// onde i corresponde à posição do elemento no vetor

#include <stdio.h>

int main(){
    int vetor[50];

    for(int i = 0; i < 50; i++){
        vetor[i] = (4 * i) % (i + 1);
    }

    for(int i = 0; i < 50; i++){
        printf("%d ", vetor[i]);
    }
}