#include <stdio.h>

// Funções de operações matemáticas
int soma(int x, int y) {
    return x + y;
}

int subtracao(int x, int y) {
    return x - y;
}

int multiplicacao(int x, int y) {
    return x * y;
}

int divisao(int x, int y) {
    if (y == 0) {
        printf("Erro: Divisão por zero!\n");
        return 0;
    }
    return x / y;
}

// Função para armazenar o resultado no histórico
void adicionarAoHistorico(int historico[], int tamanho, int novoResultado) {
    for (int i = 0; i < tamanho - 1; i++) {
        historico[i] = historico[i + 1];  // Move os valores para trás
    }
    historico[tamanho - 1] = novoResultado;  // Adiciona o novo resultado no final
}

int funcao() {
    int num1, num2, opcao, resultado;
    int historico[6] = {0}; // Inicializa o histórico com zeros

    while (1) { // Loop infinito para permitir múltiplos cálculos
        printf("\n\nCalculadora simples:\n");
        printf("Digite dois números: ");
        scanf("%d %d", &num1, &num2);

        printf("Escolha uma operação:\n 1-Soma\n 2-Subtração\n 3-Multiplicação\n 4-Divisão\n 5-Ver histórico\n 6-Sair\n");
        scanf("%d", &opcao);

        if (opcao == 6) {
            printf("Encerrando...\n");
            break;
        }

        switch (opcao) {
            case 1:
                resultado = soma(num1, num2);
                printf("Resultado: %d\n", resultado);
                adicionarAoHistorico(historico, 6, resultado);
                break;
            case 2:
                resultado = subtracao(num1, num2);
                printf("Resultado: %d\n", resultado);
                adicionarAoHistorico(historico, 6, resultado);
                break;
            case 3:
                resultado = multiplicacao(num1, num2);
                printf("Resultado: %d\n", resultado);
                adicionarAoHistorico(historico, 6, resultado);
                break;
            case 4:
                resultado = divisao(num1, num2);
                printf("Resultado: %d\n", resultado);
                adicionarAoHistorico(historico, 6, resultado);
                break;
            case 5:
                printf("Histórico de últimos 6 resultados:\n");
                for (int i = 0; i < 6; i++) {
                    printf("[%d] %d\n", i + 1, historico[i]);
                }
                break;
            default:
                printf("Opção inválida!\n");
        }
    }
    return 0;
}