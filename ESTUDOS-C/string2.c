#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char nome[100];

    // Captura a string do usuário
    printf("Digite seu nome: ");

    //fgets usado para ler uma linha de entrada do usuário e armazena-lo em uma string
    //Pode ser feito também com o scanf mas com o fgets é mais seguro pois evita o buffer

    //destino --> array aonde a string será armazenada
    //tamanho --> sizeof pega o tamanho máximo da string que pode ser lida neste caso 99 pois sempre faz o valor total de caracteres do vetor menos 1, pois tem que sobrar o espaço para o \0 que indica o final da string, ou então lê até encontrar o \n

    //stdin --> standart input, entrada padrão do programa, normalmente o teclado.
    
    //Estrutura: fgets(destino, tamanho, origem);
    fgets(nome, sizeof(nome), stdin);

    // Remover o '\n' que o fgets adiciona
    //fgets sempre adiciona o \n no final então removemos e colocamos o \0 para indicar o fim do vetor de string
    nome[strcspn(nome, "\n")] = '\0';

    // Exibir a string digitada
    printf("Nome digitado: %s\n", nome);

    // Contar o número de caracteres
    printf("Quantidade de caracteres: %ld\n", strlen(nome));

    // Converter para maiúsculas
    for(int i = 0; nome[i] != '\0'; i++) { 
        nome[i] = toupper(nome[i]);
    }

    printf("Nome em maiúsculas: %s\n", nome);

    return 0;
}