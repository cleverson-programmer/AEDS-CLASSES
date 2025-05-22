// Crie um programa que receba um texto do usuário e grave o texto em um arquivo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *arquivo;
    char texto[50];

    //lEITURA DOS DADOS
    printf("Digite um texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';

    //abrindo arquivo
    arquivo = fopen("texto.bin", "wb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    // Escrevendo o texto no arquivo binário

    // fwrite(ponteiro para aonde os dados estão, tamanho em bytes de cada elemento a ser escrito, número de elementos a serem escritos, ponteiro para o arquivo abertp com fopen)
    // fwrite() retorna o número de elementos gravados com sucesso, podemos pegar o retorno e exibir se gravou com sucesso ou não
    // BOA PRÁTICA É SEMPRE VERIFICAR O VALOR RETORNADO

    size_t resultado = fwrite(texto, sizeof(char), strlen(texto), arquivo);
    if (resultado != strlen(texto)) {
        printf("Erro ao gravar os dados.\n");
    }
    fclose(arquivo);

    // Leitura do arquivo binário
    arquivo = fopen("texto.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    //Precisa sempre criar uma variavel para armazenar os dados lidos!!!
    char textoLido[50]; // buffer para armazenar os dados lidos

    //OPCIONAL ESSA LINHA ABAIXO
    memset(textoLido, 0, sizeof(textoLido)); // garante que esteja limpo

    // fread(ponteiro para onde os dados vão ser armazenados, tamanho em bytes de cada elemento a ser lido no caso um caractere, numero de elementos a serem lidos que neste caso é o tamanho do texto sizeof(texto) - 1 que é porque o vetor de string termina com /0 sempre, ponteiro para o arquivo que foi aberto para ser lido com fopen)
    fread(textoLido, sizeof(char), sizeof(textoLido) - 1, arquivo);
    fclose(arquivo);

    printf("\nTexto lido do arquivo: %s\n", textoLido);

    return 0;
}