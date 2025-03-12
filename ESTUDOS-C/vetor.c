#include <stdio.h>

// Função para somar dois vetores e exibir o resultado
int vetor() {
    int numeros1[5] = {10, 20, 30, 40, 50};
    int numeros2[5] = {1, 2, 3, 4, 5};
    int resultado[5];

    // Percorre os vetores e soma os elementos correspondentes
    for (int i = 0; i < 5; i++) {
        resultado[i] = numeros1[i] + numeros2[i];
    }

    // Exibindo os vetores e a soma
    printf("Vetor 1: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros1[i]);
    }

    printf("\nVetor 2: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros2[i]);
    }

    //Soma
    printf("\nSoma dos Vetores: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", resultado[i]);
    }

    printf("\n");

    return 0;
}