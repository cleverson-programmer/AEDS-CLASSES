// Escreva um vetor de inteiros A com 10 elementos. Em seguida, leia um vetor de inteiros B,
// também com 10 elementos. Durante a leitura do vetor B, se o elemento na posição i for igual ao
// elemento na mesma posição do vetor A, rejeitar o valor e solicitar a entrada de um novo valor. A
// rejeição deve ocorrer até que o valor seja digitado um valor válido. Após a leitura dos vetores A e
// B, criar um algoritmo que calcule e imprima a diferença entre cada um dos elementos.

#include <stdio.h>

int main(){
    int A[10], B[10];

    for(int i = 0; i < 10; i++){
        printf("Digite o %d° elemento: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("\nPrimeiro vetor\n");
    for(int j = 0; j < 10; j++){
        printf("%d ", A[j]);
    }

    for(int i = 0; i < 10; i++){
        do{
            printf("Digite o %d° valor: ", i + 1);
            scanf("%d", &B[i]);
        }while (B[i] == A[i]);
    }

    printf("\nSegundo vetor\n");
    for(int j = 0; j < 10; j++){
        printf("%d ", B[j]);
    }


    printf("\nDiferença\n");
    for(int j = 0; j < 10; j++){
        printf("%d ", A[j] - B[j]);
    }
}