#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 1024
#define MAX_ESPECIES 100

// Struct para armazenar o nome da espécie e quantidade
typedef struct {
    char especie[50];
    int quantidade;
} EspecieContador;

// Função que conta amostras por espécie
void contarAmostrasPorEspecie(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nomeArquivo);
        return;
    }

    char linha[MAX_LINHA];
    EspecieContador especies[MAX_ESPECIES];
    int totalEspecies = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Remove quebra de linha se existir
        linha[strcspn(linha, "\r\n")] = 0;

        // Divide a linha por vírgulas
        char *token = strtok(linha, ",");
        char *ultimaColuna = NULL;

        // Pega o último token (que contém a espécie)
        while (token != NULL) {
            ultimaColuna = token;
            token = strtok(NULL, ",");
        }

        if (ultimaColuna == NULL) continue;

        // Verifica se espécie já foi contada
        int encontrada = 0;
        for (int i = 0; i < totalEspecies; i++) {
            if (strcmp(especies[i].especie, ultimaColuna) == 0) {
                especies[i].quantidade++;
                encontrada = 1;
                break;
            }
        }

        if (!encontrada && totalEspecies < MAX_ESPECIES) {
            strcpy(especies[totalEspecies].especie, ultimaColuna);
            especies[totalEspecies].quantidade = 1;
            totalEspecies++;
        }
    }

    fclose(arquivo);

    // Exibe o resultado
    printf("\nQuantidade de amostras por espécie:\n");
    for (int i = 0; i < totalEspecies; i++) {
        printf("- %s: %d amostra(s)\n", especies[i].especie, especies[i].quantidade);
    }
}

int main() {
    char nomeArquivo[100];

    printf("Digite o nome do arquivo: ");
    scanf("%99s", nomeArquivo);

    contarAmostrasPorEspecie(nomeArquivo);

    return 0;
}