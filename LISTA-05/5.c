// Crie uma função que recebe um vetor de caracter por parâmetro que representa um endereço
// de e-mail para validar se o e-mail é válido. A função deverá retornar a posição do símbolo ‘@’. Se
// o símbolo não estiver presente, então a função deverá retornar –1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar(char email[]);

int main(){
    char email[256];
    int tamanho = sizeof(email) / sizeof(email[0]);

    printf("Digite um endereço de email: ");
    fgets(email, sizeof(email), stdin);

    email[strcspn(email, "\n")] = '\0';

    int resultado = validar(email);

    if(resultado != -1){
        printf("Simbolo na posição: %d", resultado);
    }else{
        printf("Simbolo não encontrado");
    }

    return 0;
}

int validar(char email[]){
    //Garante que vamos percorrer apenas os caracteres que fazem parte da string digitada
    for(int i = 0; email[i] != '\0'; i++){
        if(email[i] == '@'){
            return i;
        }
    }

    return -1;
}