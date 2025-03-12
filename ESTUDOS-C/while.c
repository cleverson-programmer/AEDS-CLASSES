#include <stdio.h>

//Imprime todos os números de 1 ate chegar no número digitado pelo usuário
int main() {
    int num, i = 1;

    printf("Digite um número positivo: ");
    scanf("%d", &num);

    while (i <= num) {
        printf("%d ", i);
        i++;
    }

    printf("\n");
    return 0;
}