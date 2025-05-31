#include <stdio.h>
#include <string.h>

// Procedimento que remove espaços de uma string usando strtok
void removeEspacos(char *str) {
    char resultado[100] = "";
    char *token = strtok(str, " ");

    while (token != NULL) {
        strcat(resultado, token); // concatena as palavras sem espaços
        token = strtok(NULL, " ");
    }

    strcpy(str, resultado); // copia o resultado de volta para a string original
}

int main() {
    char texto[100];

    printf("Digite uma string: ");
    fgets(texto, sizeof(texto), stdin);

    // Remove o caractere de nova linha '\n' se presente
    texto[strcspn(texto, "\n")] = '\0';

    removeEspacos(texto);

    printf("String sem espaços: %s\n", texto);

    return 0;
}
