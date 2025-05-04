#include <stdio.h>

// Definição da struct para representar um conjunto de 3 inteiros
typedef struct {
    int valores[3];
} Conjunto;

// Procedimento para ordenar e exibir os valores em ordem crescente
void exibirOrdenado(Conjunto c) {
    // Ordenação simples (bubble sort para 3 elementos)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (c.valores[j] > c.valores[j + 1]) {
                int temp = c.valores[j];
                c.valores[j] = c.valores[j + 1];
                c.valores[j + 1] = temp;
            }
        }
    }

    // Exibição dos valores ordenados
    printf("Ordem crescente: %d %d %d\n", c.valores[0], c.valores[1], c.valores[2]);
}

int main() {
    int n;
    printf("Digite a quantidade de conjuntos: ");
    scanf("%d", &n);

    Conjunto conjuntos[n];

    // Leitura dos conjuntos
    for (int i = 0; i < n; i++) {
        printf("\nConjunto %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("Digite o %d° valor: ", j + 1);
            scanf("%d", &conjuntos[i].valores[j]);
        }
    }

    // Chamada do procedimento para cada conjunto
    printf("\n--- Conjuntos em ordem crescente ---\n");
    for (int i = 0; i < n; i++) {
        printf("Conjunto %d: ", i + 1);
        exibirOrdenado(conjuntos[i]);
    }

    return 0;
}