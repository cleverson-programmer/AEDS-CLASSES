#include <stdio.h>

// Escreva uma função que receba um vetor de inteiros e seu tamanho, e retorne a média dos elementos.
float media(int n, int *vetor);

int main(){
    int n;
    printf("Digite a quantidade de elementos:");
    scanf("%d", &n);

    int vetor[n];

    for(int i = 0; i < n; i++){
        printf("Digite o %d° elemento:", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("A média é: %.2f", media(n, vetor));

    return 0;
}

float media(int n, int *vetor){
    int soma = 0;
    float media = 0.0;

    for(int i = 0; i < n; i++){
        soma += vetor[i];
    }

    media = soma / n;

    return media;   //No printf imprime o valor do retorno caso a gente chame a fn dentro do printf
}