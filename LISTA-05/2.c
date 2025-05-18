// Implemente um procedimento preencheNotas que receba e preencha um vetor com as notas
// de uma turma de 10 alunos. Faça um procedimento calculaMedia que receba um vetor
// preenchido com as notas, calcule a média da turma e conte quantos alunos obtiveram nota acima
// da média. Esse procedimento deve exibir a média e o resultado da contagem. Faça um programa
// (main) que declare e preencha as devidas o vetor com valores digitados e acione os
// procedimentos.

#include <stdio.h>
#include <stdlib.h>

void preencherNotas(int vetor[], int tamanho);
void calculaMedia(int vetor[], int tamanho);

int main(){
    int vetor[10];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    preencherNotas(vetor, tamanho);
    calculaMedia(vetor, tamanho);

    return 0;
}

void preencherNotas(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Digite a %d° nota: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void calculaMedia(int vetor[], int tamanho){
    int soma = 0;
    int count = 0;

    for(int i = 0; i < tamanho; i++){
        soma += vetor[i];
    }

    float media = soma / tamanho;

    for(int i = 0; i < tamanho; i++){
        if(vetor[i] > media) count++;
    }

    printf("A média é: %.2f \nA quantidade de alunos acima da média: %d", media, count);
}