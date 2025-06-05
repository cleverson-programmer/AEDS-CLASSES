// Crie uma struct Aluno com os campos:
// nome (string), nota1 (float), nota2 (float)
// Crie uma função atualizarNotas() que recebe um ponteiro para a struct Aluno e atualiza as duas notas com novos valores digitados pelo usuário.
// No final, calcule e mostre a média.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
} Aluno;

void atualizarNotas(int tamanho, Aluno *alunos);

int main(){
    Aluno *alunos = NULL;
    int count = 0;
    char c;
    FILE *arquivo;

    setlocale(LC_ALL, "Portuguese");

    printf("Cadastro de notas:\n");
    do{
        Aluno *temp = (Aluno *) realloc(alunos, (count + 1) * sizeof(Aluno));
        if(temp == NULL){
            printf("Erro na alocação de memória\n");
            free(alunos);
            exit(1);
        }

        alunos = temp;

        while(getchar() != '\n'); // Limpa o buffer

        printf("Digite o nome do %d° aluno: ", count + 1);
        fgets(alunos[count].nome, sizeof(alunos[count].nome), stdin);
        alunos[count].nome[strcspn(alunos[count].nome, "\n")] = '\0';

        printf("Digite a 1° nota: ");
        scanf(" %f", &alunos[count].nota1);

        printf("Digite a 2° nota: ");
        scanf(" %f", &alunos[count].nota2);

        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &c);
        c = tolower(c);

        count++;

    } while(c == 's');

    while(getchar() != '\n'); // Limpa o buffer antes de ler o caractere
    char s;
    printf("Deseja atualizar notas? (S/N): ");
    scanf("%c", &s);
    if(s == 's' || s == 'S'){
        atualizarNotas(count, alunos);
    }

    for(int i = 0; i < count; i++){
        arquivo = fopen("arquivos.txt", "a");
        if(arquivo == NULL){
            printf("Erro ao salvar dados no arquivo\n");
            free(alunos);
            return 1;
        }

        fprintf(arquivo, "Nome: %s | Nota 1: %.1f | Nota 2: %.1f\n", 
            alunos[i].nome, alunos[i].nota1, alunos[i].nota2);
        fclose(arquivo);
    }

    free(alunos);
    return 0;
}

void atualizarNotas(int tamanho, Aluno *alunos){
    for(int i = 0; i < tamanho; i++){
        float media = 0.0;

        printf("Digite a 1ª nova nota do aluno %s: ", alunos[i].nome);
        scanf("%f", &alunos[i].nota1);
        printf("Digite a 2ª nova nota do aluno %s: ", alunos[i].nome);
        scanf("%f", &alunos[i].nota2);

        media = (alunos[i].nota1 + alunos[i].nota2) / 2.0;

        printf("Notas atualizadas!\n%s\n%.1f\n%.1f\n", alunos[i].nome, alunos[i].nota1, alunos[i].nota2);
        printf("Média: %.2f\n", media);
    }
}
