#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Substituir caracteres
// Escreva uma função que substitua todas as ocorrências de um caractere por outro em uma string.

int substituir_caracteres( char *str, char antigo, char novo){
    int length = strlen(str);
    //word --> ana
    //antigo --> n
    //novo --> m
    for(int i = 0; i < length; i++){
        if(str[i] == antigo){
            str[i] = novo;
        }
    }

    printf("%s", str);

}

int main(){
    char word[50];
    char antigo, novo;
    printf("Digite uma palavra:");
    fgets(word, sizeof(word), stdin);

    //O \0 tem que passar com aspas simples sempre para saber que é um caracter e não parte da string
    word[strcspn(word, "\n")] = '\0';

    //Se fosse necessário converter tudo para maiusculo
    // for(int i = 0; i < strlen(word); i++){
    //     word[i] = toupper(word[i]);
    // }

    printf("Digite o caractere da palavra que deseja substituir:\nDigite o novo caractere para adicionar:\n");
    scanf("%c %c", &antigo, &novo);

    substituir_caracteres(word, antigo, novo);

    return 0;
}