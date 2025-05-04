#include <stdio.h>
#include <stdbool.h>

// Função que realiza a operação lógica: (~A V B & C) => (!A || (B && C))
bool operacao_logica(bool A, bool B, bool C) {
    return (!A || (B && C));
}

//A maneira mais segura e clara é usar uma variável int para ler com scanf como 0 ou 1, e depois atribuir à variável bool.
int main() {
    bool A, B, C;

    // Exemplo de entrada: pode usar true/false diretamente, ou 1/0
    printf("Digite os valores de A, B e C (0 para false, 1 para true):\n");
    
    printf("A: ");
    scanf("%d", (int*)&A);  //%d espera um ponteiro para inteior (&A), porém estamos apontando para um "bool" que é um typedef para unsigned char na lib, para isso fazemos uma conversão de tipo explicita "(int*)&A" para informar que estamos tratando a variável como INT
    printf("B: ");
    scanf("%d", (int*)&B);
    printf("C: ");
    scanf("%d", (int*)&C);

    bool resultado = operacao_logica(A, B, C);

    printf("Resultado da expressão (~A V B & C): %s\n", resultado ? "true" : "false");

    return 0;
}