#include <stdio.h>

void preencherMatriz(int n, int m, int matriz[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

int somaBorda(int n, int m, int matriz[n][m]) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                soma += matriz[i][j];
            }
        }
    }

    return soma;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int matriz[n][m];

    preencherMatriz(n, m, matriz);

    int resultado = somaBorda(n, m, matriz);

    printf("%d\n", resultado);

    return 0;
}