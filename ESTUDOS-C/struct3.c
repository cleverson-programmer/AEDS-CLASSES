#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 2

typedef struct {
  char nome[50];
  int idade;
  char curso[50];
  float nota1;
  float nota2;
  float media;
  char situacao[10];
} Aluno;

float mediaAluno(float x, float y){
  return (x + y) / 2;
}

 void gerarArquivo(const Aluno *alunos){
   
  FILE *arquivo = fopen("alunos.txt", "w");
   if(arquivo == NULL){
     printf("Erro ao abrir arquivo\n");
     return;
   }
   
   fprintf(arquivo, "Lista de Alunos:\n\n");

   // Percorre o vetor de alunos e escreve no arquivo
   for (int i = 0; i < MAX; i++) {
       fprintf(arquivo, "Nome: %s\n", alunos[i].nome);
       fprintf(arquivo, "Idade: %d\n", alunos[i].idade);
       fprintf(arquivo, "Curso: %s\n", alunos[i].curso);
       fprintf(arquivo, "Nota 1: %.2f\n", alunos[i].nota1);
       fprintf(arquivo, "Nota 2: %.2f\n", alunos[i].nota2);
       fprintf(arquivo, "Média: %.2f\n", alunos[i].media);
       fprintf(arquivo, "Situação: %s\n", alunos[i].situacao);
       fprintf(arquivo, "-------------------------\n");
   }

   fclose(arquivo);
   printf("\nArquivo 'alunos.txt' gerado com sucesso!\n");
}

int main(){
  Aluno alunos[MAX];

  for(int i = 0; i < MAX; i++){
    printf("Digite o nome do aluno %d\n", i + 1);
    fgets( alunos[i].nome, 50, stdin);
    alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; //Tem que usar aspas simples aqui pois se usar aspas duplas passa uma string e não um caractere literal.

    printf("Digite a idade:\n");
    scanf("%d", &alunos[i].idade);
    getchar(); //Limpa o buffer do teclado

    printf("Digite o curso:\n");
    fgets( alunos[i].curso, 50, stdin);
    alunos[i].curso[strcspn(alunos[i].curso, "\n")] = '\0';

    printf("Digite a primeira nota:\n");
    scanf("%f", &alunos[i].nota1);
    getchar();

    printf("Digite a segunda nota:\n");
    scanf("%f", &alunos[i].nota2);
    getchar();

    alunos[i].media = mediaAluno(alunos[i].nota1, alunos[i].nota2);

    if(alunos[i].media >= 6 && alunos[i].media <= 10){
      strcpy(alunos[i].situacao, "Aprovado");
    }else{
      strcpy(alunos[i].situacao, "Reprovado");
    }
  }

  //Exibição dos dados
  printf("\nLista dos alunos\n\n");
  for(int i = 0; i < MAX; i++){
    printf("Nome: %s\nIdade:%d\nCurso:%s\nMedia: %.2f\nSituação: %s\n", alunos[i].nome, alunos[i].idade, alunos[i].curso, alunos[i].media, alunos[i].situacao);
    printf("-------------------------\n");
  }

  // Chamada da função para gerar o arquivo com os dados dos alunos
  gerarArquivo(alunos);

  return 0;
}