#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_words(char *text){
    int count = 0;
    //strtok --> divide a string em partes com base em delimitadores, nesse caso estamos pegando os espaços em branco
    //Estamos atribuindo a outra váriavel porque essa função modifica a string original.
    //Divide em tokens onde cada trecho quando encontra o delimitador coloca o \0 delimitando fim da string
    char *token = strtok(text, " ");

    //Percorre a string ate achar o primeiro delimitador e guarda o trecho de string e adiciona o \0
    //A função strtok retorna null quando NÃO tem mais token
    //Se token for diferente de null nos incrementamos pois ainda tem palavras
    //token = strtok(NULL, " "); --> Passa NULL para não começar uma nova string, a fn sabe aonde parou por conta do \0
    //e por isso ela vai vai pegar o próximo token que é o restante da string ate o delimitador, neste caso o espaço.
    //Dessa forma o loop continua ate não ter mais tokens que são os trechos da string que foram delimitados.
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

int main(){

    char text[256];
    printf("Digite um texto:");
    fgets(text, sizeof(text), stdin);

    int result = count_words(text);
    printf("Quant. palavras: %d", result);
    return 0;
}