#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 1024

void separarPorEspecie(const char *nomeArquivo) {
    FILE *entrada = fopen(nomeArquivo, "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nomeArquivo);
        return;
    }

    FILE *setosa = fopen("setosa.csv", "w");
    FILE *versicolor = fopen("versicolor.csv", "w");
    FILE *virginica = fopen("virginica.csv", "w");

    if (!setosa || !versicolor || !virginica) {
        printf("Erro ao criar arquivos de saída.\n");
        fclose(entrada);
        return;
    }

    char linha[MAX_LINHA];

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        // Remove quebra de linha se existir
        linha[strcspn(linha, "\r\n")] = 0;

        // Copia da linha para tokenização
        char linhaCopia[MAX_LINHA];
        strcpy(linhaCopia, linha);

        // Pega o último token (espécie)
        char *token = strtok(linhaCopia, ",");
        char *ultimaColuna = NULL;
        while (token != NULL) {
            ultimaColuna = token;
            token = strtok(NULL, ",");
        }

        if (ultimaColuna == NULL) continue;

        // Escreve a linha no arquivo correspondente
        if (strcmp(ultimaColuna, "setosa") == 0) {
            fprintf(setosa, "%s\n", linha);
        } else if (strcmp(ultimaColuna, "versicolor") == 0) {
            fprintf(versicolor, "%s\n", linha);
        } else if (strcmp(ultimaColuna, "virginica") == 0) {
            fprintf(virginica, "%s\n", linha);
        }
    }

    // Fecha todos os arquivos
    fclose(entrada);
    fclose(setosa);
    fclose(versicolor);
    fclose(virginica);

    printf("Separação concluída com sucesso.\n");
}

int main() {
    char nomeArquivo[100];

    printf("Digite o nome do arquivo (ex: iris.csv): ");
    scanf("%99s", nomeArquivo);

    separarPorEspecie(nomeArquivo);

    return 0;
}