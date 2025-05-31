#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiarParaBinario(const char *nomeCSV, const char *nomeBIN) {
    FILE *entrada = fopen(nomeCSV, "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo texto: %s\n", nomeCSV);
        return;
    }

    FILE *saida = fopen(nomeBIN, "wb");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo binário: %s\n", nomeBIN);
        fclose(entrada);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), entrada)) {
        fwrite(buffer, sizeof(char), strlen(buffer), saida);
    }

    printf("Arquivo binário '%s' criado com sucesso.\n", nomeBIN);

    fclose(entrada);
    fclose(saida);
}

int main() {
    copiarParaBinario("iris.csv", "iris.bin");
    return 0;
}
