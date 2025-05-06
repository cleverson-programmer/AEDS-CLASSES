// Faça uma struct Imagem que contenha uma matriz 3x3 de inteiros. Escreva uma função que inverta essa matriz (espelho horizontal).

#include <stdio.h>

typedef struct{
    int matriz[3][3];
} Imagem;

void espelho_horizontal(Imagem imagem);

int main(){

    Imagem imagem;
    
    for(int i = 0; i < 3; i++){
        printf("%d° linha\n", i + 1);
        for(int j = 0; j < 3; j++){
            printf("Digite o valor da posição: [%d][%d]", i, j);
            scanf("%d", &imagem.matriz[i][j]);
        }
        printf("\n");
    }

    espelho_horizontal(imagem);

    return 0;
}

void espelho_horizontal(Imagem imagem){

    int matrizE[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrizE[i][j] = imagem.matriz[i][2- j];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matrizE[i][j]);
        }
        printf("\n");
    }
}

