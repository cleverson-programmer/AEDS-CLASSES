#include <stdio.h>

int main() {
    int a, b;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    if (&a > &b) {
        //(void*) --> garante que vai imprimir o endereço de memória
        printf("O maior endereço é de A: %p\n", (void*)&a); //Operador para imprimir endereço é o %p
    } else {
        printf("O maior endereço é de B: %p\n", (void*)&b);
    }

    return 0;
}