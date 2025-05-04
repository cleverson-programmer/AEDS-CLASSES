#include <stdio.h>

//Passagem de valores por referência usa ponteiros, passando o endereço da variável

void mostrarVariaveis(int *a, int *b, int *c) {
    printf("NOME_VARIAVEL\tENDEREÇO\tVALOR\n");
    printf("a\t\t%p\t%d\n", (void*)a, *a);
    printf("b\t\t%p\t%d\n", (void*)b, *b);
    printf("c\t\t%p\t%d\n", (void*)c, *c);
}

int main() {
    int a, b, c;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("Digite o valor de c: ");
    scanf("%d", &c);

    mostrarVariaveis(&a, &b, &c);

    return 0;
}