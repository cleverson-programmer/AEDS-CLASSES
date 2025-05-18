// Peça ao usuário que insira uma palavra ou frase. Utilize vetores para armazenar a palavra ou
// frase. Verifique se a palavra ou frase é um palíndromo (ou seja, se pode ser lida da mesma
// forma de trás para frente e vice-versa). Imprima se a palavra ou frase é um palíndromo ou
// não.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void palindromo(char str[]);

int main(){

    char str[256];

    printf("Digite uma palavra: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    palindromo(str);

    return 0;
}

void palindromo(char str[]){

    int length = strlen(str);
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == str[length - 1 - i]){
            count++;
        }
    }

    if(count == length){
        printf("É palindromo");
    }else{
        printf("Não é palindromo");
    }
}