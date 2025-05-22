// Crie uma struct Produto com os campos nome (até 30 caracteres) e preco (float). 
// Permita que o usuário cadastre produtos até desejar parar. 
// Use realloc para aumentar o vetor conforme necessário. Exiba os produtos e libere a memória.

#include <stdio.h>      // Inclusão da biblioteca padrão para entrada e saída
#include <stdlib.h>     // Inclusão da biblioteca para alocação dinâmica de memória
#include <string.h>     // Inclusão da biblioteca para manipulação de strings
#include <ctype.h>      // Inclusão da biblioteca para manipulação de caracteres

// Definição da struct Produto com nome (string de até 30 caracteres) e preco (float)
typedef struct {
    char nome[30];
    float preco;
} Produto;

int main(){
    Produto *produtos = NULL; // Ponteiro para vetor de produtos, inicialmente vazio
    int qtd = 0;              // Contador de produtos cadastrados
    char continuar;           // Variável para controlar se o usuário quer continuar

    do{
        // Realoca memória para armazenar mais um produto
        Produto *temp = (Produto *) realloc(produtos, (qtd + 1) * sizeof(Produto));
        if(temp == NULL){ // Verifica se a realocação falhou
            printf("Erro de alocação de memória");
            return 1; // Encerra o programa em caso de erro
        }

        produtos = temp; // Atualiza o ponteiro original com o novo endereço de memória

        // Leitura dos dados do novo produto
        printf("Produto %d\n", qtd + 1);
        getchar(); // Limpa o buffer do teclado (remove '\n' da entrada anterior)

        printf("Nome: ");
        // Lê o nome do produto com segurança, evitando estouro de buffer
        fgets(produtos[qtd].nome, sizeof(produtos[qtd].nome), stdin);
        // Remove o caractere '\n' lido pelo fgets, se presente
        produtos[qtd].nome[strcspn(produtos[qtd].nome, "\n")] = '\0';

        printf("Preço: ");
        // Lê o preço do produto
        scanf("%f", &produtos[qtd].preco);

        qtd++; // Incrementa a quantidade total de produtos cadastrados

        getchar(); // Limpa o buffer antes de ler o próximo caractere
        printf("Deseja adicionar outro produto? (s/n): ");
        scanf("%c", &continuar); // Lê a resposta do usuário

    }while(continuar == 's'); // Continua se o usuário digitar 's'

    // Exibição dos produtos cadastrados
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Produto: %s - Preço: R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    }

    free(produtos); // Libera a memória alocada dinamicamente

    return 0; // Encerra o programa
}
