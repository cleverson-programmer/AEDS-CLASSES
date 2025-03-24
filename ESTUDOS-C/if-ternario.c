#include <stdio.h>

int main() {
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("%s\n", num > 0 ? "Positivo" : (num < 0 ? "Negativo" : "Zero"));
    return 0;
}