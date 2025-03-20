#include <stdio.h>

int main() {
    int n;
    
    printf("Digite um número inteiro positivo N: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Por favor, insira um número inteiro positivo.\n");
        return 1;
    }

    int a = 0, b = 1, temp;
    
    if (n == 0) {
        printf("O 0º termo da sequência de Fibonacci é: 0\n");
        return 0;
    }
    
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    printf("O %dº termo da sequência de Fibonacci é: %d\n", n, b);
    
    return 0;
}
