#include <stdio.h>

int main() {
    long int num;
    int contador = 0;
    printf("Digite um número: ");
    scanf("%ld", &num);
    while (num != 0) {
        num /= 10;
        contador++;
    }
    printf("Número de dígitos: %d\n", contador);
    return 0;
}