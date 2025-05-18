// Solicite ao usuário que insira uma frase e duas palavras: uma palavra a ser buscada na frase e
// outra palavra para substituir a palavra encontrada. Utilize vetores para armazenar a frase e
// as palavras. Busque a palavra na frase e substitua todas as ocorrências pela segunda palavra.
// Imprima a frase resultante após a substituição.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void substituir_palavra(const char *frase, const char *palavra_antiga, const char *palavra_nova);

int main() {
    char frase[256];
    char palavra1[32], palavra2[32];

    // Frase
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    // Palavra a ser substituída
    printf("Digite a palavra que deseja substituir: ");
    fgets(palavra1, sizeof(palavra1), stdin);
    palavra1[strcspn(palavra1, "\n")] = '\0';

    // Palavra substituta
    printf("Digite a nova palavra: ");
    fgets(palavra2, sizeof(palavra2), stdin);
    palavra2[strcspn(palavra2, "\n")] = '\0';

    substituir_palavra(frase, palavra1, palavra2);

    return 0;
}

void substituir_palavra(const char *frase, const char *palavra_antiga, const char *palavra_nova) {
    char nova_frase[512];  // buffer para a nova frase
    nova_frase[0] = '\0';  // inicia a string como vazia

    const char *ptr = frase;
    const char *encontrada;

    size_t len_antiga = strlen(palavra_antiga);

    while ((encontrada = strstr(ptr, palavra_antiga)) != NULL) {
        // Copia o trecho antes da palavra encontrada
        strncat(nova_frase, ptr, encontrada - ptr);
        // Adiciona a nova palavra
        strcat(nova_frase, palavra_nova);
        // Avança o ponteiro após a palavra encontrada
        ptr = encontrada + len_antiga;
    }

    // Copia o restante da frase
    strcat(nova_frase, ptr);

    printf("\nFrase resultante:\n%s\n", nova_frase);
}
