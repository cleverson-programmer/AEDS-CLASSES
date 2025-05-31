#include <stdio.h>

void imprimirPascal(int n);

int main() {
    int n;
    scanf("%d", &n);

    imprimirPascal(n);

    return 0;
}

void imprimirPascal(int n) {
    int triangulo[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangulo[i][j] = 1;
            } else {
                triangulo[i][j] = triangulo[i-1][j-1] + triangulo[i-1][j];
            }
            printf("%d ", triangulo[i][j]);
        }
        printf("\n");
    }
}