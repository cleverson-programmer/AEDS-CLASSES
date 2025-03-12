#include <stdio.h>

//Força o usuário a digitar um número positivo, executa ao menos uma vez por conta do "do"
int main() {
    int num;

    do {
        printf("Digite um número positivo: ");
        scanf("%d", &num);

        if (num < 0)
            printf("Número inválido! Tente novamente.\n");

    } while (num < 0);

    printf("Número aceito: %d\n", num);
    return 0;
}