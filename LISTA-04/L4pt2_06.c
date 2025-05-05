#include <stdio.h>

// Função para obter o k-ésimo dígito da direita para a esquerda
int kesimo_digito(int n, int k) {
    for (int i = 1; i < k; i++) {
        n /= 10;  // Remove os k-1 dígitos da direita
    }
    return n % 10;  // Retorna o k-ésimo dígito
}

int main() {
    int numero, k;

    // Entrada dos valores
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    printf("Digite a posicao k (da direita para a esquerda): ");
    scanf("%d", &k);

    // Verificação simples (opcional)
    if (numero <= 0 || k <= 0) {
        printf("Erro: numero e k devem ser positivos.\n");
        return 1;
    }

    // Chamada da função e exibição do resultado
    int digito = kesimo_digito(numero, k);
    printf("O %dº digito da direita para a esquerda em %d é: %d\n", k, numero, digito);

    return 0;
}