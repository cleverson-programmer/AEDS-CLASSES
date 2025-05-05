#include <stdio.h>
#include <string.h>

// Escreva uma função que receba uma string e retorne seu tamanho usando strlen.
int tamanho(char *nome);

int main(){
    char nome[256];

    printf("Digite uma palavra:");
    fgets(nome, sizeof(nome), stdin);
    
    nome[strcspn(nome, "\n")] = '\0';

    printf("O tamanho da string é: %d caracteres", tamanho(nome));
}

int tamanho(char *nome){
    return strlen(nome);
}