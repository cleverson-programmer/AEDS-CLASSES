#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int dia, mes, ano;
} Pessoa;

int compararData(Pessoa p1, Pessoa p2) {
    if (p1.ano != p2.ano)
        return p1.ano - p2.ano;
    if (p1.mes != p2.mes)
        return p1.mes - p2.mes;
    return p1.dia - p2.dia;
}

void salvarEmArquivo(Pessoa maisNova, Pessoa maisVelha, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Pessoa mais nova: %s (%02d/%02d/%04d)\n", maisNova.nome, maisNova.dia, maisNova.mes, maisNova.ano);
    fprintf(arquivo, "Pessoa mais velha: %s (%02d/%02d/%04d)\n", maisVelha.nome, maisVelha.dia, maisVelha.mes, maisVelha.ano);
    
    fclose(arquivo);
    printf("Dados salvos em '%s'.\n", nomeArquivo);
}

void visualizarArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado.\n");
        return;
    }

    char linha[100];
    printf("\nConteúdo do arquivo:\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
}

int main() {
    Pessoa pessoas[6];
    Pessoa maisNova, maisVelha;
    char opcao;
    const char *arquivo = "dados.txt";

    printf("Digite os dados de 6 pessoas:\n");
    for (int i = 0; i < 6; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: ");
        getchar(); // Limpa o buffer
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0'; // Remove \n

        printf("Data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &pessoas[i].dia, &pessoas[i].mes, &pessoas[i].ano);
    }

    maisNova = maisVelha = pessoas[0];

    for (int i = 1; i < 6; i++) {
        if (compararData(pessoas[i], maisNova) > 0) {
            maisNova = pessoas[i];
        }
        if (compararData(pessoas[i], maisVelha) < 0) {
            maisVelha = pessoas[i];
        }
    }

    salvarEmArquivo(maisNova, maisVelha, arquivo);

    printf("\nDeseja visualizar o conteúdo do arquivo? (s/n): ");
    scanf(" %c", &opcao);

    if (opcao == 's' || opcao == 'S') {
        visualizarArquivo(arquivo);
    }

    return 0;
}
