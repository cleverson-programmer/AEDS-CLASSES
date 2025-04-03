#include <stdio.h>

// Procedimento para ler dois números
void le_numeros(int *n1, int *n2) {
    printf("Digite o primeiro numero: ");
    scanf("%d", n1); // Lê diretamente no endereço de n1
    printf("Digite o segundo numero: ");
    scanf("%d", n2); // Lê diretamente no endereço de n2
}

// Procedimento para imprimir dois números
void imprime_numeros(int n1, int n2) {
    printf("Numeros digitados: %d %d\n", n1, n2);
}

int main() {
    int n1, n2; // Variáveis locais
    le_numeros(&n1, &n2); // Passa os endereços das variáveis
    imprime_numeros(n1, n2); // Passa os valores para impressão
    return 0;
}