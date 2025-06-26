#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int matricula;
    char nome[50];
    float nota;
} Aluno;

int main() {
    FILE *arquivo;
    Aluno *alunos = NULL;
    int qtd = 0;
    char c;

    do {
        // Realocação de memória
        Aluno *temp = (Aluno *) realloc(alunos, (qtd + 1) * sizeof(Aluno));
        if (temp == NULL) {
            printf("Erro de alocação de memória\n");
            free(alunos);
            exit(1);
        }
        alunos = temp;

        // Entrada de dados
        printf("Digite o nome: ");
        fgets(alunos[qtd].nome, sizeof(alunos[qtd].nome), stdin);
        alunos[qtd].nome[strcspn(alunos[qtd].nome, "\n")] = '\0';

        printf("Digite a matrícula: ");
        scanf(" %d", &alunos[qtd].matricula);

        printf("Digite a nota: ");
        scanf(" %f", &alunos[qtd].nota);
        getchar(); // Limpar o buffer

        // Abrir arquivo no modo append binário
        arquivo = fopen("alunos.bin", "ab");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo\n");
            free(alunos);
            exit(1);
        }

        // Gravar o último aluno inserido
        fwrite(&alunos[qtd], sizeof(Aluno), 1, arquivo);
        fclose(arquivo);

        qtd++;

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &c);
        getchar(); // Limpar o buffer

    } while (tolower(c) == 's');

    // Leitura dos dados do arquivo
    arquivo = fopen("alunos.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para leitura\n");
        exit(1);
    }

    // Verificar o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    int total_registros = tamanho / sizeof(Aluno);

    // Alocar memória para leitura
    Aluno *lidos = (Aluno *) malloc(total_registros * sizeof(Aluno));
    if (lidos == NULL) {
        printf("Erro ao alocar memória para leitura\n");
        fclose(arquivo);
        exit(1);
    }

    fread(lidos, sizeof(Aluno), total_registros, arquivo);
    fclose(arquivo);

    // Exibir os dados lidos
    printf("\nAlunos cadastrados:\n");
    for (int i = 0; i < total_registros; i++) {
        printf("Nome: %s | Matrícula: %d | Nota: %.2f\n",
               lidos[i].nome, lidos[i].matricula, lidos[i].nota);
    }

    free(lidos);
    free(alunos);

    return 0;
}