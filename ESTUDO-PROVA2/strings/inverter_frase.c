#include <stdio.h>
#include <string.h>

void inverte_frase(char *str);

int main() {
    char str[256];

    printf("Digite um texto: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // remove o '\n' do final da string

    inverte_frase(str);

    return 0;
}

void inverte_frase(char *str) {
    char *palavras[50];  // Array de ponteiros para armazenar até 50 palavras
    int count = 0;

    // Divide a string em tokens
    char *token = strtok(str, " ");
    while (token != NULL && count < 50) {
        palavras[count++] = token;
        token = strtok(NULL, " ");
    }

    // Imprime as palavras na ordem inversa
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", palavras[i]);
        printf(" ");
    }

    printf("\n");
}