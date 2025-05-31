#include <stdio.h>

int main() {
    int copias;
    float valor;

    scanf("%d", &copias);

    if (copias <= 100) {
        valor = copias * 0.25;
    } else {
        valor = 100 * 0.25 + (copias - 100) * 0.20;
    }

    printf("%.2f\n", valor);

    return 0;
}
