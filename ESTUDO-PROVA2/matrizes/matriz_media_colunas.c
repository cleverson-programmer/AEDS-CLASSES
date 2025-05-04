#include <stdio.h>
#include <locale.h>

void media(int matriz[3][4]);

int main(){
    int matriz[3][4];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("Digite o valor da matriz na posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    media(matriz);

    return 0;
}

void media(int matriz[3][4]){
    float vetor[4];

    printf("SOMA\n");
    for(int i = 0; i < 4; i++){
        int soma = 0;
        float media = 0;
        for(int j = 0; j < 3; j++){
            soma += matriz[j][i];
            media = soma / 3;
            vetor[i] = media;
        }

        printf("%d\n", media);
    }


}