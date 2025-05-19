//Alocando memória para uma quantidade indefinida de dados e salvando dados na matriz

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz = NULL;         // Matriz (vetor de ponteiros)
    int *tamanhosColunas = NULL; // Armazena quantas colunas tem cada linha
    int linhas = 0;

    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        int colunas;
        printf("\nDigite a quantidade de elementos da linha %d (ou 0 para encerrar): ", linhas + 1);
        scanf("%d", &colunas);
        if (colunas <= 0) break;

        // Realocando o vetor de ponteiros da matriz
        int **tempMatriz = (int **) realloc(matriz, (linhas + 1) * sizeof(int *));// Adicionando mais uma linha
        int *tempTamanhos = (int *) realloc(tamanhosColunas, (linhas + 1) * sizeof(int));   //Quantidade de elementos por linha
        if (tempMatriz == NULL || tempTamanhos == NULL) {
            printf("Erro na alocação de memória.\n");
            return 1;
        }

        matriz = tempMatriz;
        tamanhosColunas = tempTamanhos;

        // Alocando a linha atual
        matriz[linhas] = (int *) malloc(colunas * sizeof(int)); //Matriz na linha atual do loop alocando a quantidade de elementos (colunas)
        if (matriz[linhas] == NULL) {
            printf("Erro ao alocar linha.\n");
            return 1;
        }

        tamanhosColunas[linhas] = colunas;

        // Lendo os valores da linha
        printf("Digite os %d valores da linha %d:\n", colunas, linhas + 1);
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", linhas, j);
            scanf("%d", &matriz[linhas][j]);
        }

        linhas++;

        printf("Deseja adicionar outra linha? (s/n): ");
        scanf(" %c", &continuar); // espaço antes de %c ignora '\n' do buffer
    }

    // Imprime a matriz
    printf("\nMatriz final:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < tamanhosColunas[i]; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberação de memória
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    free(tamanhosColunas);

    return 0;
}
