#include <stdio.h>

void positivo(int *vetor, int tamanho);

int main(){
    int vetor[5];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    for(int i = 0; i < tamanho; i++){
        printf("Digite o número de posição %d °: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    positivo(vetor, tamanho);
    return 0;
}

void positivo(int *vetor, int tamanho){
    for(int j = 0; j < tamanho; j++){
        if(vetor[j] > 0){
            printf("%d\n", vetor[j]);
        }
    }
}