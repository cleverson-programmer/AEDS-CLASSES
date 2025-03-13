
#include <stdio.h>

int main() {
    float nota, soma = 0;
    int count = 0;

    printf("Digite as notas (digite -1 para finalizar): ");

    while (1) {
        scanf("%f", &nota);
        if (nota == -1) break;
        soma += nota;
        count++;
    }

    if (count > 0) {
        printf("Média das notas: %.2f\n", soma / count);
    } else {
        printf("Nenhuma nota foi inserida.\n");
    }

    return 0;
}
