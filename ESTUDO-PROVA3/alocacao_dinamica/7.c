#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char nome[50];
    float nota;
}Alunos;

void reading();

float average(int n, Alunos notas[]);

void print(float media);

int main(){
    reading();

    return 0;
}

void reading(){
    Alunos *notas = NULL;
    int count = 0;
    char continuar;

    do{
        Alunos *temp = (Alunos *) realloc(notas, (count + 1) * sizeof(Alunos));
        if(temp == NULL){
            printf("Erro na alocação dinâmica");
            free(notas);
            exit(1);
        }

        notas = temp;

        printf("Digite o nome do %d° aluno: ", count + 1);

        // Limpa o buffer antes de fgets, apenas se for necessário
        fflush(stdin);  // Para Windows, evita sujeira no buffer limpando a entrada padrão

        fgets(notas[count].nome, sizeof(notas[count].nome), stdin);
        notas[count].nome[strcspn(notas[count].nome, "\n")] = '\0';

        printf("Digite a nota do %d° aluno: ", count + 1);
        scanf(" %f", &notas[count].nota);

        // Limpa o buffer antes de ler o caractere 'continuar'
        while ((getchar()) != '\n');  // Descarta o '\n' após scanf

        printf("Deseja continuar (s) ou (n): ");
        scanf("%c", &continuar);
        continuar = tolower(continuar);

        while ((getchar()) != '\n');

        count++;
    }while(continuar == 's');

    average(count, notas);
    free(notas); //Libera memória após o uso;
}

float average(int n, Alunos notas[]){
    float soma = 0;
    float media = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        if(notas[i].nota > 6){
            soma += notas[i].nota;
            count++;
        }
    }

    media =  soma / count;
    print(media);
    return media;
}

void print(float media){
    printf("A média dos alunos aprovados é: %.2f", media);
}