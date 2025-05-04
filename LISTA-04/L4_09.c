#include <stdio.h>

void primo(int m, int *p1, int *p2) {
    int count;

    // Encontrar o maior primo menor que m
    for (int i = m - 1; i >= 2; i--) {
        count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                count++;
            }
        }
        if (count == 2) {  // Se tiver exatamente 2 divisores, é primo
            *p1 = i;
            break;
        }
    }

    // Encontrar o menor primo maior que m
    for (int i = m + 1; ; i++) {
        count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                count++;
            }
        }
        if (count == 2) {
            *p2 = i;
            break;
        }
    }

    // Impressão dos resultados
    printf("Primo\n");
    printf("Menor do que M: %d\n", *p1);
    printf("Maior do que M: %d\n", *p2);
}

int main() {
    int m;
    int p1 = 0, p2 = 0;

    printf("Digite o valor de M: ");
    scanf("%d", &m);

    primo(m, &p1, &p2);

    return 0;
}