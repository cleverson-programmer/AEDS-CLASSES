#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRAS 100
#define TAM_MAX_TEXTO 1000
#define TAM_MAX_PALAVRA 50

// Estrutura para armazenar uma palavra e sua contagem
typedef struct {
    char palavra[TAM_MAX_PALAVRA];
    int contagem;
} PalavraContagem;

// Função para converter string para minúsculas (opcional)
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Procedimento para contar palavras repetidas
void contarPalavrasRepetidas(char *texto) {
    PalavraContagem palavras[MAX_PALAVRAS];
    int total = 0;

    char *token = strtok(texto, " \n\t.,!?;:"); // separadores
    while (token != NULL) {
        toLowerCase(token);  // remover se não quiser case-insensitive

        int encontrada = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(palavras[i].palavra, token) == 0) {
                palavras[i].contagem++;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada && total < MAX_PALAVRAS) {
            strcpy(palavras[total].palavra, token);
            palavras[total].contagem = 1;
            total++;
        }

        token = strtok(NULL, " \n\t.,!?;:");
    }

    printf("\nPalavras repetidas e suas contagens:\n");
    for (int i = 0; i < total; i++) {
        if (palavras[i].contagem > 1) {
            printf("%s: %d vezes\n", palavras[i].palavra, palavras[i].contagem);
        }
    }
}

int main() {
    char texto[TAM_MAX_TEXTO];

    printf("Digite um texto:\n");
    fgets(texto, TAM_MAX_TEXTO, stdin);

    contarPalavrasRepetidas(texto);

    return 0;
}
