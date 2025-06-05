#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct que representa uma linha do CSV
typedef struct {
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
    char species[50];
} Iris;

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

    char linha[1024];
    while (fgets(linha, sizeof(linha), entrada)) {
        Iris iris;

        // Divide a linha por vírgulas e preenche a struct
        sscanf(linha, "%f,%f,%f,%f,%49[^\n]", 
            &iris.sepal_length,
            &iris.sepal_width,
            &iris.petal_length,
            &iris.petal_width,
            iris.species);

        // Escreve a struct inteira no arquivo binário
        fwrite(&iris, sizeof(Iris), 1, saida);
    }

    printf("Arquivo binário '%s' criado com sucesso.\n", nomeBIN);

    fclose(entrada);
    fclose(saida);
}

int main() {
    copiarParaBinario("iris.csv", "iris.bin");
    return 0;
}
