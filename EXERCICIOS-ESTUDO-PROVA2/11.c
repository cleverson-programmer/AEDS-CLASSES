#include <stdio.h>

// Crie uma função que receba uma matriz 4x4 de inteiros e retorne a soma da diagonal principal.

int  soma_diagonal(int matriz[4][4]);
int soma_diagonalInvertida(int matriz[4][4]);

int main(){

    int matriz[4][4];

    for(int i = 0; i < 4; i++){
        printf("%d° linha\n", i + 1);
        for(int j = 0; j < 4; j++){
            printf("Digite o valor da posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }

    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("A soma da diagonal é: %d", soma_diagonal(matriz));
    printf("\nA soma da diagonal invertida é: %d", soma_diagonalInvertida(matriz));
    return 0;
}

int soma_diagonal(int matriz[4][4]){
    int soma = 0;
    //Diagonal principal
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j){
                soma += matriz[i][j];
            }
        }
    }

    return soma;
}

int soma_diagonalInvertida(int matriz[4][4]){
    //Diagonal invertida
    int soma = 0;
    int n = 4;
    for(int i = 0; i < 4; i++){
       soma += matriz[i][n - i - 1];    //Numero de colunas menos a posição atual percorrida pela linha, -1 que é por conta do indice que começa em 0
    }

    return soma;
}