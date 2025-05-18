// Solicite ao usuário que insira uma string. Conte o número de vogais na string utilizando um
// vetor para armazenar as vogais ('a', 'e', 'i', 'o', 'u') e percorrendo a string fornecida. Imprima
// o número total de vogais encontradas

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int vogais(char str[]);

int main(){

    char str[256];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    int result = vogais(str);

    printf("%d", result);

    return 0;
}

int vogais(char str[]){

    int length = 0;

    for(int i = 0; str[i] != '\0'; i++){
        str[i] = tolower(str[i]);
        if(strchr("aeiou", str[i])){
            length++;
        }

    }

    return length;
}