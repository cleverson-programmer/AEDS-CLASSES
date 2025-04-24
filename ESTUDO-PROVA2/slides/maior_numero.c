#include <stdio.h>

int main(){
    int vetor[5];
    int maior = vetor[0];
    for( int i = 0; i < 5; i++){
        printf("Digite o %d° numero:", i + 1);
        scanf("%d", &vetor[i]);

        if(vetor[i] > maior){
            maior= vetor[i];
        }
    }

    printf("O maior é %d", maior);
    return 0;
}