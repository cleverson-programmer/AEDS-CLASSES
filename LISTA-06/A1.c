#include <stdio.h>
#include <stdlib.h>

void contarLinhas(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'. Verifique se o nome está correto.\n", nomeArquivo);
        return;
    }

    int contador = 0;
    char linha[1024];

    //fgets --> lê uma linha por vez da entrada padrão ou de um arquivo e armazena essa linha em um vetor de caracteres
    //Buffer aonde será armazenado, tamanho máximo que lê, ponteiro para o arquivo do qual pega os dados
    //Compara com diferente de NULL, pois fgets retorna o ponteiro da linha se conseguir ler a linha
    //ou retorna NULL caso chegue no final do arquivo.
    //OU SEJA: Enquanto conseguir ler uma nova linha do arquivo, continue...
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }

    fclose(arquivo);

    printf("O arquivo '%s' possui %d linha(s).\n", nomeArquivo, contador);
}

int main() {
    char nomeArquivo[100];

    printf("Digite o nome do arquivo com a extensão: ");
    scanf("%99s", nomeArquivo);

    contarLinhas(nomeArquivo);

    return 0;
}