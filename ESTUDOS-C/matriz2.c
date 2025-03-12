#include<stdio.h>
#include<stdlib.h>


int main(){

  int n1,n2,n3,n4, n5, n6;
  printf("Digite o 1 valor:\n");
  scanf("%d", &n1);
  printf("Digite o 2 valor:\n");
  scanf("%d", &n2);
  printf("Digite o 3 valor:\n");
  scanf("%d", &n3);
  printf("Digite o 4 valor:\n");
  scanf("%d", &n4);
  printf("Digite o 5 valor:\n");
  scanf("%d", &n5);
  printf("Digite o 6 valor:\n");
  scanf("%d", &n6);
  
  int matriz[2][3] = {
    {n1, n2, n3},
    {n4, n5,n6 }
  };

  // Vetores para armazenar as somas das linhas e colunas
  int soma_linhas[2] = {0, 0};
  int soma_colunas[3] = {0, 0};

  // Percorrendo a matriz para imprimir e calcular as somas
  for (int i = 0; i < 2; i++) { // For que percorre a linha
      for (int j = 0; j < 3; j++) { // For que percorre a coluna
          printf("%d ", matriz[i][j]);
          soma_linhas[i] += matriz[i][j]; // Soma os elementos da linha i
          soma_colunas[j] += matriz[i][j]; // Soma os elementos da coluna j
      }
      printf("\n");
  }

  // Imprimindo as somas das linhas
  printf("Soma das linhas:\n");
  for (int i = 0; i < 2; i++) {
      printf("Linha %d: %d\n", i + 1, soma_linhas[i]);
  }

  // Imprimindo as somas das colunas
  printf("Soma das colunas:\n");
  for (int j = 0; j < 3; j++) {
      printf("Coluna %d: %d\n", j + 1, soma_colunas[j]);
  }

  return 0;
}