#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Verificar palíndromo
// Faça uma função que diga se uma string é um palíndromo (ex: "ana", "radar").

//Protótipo da função
int palindromo(char *str);

int main(){
    char word[20];
    printf("Digite uma palavra:");
    fgets(word, sizeof(word), stdin);

    //Sem essa linha para tirar a quebra de linha '\n' do vetor não funciona!
    word[strcspn(word, "\n")] = '\0';

    //Se for exigido que seja iguais considerando tanto maiusculas quanto minusculas
    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }

    if(palindromo(word)){
        printf("É palindromo");
    }else{
        printf("Não é palindromo");
    }

    return 0;
}

int palindromo(char *str){
    int length = strlen(str);
    
    for(int i = 0; i < length; i++){
        if(str[i] != str[length - i - 1]){  // length - i --> para pegar de trás para frente. --> -1 para descontar o \0 que fica no final da string
            return 0;
        }
    }

    return 1;
    
}

//Outra forma de resolver:
void palindromo(char *str){
    int length = strlen(str);
    int count = 0;
    
    for(int i = 0; i < length; i++){
        if(str[i] == str[length - i - 1]){  // length - i --> para pegar de trás para frente. --> -1 para descontar o \0 que fica no final da string
            count++;
        }
    }

    if(count == length){
        printf("palindromo");
    }else{
        printf("Não é palindromo");
    }

}