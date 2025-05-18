// Declare uma struct chamada Pessoa com os campos nome (até 50 caracteres) e idade. 
// Escreva um programa que aloque dinamicamente um vetor de Pessoa, leia os dados e exiba tudo ao final.
// Use malloc e libere a memória com free.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
}Pessoa;

int main(){
    int n;
    
    printf("Digite a quantidade de pessoas:");
    scanf("%d", &n);

    getchar();

    //Alocando memoria dinamicamente para n pessoas
    Pessoa *lista = (Pessoa *) malloc(n * sizeof(Pessoa));
    if(lista == NULL){
        printf("erro ao alocar memoria");
        return 1;
    }

    // Leitura dados
    for(int i = 0; i < n; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", lista[i].nome);
        printf("Idade: ");
        scanf("%d", &lista[i].idade);
    }

    // Exibe os dados
    printf("\nLista de Pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d\n", lista[i].nome, lista[i].idade);
    }

    free(lista); // Libera memória
    return 0;
}