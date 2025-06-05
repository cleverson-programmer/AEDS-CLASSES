#include <stdio.h>

typedef struct {
    float media;
    int matriz[3][3];
} Imagem;

void espelho_horizontal(Imagem *imagem);

int main() {
    Imagem imagem;

    printf("Digite os valores da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Posição [%d][%d]: ", i, j);
            scanf("%d", &imagem.matriz[i][j]);
        }
    }

    espelho_horizontal(&imagem);

    return 0;
}

void espelho_horizontal(Imagem *imagem) {
    int matrizEspelhada[3][3];
    int soma = 0;

    // Espelhamento horizontal e soma dos elementos
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrizEspelhada[i][j] = imagem->matriz[i][2 - j];
            soma += imagem->matriz[i][j];
        }
    }

    imagem->media = soma / 9.0;

    printf("\nMatriz espelhada horizontalmente:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrizEspelhada[i][j]);
        }
        printf("\n");
    }

    printf("\nMédia dos elementos: %.2f\n", imagem->media);
}
