#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int string(){
  //Declarando um vetor com caracteres fixos
  char nome[10] = "João";

  //Vetor sem quantidade fixa de caracteres
  char funcionarios[] = "Maria";

  //Usando ponteiro para apontar para um espaço da memória contendo a string
  char *sobrenome = "Silva";

  //Usando scanf()
  char name[20];

  printf("Digite seu nome:\n");
  scanf("%s", name);
  printf("Ola %s", name);

  //Usando fgets() (Lê dados de string com espaço)
  char rua[50];
  printf("Digite uma rua:\n");
  //stdin indica que a váriavel virá da entrada padrão(teclado)
  fgets(rua, sizeof(rua), stdin);
  printf("A rua é %s:", rua);

  //Funções de manipulação de strings usa a lib <string.h>

  //fn strlen() --> Obtém o tamanho da string
  char palavra[] = "Computador";
  //%lu --> número inteiro positivo sem sinal long unsigned
  printf("A palavra tem %lu caracteres\n", strlen(palavra));

  //fn strcpy() copiando string
  char destino[20];
  strcpy(destino, "Ceara");
  printf("A palavra copiada foi:\n%s", destino);

  // fn strcat() --> concatenando strings

  char cidade[50] = "Ibirite,";
  char bairro[] = " Ouro negro";

  strcat(cidade, bairro);
  printf("Endereço:\n%s", cidade);

  //strcmp() --> comparando strings, retorna 0 se as strings forem iguais, 
  //positivo se a primeira for maior que segunda e negativo se a primeira for menor que a segunda
  char s1[] = "PC";
  char s2[] = "PC";
  
  if(strcmp(s1, s2) == 0){
    printf("Strings são iguais");
  }

  //Percorrendo strings
  char substantivo[] = "Parque";

  for(int i = 0; substantivo[i] != '\0'; i++){
    printf("Letra %c na posição %d\n", substantivo[i], i);
  }
  
  //Conversão de tipo: atoi() --> string para inteiro sprintf() --> inteiro para string
  char numeroTexto[] = "123";
  int numero = atoi(numeroTexto);
  printf("String em número: %d\n", numero);

  char buffer[10];
  sprintf(buffer, "%d", 456);
  printf("Número em string: %s\n", buffer);
}