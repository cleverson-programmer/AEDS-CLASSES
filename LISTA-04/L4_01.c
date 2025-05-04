#include <stdio.h>
#include <ctype.h>
// Definição da struct Aluno
typedef struct {
    float notas[3];
    char tipoMedia; // 'A' para aritmética, 'P' para ponderada
} Aluno;

void calcularMedia(Aluno aluno);

int main() {
    int n;

    printf("Quantos alunos deseja inserir? ");
    scanf("%d", &n);

    Aluno alunos[n]; // Vetor de structs Aluno

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);

        for (int j = 0; j < 3; j++) {
            printf("Digite a nota %d: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }

        printf("Digite o tipo de média ('A' para aritmética, 'P' para ponderada): ");
        scanf(" %c", &alunos[i].tipoMedia); // espaço para consumir o enter

        // Chamada do procedimento
        calcularMedia(alunos[i]);
    }

    return 0;
}

// Procedimento para calcular e exibir a média
void calcularMedia(Aluno aluno){
    float media;

    aluno.tipoMedia = tolower(aluno.tipoMedia);

    switch(aluno.tipoMedia){
        case 'a':
            media = (aluno.notas[0] + aluno.notas[1] + aluno.notas[2]) / 3;
            printf("Média Aritmética: %.2f\n", media);
        break;
        case 'p':
            media = (aluno.notas[0] * 5 + aluno.notas[1] * 3 + aluno.notas[2] * 2) / 10;
            printf("Média Ponderada: %.2f\n", media);
        break;
        default:
            printf("Nenhuma opção válida!");
    }
}