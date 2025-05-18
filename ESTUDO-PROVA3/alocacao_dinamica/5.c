// Crie uma struct Produto com os campos nome (até 30 caracteres) e preco (float). 
// Permita que o usuário cadastre produtos até desejar parar. 
// Use realloc para aumentar o vetor conforme necessário. Exiba os produtos e libere a memória.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    char nome[30];
    float preco;
} Produto;

int main(){
    Produto *produtos = NULL;
    int qtd = 0;
    char continuar;

    do{
        //Realocar memoria para ponteiro de vetor de produtos
        Produto *temp = (Produto *) realloc(produtos, (qtd + 1) * sizeof(Produto));
        if(temp == NULL){
            printf("Erro de alocação de memória");
            return 1;
        }

        produtos = temp;

        //Leitura do novo produto;
        printf("Produto %d\n", qtd + 1);
        getchar();
        printf("Nome: ");
        fgets(produtos[qtd].nome, sizeof(produtos[qtd].nome), stdin);
        produtos[qtd].nome[strcspn(produtos[qtd].nome, "\n")] = '\0';

        printf("Preço: ");
        scanf("%f", &produtos[qtd].preco);

        qtd++;
        getchar();
        printf("Deseja adicionar outro produto? (s/n): ");
        scanf("%c", &continuar);

    }while(continuar == 's');

    // Exibe os produtos
    printf("\nLista de Produtos:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Produto: %s - Preço: R$ %.2f\n", produtos[i].nome, produtos[i].preco);
    }

    free(produtos);
    return 0;
}

