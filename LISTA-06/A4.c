#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define MAX_LINHA 1024

// Struct para armazenar estatísticas de uma espécie
typedef struct {
    char nome[20];
    int contagem;
    double soma[4];
    double minimo[4];
    double maximo[4];
} Estatisticas;

void inicializarEstatisticas(Estatisticas *e, const char *nome) {
    strcpy(e->nome, nome);
    e->contagem = 0;
    for (int i = 0; i < 4; i++) {
        e->soma[i] = 0.0;
        e->minimo[i] = DBL_MAX;
        e->maximo[i] = DBL_MIN;
    }
}

void atualizarEstatisticas(Estatisticas *e, double valores[4]) {
    e->contagem++;
    for (int i = 0; i < 4; i++) {
        e->soma[i] += valores[i];
        if (valores[i] < e->minimo[i]) e->minimo[i] = valores[i];
        if (valores[i] > e->maximo[i]) e->maximo[i] = valores[i];
    }
}

void salvarEstatisticas(Estatisticas *e, const char *arquivoNome) {
    FILE *f = fopen(arquivoNome, "w");
    if (f == NULL) {
        printf("Erro ao criar arquivo %s\n", arquivoNome);
        return;
    }

    fprintf(f, "Estatísticas para %s\n", e->nome);
    fprintf(f, "Atributo\tMínimo\tMáximo\tMédia\n");
    const char *atributos[] = {"Sepala Comprimento", "Sepala Largura", "Petala Comprimento", "Petala Largura"};
    for (int i = 0; i < 4; i++) {
        double media = e->soma[i] / e->contagem;
        fprintf(f, "%s\t%.2lf\t%.2lf\t%.2lf\n", atributos[i], e->minimo[i], e->maximo[i], media);
    }

    fclose(f);
}

void processarArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nomeArquivo);
        return;
    }

    Estatisticas setosa, versicolor, virginica;
    inicializarEstatisticas(&setosa, "setosa");
    inicializarEstatisticas(&versicolor, "versicolor");
    inicializarEstatisticas(&virginica, "virginica");

    char linha[MAX_LINHA];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        linha[strcspn(linha, "\r\n")] = 0;

        char *token = strtok(linha, ",");
        double valores[4];
        int i = 0;
        while (token != NULL && i < 4) {
            valores[i++] = atof(token);
            token = strtok(NULL, ",");
        }
        if (i != 4 || token == NULL) continue;

        char *especie = token;

        if (strcmp(especie, "setosa") == 0) {
            atualizarEstatisticas(&setosa, valores);
        } else if (strcmp(especie, "versicolor") == 0) {
            atualizarEstatisticas(&versicolor, valores);
        } else if (strcmp(especie, "virginica") == 0) {
            atualizarEstatisticas(&virginica, valores);
        }
    }

    fclose(arquivo);

    salvarEstatisticas(&setosa, "setosa_dados.txt");
    salvarEstatisticas(&versicolor, "versicolor_dados.txt");
    salvarEstatisticas(&virginica, "virginica_dados.txt");

    printf("Resumo estatístico gerado com sucesso!\n");
}

int main() {
    char nomeArquivo[100];

    printf("Digite o nome do arquivo (ex: iris.csv): ");
    scanf("%99s", nomeArquivo);

    processarArquivo(nomeArquivo);

    return 0;
}