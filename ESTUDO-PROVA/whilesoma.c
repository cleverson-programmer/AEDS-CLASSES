#include <stdio.h>

int main() {
    int num, soma = 0;
    while (num != 0) {
        printf("Digite números (0 para parar): ");
        scanf("%d", &num);
        soma += num;
    }
    printf("Soma: %d\n", soma);
    return 0;
}