#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Converter para maiúsculas
// Escreva uma função que converta todos os caracteres de uma string para maiúsculos.

void converter( char *str){

    for (int i = 0; i < strlen(str); i ++){
        str[i] = toupper(str[i]);
    }

    printf("%s", str);
}

int main(){
    char str[256];
    printf("Digite uma string:");
    fgets(str, sizeof(str), stdin);

    converter(str);

    return 0;
}