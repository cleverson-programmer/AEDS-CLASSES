#include <stdio.h>

int fnVetor(int matriz[10][10], int *vetor, int n, int m);

int main(){
    int n, m;

    printf("Digite a quantidade de linhas:");
    scanf("%d", &n);

    printf("Digite a quantidade de colunas:");
    scanf("%d", &m);

    int matriz[10][10]; // Ajustado para tamanho fixo máximo
    int vetor[m];
    
    for (int i = 0; i < n; i++) {         // linhas
        for (int j = 0; j < m; j++) {     // colunas
            printf("Digite o valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    fnVetor(matriz, vetor, n, m);
    return 0;
}

int fnVetor(int matriz[10][10], int *vetor, int n, int m){
    // Inicializa o vetor com 0
    for (int j = 0; j < m; j++) {
        vetor[j] = 0;
    }

    // Soma os valores de cada coluna
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vetor[j] += matriz[i][j];
        }
    }

    // Imprime o vetor
    for (int j = 0; j < m; j++) {
        printf("%d ", vetor[j]);
    }

    return 0;
}