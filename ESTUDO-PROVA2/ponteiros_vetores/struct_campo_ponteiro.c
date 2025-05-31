// //Crie uma struct chamada Produto com os seguintes campos:
// nome (string), preco (float), quantidade (int)

// Implemente uma função atualizarEstoque() que recebe um ponteiro para o campo quantidade e 
// atualiza o valor da quantidade com base em uma entrada do usuário (quantidade a ser adicionada ao estoque).
// No final, exiba o novo valor da quantidade.

#include <stdio.h>
#include <string.h>

//Atualizando CAMPOS DE UMA STRUCT por referencia com ponteiros
//Neste exercicio passa apenas o endereço de um campo de uma struct e não uma struct inteira
// TRABALHA COM : &produtos[i].qtd
// SE FOSSE PASSAR A INTEIRA: &produto->qtd
typedef struct{
    char nome[50];
    float preco;
    int id;
    int qtd;
} Produto;

void atualizarEstoque(int *qtd);

int main(){
    int n;
    char att;

    printf("Digite a quantidade de produtos a ser cadastrado: ");
    scanf("%d", &n);

    Produto produtos[n];

    for(int i = 0; i < n; i++){
        while((getchar() != '\n'));

        printf("Digite o nome do produto: ");
        fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

        printf("Digite o id do produto: ");
        scanf("%d", &produtos[i].id);

        printf("Digite o preço: ");
        scanf("%f", &produtos[i].preco);

        printf("Digite a quantidade: ");
        scanf("%d", &produtos[i].qtd);

    }

    printf("Deseja atualizar o estoque: (S/N):");
    scanf(" %c", &att);

    if(att == 's' || att == 'S'){
        int id;
        printf("Digite o id do produto: ");
        scanf("%d", &id);

        for(int i = 0; i < n; i++){
            if(produtos[i].id == id){
                atualizarEstoque(&produtos[i].qtd);
                printf("Nova quantidade:\n");
                printf("%s | %.2f | %d | %d \n", produtos[i].nome, produtos[i].preco, produtos[i].id, produtos[i].qtd);
            }
        }

    }else{
        return 0;
    }

    return 0;
}

void atualizarEstoque(int *qtd){
    int nova_qtd;
    printf("Digite a nova quantidade: ");
    scanf("%d", &nova_qtd);

    *qtd = nova_qtd;
}