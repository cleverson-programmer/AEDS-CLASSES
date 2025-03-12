#include <stdio.h>

void converterParaBinario(int numero) {
    if (numero == 0) {
        printf("0");
        return;
    }

    int binario[32], i = 0; //Salvando os bits no vetor e a posição atual com o "i".

    while (numero > 0) {
        binario[i] = numero % 2;  // Guarda o resto (0 ou 1)
        numero = numero / 2;      // Atualiza o número (quociente)
        i++;    //Próxima posição do vetor
    }

    // Imprime os bits em ordem reversa
    //Como um vetor começa em 0, temos que pegar a última posição menos 1, pois são 5 números em 4 posições (0 a 4)
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
}

int binario() {
    int numero;
    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    printf("Representação binária: ");
    converterParaBinario(numero);

    printf("\n");
    return 0;
}