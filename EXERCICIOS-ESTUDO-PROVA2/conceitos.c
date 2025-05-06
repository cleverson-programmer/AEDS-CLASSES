// Crie uma struct Aluno com uma vetor de nome, uma matriz 3x3 de notas, uma variavel matricula que é bool. O usuário deverá digitar a quantidade de alunos que deseja cadastrar. 
//Faça uma função que calcule a média geral do aluno. Outra função que retorne apenas o dado de um aluno por vez e outra que retorna de todos os alunos de uma única vez

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    char nome[256];
    float matriz[3][3];
    bool matricula;
    float media;
} Aluno;

// Protótipos
void preencher_matriz(float matriz[3][3]);
float media_geral(float matriz[3][3]);
float media_total(Aluno alunos[], int n);
void unico_Aluno(Aluno aluno);
void varios_Aluno(Aluno alunos[], int n);

int main() {
    int n;
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n);
    getchar(); // Limpa o \n após scanf

    Aluno alunos[n];

    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);

        printf("Digite o nome do aluno: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; // Remove \n do final

        int status;
        printf("Digite a situação da matrícula (1 = Ativo, 0 = Inativo): ");
        scanf("%d", &status);
        alunos[i].matricula = status ? true : false;

        preencher_matriz(alunos[i].matriz);
        alunos[i].media = media_geral(alunos[i].matriz);

        getchar(); // Limpa \n após scanf
    }

    printf("\n===== Exibindo todos os alunos =====\n");
    varios_Aluno(alunos, n);

    printf("\n===== Exibindo um aluno por vez =====\n");
    for (int i = 0; i < n; i++) {
        unico_Aluno(alunos[i]);
    }

    return 0;
}

// Preenche a matriz de notas do aluno
void preencher_matriz(float matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Nota [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

// Calcula a média geral de uma matriz 3x3
float media_geral(float matriz[3][3]) {
    float soma = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma += matriz[i][j];
        }
    }
    return soma / 9.0;
}

//Media de todas as matrizes
float media_total(Aluno alunos[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += alunos[i].media;
    }
    return soma / n;
}

// Exibe dados de um único aluno
void unico_Aluno(Aluno aluno) {
    printf("\nAluno: %s\n", aluno.nome);
    printf("Matrícula: %s\n", aluno.matricula ? "Ativa" : "Inativa");
    printf("Notas:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.1f ", aluno.matriz[i][j]);
        }
        printf("\n");
    }
    printf("Média Geral: %.2f\n", aluno.media);
}

// Exibe dados de todos os alunos
void varios_Aluno(Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        unico_Aluno(alunos[i]);
    }

    float mediaGeralTurma = media_total(alunos, n);
    printf("\nMédia geral da turma: %.2f\n", mediaGeralTurma);
}
