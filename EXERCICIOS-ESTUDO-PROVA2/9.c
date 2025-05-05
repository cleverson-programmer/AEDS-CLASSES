#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Implemente uma função que conte quantas vogais existem em uma string.

void vogais(char *str);

int main(){
    char str[256];
    printf("Escreva uma palavra:");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    vogais(str);
    return 0;
}

void vogais(char *str){
    int length = strlen(str);
    int count = 0;
    for(int i = 0; i < length; i++){
        str[i] = tolower(str[i]);
        if(strchr("aeiou", str[i])){
            count++;
        }
    }

    printf("Contém %d vogais", count);
}