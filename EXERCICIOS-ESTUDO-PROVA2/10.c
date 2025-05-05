#include <stdio.h>
#include <string.h>

// Remover todos os espaços em branco de uma string.

void removerEspacos(const char *entrada, char *saida) {
    int j = 0;
    for (int i = 0; i < strlen(entrada); i++) {
        if (entrada[i] != ' ')
            saida[j++] = entrada[i];
    }
    saida[j] = '\0';
}

int main() {
    char frase[100], limpa[100];
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    removerEspacos(frase, limpa);
    printf("Frase sem espaços: %s\n", limpa);
    return 0;
}
