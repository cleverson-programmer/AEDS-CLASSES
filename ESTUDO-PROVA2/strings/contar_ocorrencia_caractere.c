#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Contar ocorrências de um caractere
// Crie uma função que conte quantas vezes um caractere aparece em uma string.

void count_caractere( char *str, char c){
    int length = strlen(str);
    int count = 0;

    for(int i = 0; i < length; i++){

        if(str[i] == c){
            count++;
        }
    }

    printf("%d\n", count);
}

int main(){
    char word[256];
    char c;

    printf("Escreva uma palavra:");
    fgets(word, sizeof(word), stdin);

    word[strcspn(word, "\n")] = '\0';

    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }

    printf("Digite um caractere para verificar:");
    scanf("%c", &c);

    count_caractere(word, c);

    return 0;
}