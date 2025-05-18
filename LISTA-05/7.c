// Implemente a função abaixo, que receba como parâmetro uma string e converte,
// individualmente, cada caractere para maiúsculo. A função deverá retornar a string convertida
// para maiúsculo. A string a ser retornada deverá ser criada utilizando o comando malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função que converte string para maiúsculo usando malloc
char* converteParaMaiusculo(const char* str) {
    // Aloca memória para a nova string (+1 para o '\0')
    char* maiuscula = (char*) malloc((strlen(str) + 1) * sizeof(char));
    
    if (maiuscula == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    // Percorre a string original e converte cada caractere
    for (int i = 0; str[i] != '\0'; i++) {
        maiuscula[i] = toupper(str[i]);
    }

    // Adiciona o caractere nulo ao final da string
    maiuscula[strlen(str)] = '\0';

    return maiuscula;
}

int main() {
    char texto[100];

    printf("Digite uma frase: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';  // Remove o '\n' do final

    // Chama a função para converter
    char* resultado = converteParaMaiusculo(texto);

    // Exibe a string convertida
    printf("Texto em maiúsculas: %s\n", resultado);

    // Libera a memória alocada
    free(resultado);

    return 0;
}

