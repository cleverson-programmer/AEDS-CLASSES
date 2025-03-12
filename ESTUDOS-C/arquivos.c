#include <stdio.h>
#include <stdlib.h>

//Outras funções: fopen, fclose, fprintf, fscanf, fgets, fputc, fgetc.

int arquivos(){
  //FILE é um tipo de dado definido na lib <stdio.h> , funciona como um ponteiro para um bloco de controle de arquivo
  //Usamos o ponteiro pois um arquivo é um recurso externo(não está na memória principal do programa). O ponteiro armazena a referência ao arquivo aberto, permitindo que o programa interaja com ele
  //"w" é o modo de abertura, cria um novo arquivo com esse nome ou sobrescreve um existente
  FILE *arquivo = fopen("dados.txt", "w");
    if(arquivo == NULL){
      printf("Erro ao abrir arquivo");
      return 1;
    }

  fprintf(arquivo, "Nome:João\nIdade:30");
  fclose(arquivo);

  printf("Dados salvos com sucesso\n");

  //Lendo um arquivo

  FILE *arquivo2 = fopen("dados.txt", "r");  // Abre para leitura
  char linha[100];

  if (arquivo2 == NULL) {
      printf("Erro ao abrir o arquivo!\n");
      return 1;
  }

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {  // Lê linha por linha
      printf("%s", linha);
  }

  fclose(arquivo);

  return 0;
}