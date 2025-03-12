#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declarando uma diretiva de pré-processador, é uma constante simbólica como se fosse as variáveis do .ENV em JS, na hora da compilação, substitui a constante pelo valor dela.
#define MAX 3

//Struct que vamos aninhar
struct Endereco {
  char rua[50];
  char cidade[50];
  int numero;
};

//Aninhamento de structs (usando typedef para abordagem de alias)
typedef struct {
  char nome[50];
  int idade;
  struct Endereco endereco; //Criando uma variável do tipo struct endereço dentro de uma struct (aninhamento)
} Cliente;

//Struct com ponteiros, para acessar os membros da struct usa "->"
struct Produtos {
  char nome[50];
  int qntd;
  float preco;
};

//Vetores de struct, podemos armazenar multiplos registros em um vetor de structs
typedef struct {
  char nome[50];
  float preco;
} Frutas;


int struct2(){

  //Declarando uma variavel do tipo struct Cliente que contém outra struct aninhada
  Cliente usuario = {"Paulo", 45, {"Rua Maranhão", "Ibirité", 729}};
  printf("Nome: %s\nIdade: %d\n", usuario.nome, usuario.idade);
  printf("\nDados de Endereço:\nRua: %s\nNúmero: %d\nCidade: %s\n", usuario.endereco.rua, usuario.endereco.numero, usuario.endereco.cidade);

  printf("\n\n--------------------------------------------------------\n\n");
  
  //Declarando uma variável do tipo struct Produtos
  struct Produtos notebook = {
    .nome = {"Notebook Dell"},
    .qntd = 20,
    .preco = 4.985
  };

  struct Produtos *ptr = &notebook;

  //Acessando via ponteiro usando ->
  printf("Nome: %s\n", ptr->nome);
  printf("Quantidade: %d\n", ptr->qntd);
  printf("Preço: %.3f\n", ptr->preco);

  printf("\n\n--------------------------------------------------------\n\n");
  
  //Criando um vetor de structs de exibindo na tela
  Frutas sacolao[MAX] = {
    {"Maça", 6},
    {"Banana", 5},
    {"Pera", 10}
  };

  //Exibindo os dados com um looping
  for(int i = 0; i < MAX; i++) {
    printf("Fruta: %s, Preço: %.2fR$\n", sacolao[i].nome, sacolao[i].preco);
  }
}