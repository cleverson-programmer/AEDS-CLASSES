#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma(int vetor[], int n);

int main(){
    int vetor[10];

    for(int i = 0; i < 10; i++){
        printf("Digite o %d° valor: ", i);
        scanf("%d", &vetor[i]);
    }

    int resultado = soma(vetor, 10);
    printf("%d", resultado);
}

int soma(int vetor[], int n){
    if(n == 0){
        return 0;
    }
    return vetor[n - 1] + soma(vetor, n - 1);
}