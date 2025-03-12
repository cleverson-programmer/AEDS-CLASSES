#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declarando uma struct da forma comum
struct Pessoa {
  char nome[50];
  int idade;
  float altura;
};

//Podemos declarar uma struct usando o "typedef" para que quando for iniciar uma variável com a struct não precise usar "struct Pessoa <variavel>" e apenas "Pessoa <variavel>".
typedef struct {
  char modelo[50];
  int ano;
  float kms;
} Carro;

int struct1(){
  //Declarando uma variável do tipo struct Pessoa
  struct Pessoa pessoa1;

  //Iniciando uma struct na própria declaração
  struct Pessoa pessoa2 = {"Bia", 26, 1.54};
  
  //Iniciando struct na própria declaração porém em bloco
  struct Pessoa pessoa3 = {
    .nome = {"Mateus"},
    .idade = 40,
    .altura = 1.85
  };

  //Iniciando variavel diretamente como Carro pois usamos o "typedef" na criação dessa struct
  Carro honda = {"Honda Civic", 2025, 10.000};
  printf("Dados do veículo:\nModelo: %s\nAno: %d\nKM: %.2f\n", honda.modelo, honda.ano, honda.kms);

  printf("\n\n--------------------------------------------------------\n\n");
  
  //Atribuindo valores aos membros da struct
  strcpy(pessoa1.nome, "João"); //Usamos a fn strcpy da lib <string.h> pois ela é usada para copiar/inserir textos (palavras com espaço) em vetores.
  pessoa1.idade = 30;
  pessoa1.altura = 1.76;

  // Exibindo os valores
  printf("Dados da pessoa:\n");
  printf("Nome: %s\n", pessoa1.nome);
  printf("Idade: %d\n", pessoa1.idade);
  printf("Altura: %.2f\n", pessoa1.altura);

 return 0; 
}