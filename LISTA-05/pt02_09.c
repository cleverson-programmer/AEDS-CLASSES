// Escreva um programa que armazene as idades dos alunos que estão presentes em uma aula da
// disciplina de Algoritmos e Estrutura de Dados I. Considere que o vetor possa conter até 60
// registros. Sabe-se que, em uma dada aula, alguns alunos podem ter faltado. Com isso, leia
// elementos até que seja digitado um valor 0 ou enquanto a quantidade de alunos for inferior à
// capacidade do vetor. Imprima:
// • Idade de todos os alunos presentes na aula (não imprimir idades não cadastradas).
// • Idade de todos os alunos com idade superior à média.

#include <stdio.h>

int main() {
    int idades[60];
    int quantidade = 0;
    int soma = 0;
    float media;

    printf("Digite as idades dos alunos (digite 0 para encerrar):\n");

    for (int i = 0; i < 60; i++) {
        int idade;
        printf("Aluno %d: ", i + 1);
        scanf("%d", &idade);

        if (idade == 0) {
            break;  // Encerra leitura se valor for 0
        }

        idades[quantidade] = idade;
        soma += idade;
        quantidade++;
    }

    if (quantidade == 0) {
        printf("Nenhum aluno presente.\n");
        return 0;
    }

    media = (float)soma / quantidade;

    printf("\nIdades dos alunos presentes:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", idades[i]);
    }

    printf("\n\nMédia de idade: %.2f\n", media);

    printf("Alunos com idade acima da média:\n");
    for (int i = 0; i < quantidade; i++) {
        if (idades[i] > media) {
            printf("%d ", idades[i]);
        }
    }

    printf("\n");

    return 0;
}
